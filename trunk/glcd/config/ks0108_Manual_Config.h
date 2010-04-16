/*
 * ks0108_Manual_Config.h - User specific configuration for Arduino GLCD library
 *
 * Use this file to set io pins and LCD panel parameters
 * This version is for a standard ks0108 display
 * connected using the default Arduino wiring
 *
*/

#ifndef GLCD_PANEL_CONFIG_H
#define GLCD_PANEL_CONFIG_H

/*
 * define name for panel configuration
 */
#define glcd_PanelConfigName "ks0108-Manual"

/*********************************************************/
/*  Configuration for LCD panel specific configuration   */
/*********************************************************/
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

// panel controller chips
#define CHIP_WIDTH     64  // pixels per chip
#define CHIP_HEIGHT    64  // pixels per chip

/*********************************************************/
/*  Configuration for assigning LCD bits to Arduino Pins */
/*********************************************************/

/*
 * define name for pin configuration
 */
#define glcd_PinConfigName "ks0108-Manual"

/*
 * Pins can be assigned using arduino pin numbers 0-n
 * Pins can also be assigned using PIN_Pb 
 *   where P is port A-L and b is bit 0-7
 *   Example: port D pin 3 is PIN_D3
 *
 */


/* Data pin definitions
 */
#define glcdData0Pin        8
#define glcdData1Pin        9
#define glcdData2Pin        10
#define glcdData3Pin        11
#define glcdData4Pin        4
#define glcdData5Pin        5
#define glcdData6Pin        6
#define glcdData7Pin        7

/* Arduino pins used for Commands
 * default assignment uses the first five analog pins
 */
#define glcdCSEL1        14
#define glcdCSEL2        15
// uncomment the following if more than two chip select pins are needed
//#define glcdCSEL3        3   // third chip select line on pin 3 if needed
//#define glcdCSEL4        2   // fourth chip select if needed

#define glcdRW            16
#define glcdDI            17
#define glcdEN            18
// Reset Bit  - uncomment the next line if reset is connected to an output pin
//#define glcdRES            19    // Reset Bit

/*********************************************************/
/*  Chip Select pin assignments                          */
/*********************************************************/
#define CS_2Chips_2Pins    // default has two chips selected using two pins
//#define CS_2Chips_1Pin   // 2 chips selected using one CS pin (the other CS is inverted in hardware)
//#define CS_3Chips_2Pins  // 3 chips selected using two CS pins
//#define CS_3Chips_3Pins  // 3 chips selected using three CS pins
//#define CS_4Chips_2Pins  // 4 chips selected using two CS pins
//#define CS_4Chips_4Pins  // 4 chips selected using 4 CS pins

/*
 * Changing the CHIP_SELECTED define from HIGH to LOW swaps chips on two chip panels 
 * Making this change inverts the chip select lines (from active HIGH to active LOW) 
 */  
#define CHIP_SELECTED     HIGH   // Change this to LOW to invert chip selects 
#define CHIP_UNSELECTED  (!CHIP_SELECTED) // don't change this
 
/*
 * Two Chip panels using two select pins
 */
#ifdef CS_2Chips_2Pins
#define glcd_CHIP0 glcdCSEL1,CHIP_SELECTED,   glcdCSEL2,CHIP_UNSELECTED
#define glcd_CHIP1 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_SELECTED

/*
 * Two Chip panels using one select pin
 */
#elif defined  CS_2Chips_1Pin
#define glcd_CHIP0 glcdCSEL1,CHIP_UNSELECTED
#define glcd_CHIP1 glcdCSEL1,CHIP_SELECTED

/*
 * Three Chip panel using two select pins
 */
#elif defined CS_3Chips_2Pins
#define glcd_CHIP0 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_SELECTED
#define glcd_CHIP1 glcdCSEL1,CHIP_SELECTED,   glcdCSEL2,CHIP_UNSELECTED
#define glcd_CHIP2 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_UNSELECTED

/*
 * example of three Chip panel using three select pins
 * in this example, the chip is selected by setting a corresponding pin LOW
 *
 * Don't forget that glcdCSEL3 needs to defined (uncommented in the command pin assignments)
 */
#elif defined CS_3Chips_3Pins
#define glcd_CHIP0 glcdCSEL1,CHIP_SELECTED,   glcdCSEL2,CHIP_UNSELECTED, glcdCSEL3,CHIP_UNSELECTED
#define glcd_CHIP1 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_SELECTED,   glcdCSEL3,CHIP_UNSELECTED
#define glcd_CHIP2 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_UNSELECTED, glcdCSEL3,CHIP_SELECTED

/*
 * Four Chip panel using four select pins
 *
 * Don't forget that glcdCSEL3 and glcdCSEL4 need to defined
 */
#elif defined CS_4Chips_4Pins
#define glcd_CHIP0 glcdCSEL1,CHIP_SELECTED,   glcdCSEL2,CHIP_UNSELECTED, glcdCSEL3,CHIP_UNSELECTED, glcdCSEL4,CHIP_UNSELECTED
#define glcd_CHIP1 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_SELECTED,   glcdCSEL3,CHIP_UNSELECTED, glcdCSEL4,CHIP_UNSELECTED
#define glcd_CHIP2 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_UNSELECTED, glcdCSEL3,CHIP_SELECTED,   glcdCSEL4,CHIP_UNSELECTED
#define glcd_CHIP3 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_UNSELECTED, glcdCSEL3,CHIP_UNSELECTED, glcdCSEL4,CHIP_SELECTED

/*
 * Four Chip panel using two select pins
 */
#elif defined CS_4Chips_2Pins
#define glcd_CHIP0 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_UNSELECTED
#define glcd_CHIP1 glcdCSEL1,CHIP_SELECTED,   glcdCSEL2,CHIP_UNSELECTED
#define glcd_CHIP2 glcdCSEL1,CHIP_SELECTED,   glcdCSEL2,CHIP_SELECTED
#define glcd_CHIP3 glcdCSEL1,CHIP_UNSELECTED, glcdCSEL2,CHIP_SELECTED
#endif

/*
 * The following defines are for panel specific low level timing.
 *
 * See your data sheet for the exact timing and waveforms.
 * All defines below are in nanoseconds.
 */

#define GLCD_tDDR   320    /* Data Delay time (E high to valid read data)        */
#define GLCD_tAS    140    /* Address setup time (ctrl line changes to E high)   */
#define GLCD_tDSW   200    /* Data setup time (data lines setup to dropping E)   */
#define GLCD_tWH    450    /* E hi level width (minimum E hi pulse width)        */
#define GLCD_tWL    450    /* E lo level width (minimum E lo pulse width)        */


// calculate number of chips & round up if width is not evenly divisable
#define glcd_CHIP_COUNT ((DISPLAY_WIDTH + CHIP_WIDTH - 1)  / CHIP_WIDTH)

#include "device/ks0108_Device.h"
#endif //GLCD_PANEL_CONFIG_H
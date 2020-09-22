--- src/file.c.orig	2003-12-15 13:43:47 UTC
+++ src/file.c
@@ -18,7 +18,9 @@
 \******************************************************************************/
 #include "hex.h"
 
-/*******************************************************\
+FILE *fpIN, *fpOUT;						/* global file ptrs   */
+
+/*******************************************************	\
  * Description: prints out a line of text to the screen*
  *		the current address line and both the          *
  *		hex and decimal values for the current         *

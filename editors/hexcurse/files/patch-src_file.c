--- src/file.c.orig	2015-11-18 04:33:09 UTC
+++ src/file.c
@@ -18,6 +18,8 @@
 \******************************************************************************/
 #include "hex.h"
 
+FILE *fpIN;			/* global file ptr           */
+
 /*******************************************************\
  * Description: prints out a line of text to the screen*
  *		the current address line and both the          *

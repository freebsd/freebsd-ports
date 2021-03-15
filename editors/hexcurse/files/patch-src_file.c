--- src/file.c.orig	2015-11-17 20:33:09.000000000 -0800
+++ src/file.c	2021-03-15 11:34:15.464468000 -0700
@@ -18,6 +18,8 @@
 \******************************************************************************/
 #include "hex.h"
 
+FILE *fpIN;			/* global file ptr           */
+
 /*******************************************************\
  * Description: prints out a line of text to the screen*
  *		the current address line and both the          *

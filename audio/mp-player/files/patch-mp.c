--- mp.c.orig	2004-01-28 21:39:17 UTC
+++ mp.c
@@ -27,7 +27,7 @@
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include <curses.h>
 #include <panel.h>
@@ -41,6 +41,7 @@
  ******************************************************************************/
 
 #define VERSION		"0.6"		/* here it is */
+#define NAME_MAX	255
 
 
 /*** Various. ***/

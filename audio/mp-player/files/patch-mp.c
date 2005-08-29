--- mp.c.orig	Fri Aug 26 09:59:36 2005
+++ mp.c	Fri Aug 26 09:59:57 2005
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

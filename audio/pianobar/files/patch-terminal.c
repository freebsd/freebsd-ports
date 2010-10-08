--- src/terminal.c.orig	2010-10-07 01:54:32.000000000 -0700
+++ src/terminal.c	2010-10-08 14:51:21.000000000 -0700
@@ -21,9 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
-#define _BSD_SOURCE /* setlinebuf() */
-
 #include <termios.h>
 #include <stdio.h>
 

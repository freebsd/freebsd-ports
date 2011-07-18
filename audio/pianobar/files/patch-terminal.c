--- src/terminal.c.orig	2011-07-09 01:40:54.000000000 -0700
+++ src/terminal.c	2011-07-14 12:07:01.000000000 -0700
@@ -21,7 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
 #define _BSD_SOURCE /* setlinebuf() */
 
 #include <termios.h>

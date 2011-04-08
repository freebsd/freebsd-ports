--- src/terminal.c.orig	2011-01-24 04:00:25.000000000 -0800
+++ src/terminal.c	2011-04-07 14:29:03.000000000 -0700
@@ -21,9 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
-#define _BSD_SOURCE /* setlinebuf() */
-
 #include <termios.h>
 #include <stdio.h>

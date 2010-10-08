--- src/main.c.orig	2010-10-07 01:54:32.000000000 -0700
+++ src/main.c	2010-10-08 14:51:13.000000000 -0700
@@ -21,9 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
-#define _BSD_SOURCE /* strdup() */
-
 /* system includes */
 #include <stdlib.h>
 #include <string.h>

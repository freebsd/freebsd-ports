--- src/main.c.orig	2011-01-24 04:00:25.000000000 -0800
+++ src/main.c	2011-04-07 14:28:49.000000000 -0700
@@ -21,9 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
-#define _BSD_SOURCE /* strdup() */
-
 /* system includes */
 #include <stdlib.h>
 #include <string.h>

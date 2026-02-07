--- src/fmp.c.orig	2025-05-31 21:44:22 UTC
+++ src/fmp.c
@@ -20,8 +20,6 @@
  * THE SOFTWARE.
  */
 
-#define _XOPEN_SOURCE 600 /* strptime */
-#define _POSIX_C_SOURCE 200809L /* fmemopen */
 #include <time.h>
 
 #include <fcntl.h>

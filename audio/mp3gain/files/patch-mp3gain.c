-- mp3gain.c.orig	Sun Jan 19 07:16:02 2003
+++ mp3gain.c	Sun Jan 19 07:16:37 2003
@@ -50,6 +50,7 @@
 
 #ifndef WIN32
 #undef asWIN32DLL
+#include <sys/types.h>
 #include <utime.h>
 #endif /* WIN32 */


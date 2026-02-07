--- src/utils/mongoose.c.orig	2020-02-08 03:34:10 UTC
+++ src/utils/mongoose.c
@@ -15,6 +15,8 @@
 // Alternatively, you can license this library under a commercial
 // license, as set out in <http://cesanta.com/>.
 
+#include <sys/socket.h>
+
 #undef UNICODE									// Use ANSI WinAPI functions
 #undef _UNICODE								 // Use multibyte encoding on Windows
 #define _MBCS									 // Use multibyte encoding on Windows

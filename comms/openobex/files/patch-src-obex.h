--- src/obex.h.orig	Wed Oct  1 13:17:13 2003
+++ src/obex.h	Mon Mar 22 11:11:11 2004
@@ -30,7 +30,7 @@
 #ifndef OBEX_H
 #define OBEX_H
 
-#include <stdint.h>
+#include <sys/types.h>
 
 #ifdef _WIN32
 #include <winsock.h>

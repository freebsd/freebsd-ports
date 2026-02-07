--- libs/indicore/indicom.c.orig	2025-10-13 12:03:12 UTC
+++ libs/indicore/indicom.c
@@ -67,6 +67,7 @@
 
 #ifdef __FreeBSD__
 #include <sys/param.h>
+#include <sys/socket.h>
 #endif
 
 #if defined(BSD) && !defined(__GNU__)

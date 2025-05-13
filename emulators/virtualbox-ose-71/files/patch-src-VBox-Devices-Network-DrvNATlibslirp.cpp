--- src/VBox/Devices/Network/DrvNATlibslirp.cpp.orig	2025-01-25 00:56:57.537046000 +0700
+++ src/VBox/Devices/Network/DrvNATlibslirp.cpp	2025-01-25 00:58:05.112538000 +0700
@@ -57,6 +57,7 @@
 
 #ifdef RT_OS_FREEBSD
 # include <netinet/in.h>
+# include <sys/socket.h>
 #endif
 
 #include <iprt/asm.h>

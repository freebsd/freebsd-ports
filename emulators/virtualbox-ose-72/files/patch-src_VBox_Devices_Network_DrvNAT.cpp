--- src/VBox/Devices/Network/DrvNAT.cpp.orig	2025-08-13 19:48:03 UTC
+++ src/VBox/Devices/Network/DrvNAT.cpp
@@ -57,6 +57,7 @@
 
 #ifdef RT_OS_FREEBSD
 # include <netinet/in.h>
+# include <sys/socket.h>
 #endif
 
 #include <iprt/asm.h>

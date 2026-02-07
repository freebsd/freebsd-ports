--- uppsrc/Core/Cpu.cpp.orig	2021-09-25 19:55:51 UTC
+++ uppsrc/Core/Cpu.cpp
@@ -10,6 +10,8 @@
 
 #ifdef PLATFORM_FREEBSD
 #include <sys/vmmeter.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #ifdef PLATFORM_MACOS
 #include <mach/mach.h>

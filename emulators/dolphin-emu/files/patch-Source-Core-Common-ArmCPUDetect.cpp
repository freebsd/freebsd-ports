--- Source/Core/Common/ArmCPUDetect.cpp.orig	2025-09-15 19:46:44 UTC
+++ Source/Core/Common/ArmCPUDetect.cpp
@@ -20,6 +20,7 @@
 #include <sys/auxv.h>
 #elif defined(HAVE_ELF_AUX_INFO)
 #include <sys/auxv.h>
+#include <sys/sysctl.h>
 #elif defined(__OpenBSD__)
 #include <machine/armreg.h>
 #include <machine/cpu.h>

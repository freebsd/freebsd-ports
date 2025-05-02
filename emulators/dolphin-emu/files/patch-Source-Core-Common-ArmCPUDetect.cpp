--- Source/Core/Common/ArmCPUDetect.cpp.orig    2025-05-02 13:15:23 UTC
+++ Source/Core/Common/ArmCPUDetect.cpp
@@ -20,6 +20,7 @@
 #include <sys/auxv.h>
 #elif defined(__FreeBSD__)
 #include <sys/auxv.h>
+#include <sys/sysctl.h>
 #elif defined(__OpenBSD__)
 #include <machine/armreg.h>
 #include <machine/cpu.h>

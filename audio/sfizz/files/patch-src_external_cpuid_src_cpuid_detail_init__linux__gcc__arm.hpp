--- src/external/cpuid/src/cpuid/detail/init_linux_gcc_arm.hpp.orig	2021-09-13 17:35:44 UTC
+++ src/external/cpuid/src/cpuid/detail/init_linux_gcc_arm.hpp
@@ -11,7 +11,9 @@
 
 #include <elf.h>
 #include <fcntl.h>
+#if defined(__linux__)
 #include <linux/auxvec.h>
+#endif
 #include <unistd.h>
 
 #include "cpuinfo_impl.hpp"

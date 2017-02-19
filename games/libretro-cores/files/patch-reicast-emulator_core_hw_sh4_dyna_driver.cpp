--- reicast-emulator/core/hw/sh4/dyna/driver.cpp.orig	2016-11-04 17:23:51 UTC
+++ reicast-emulator/core/hw/sh4/dyna/driver.cpp
@@ -34,7 +34,7 @@
 u8 SH4_TCB[CODE_SIZE+4096]
 #if defined(_WIN32) || FEAT_SHREC != DYNAREC_JIT
 	;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	__attribute__((section(".text")));
 #elif defined(__MACH__)
 	__attribute__((section("__TEXT,.text")));

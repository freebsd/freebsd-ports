--- libswirl/hw/sh4/dyna/driver.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/hw/sh4/dyna/driver.cpp
@@ -31,7 +31,7 @@
 u8 SH4_TCB[CODE_SIZE+4096]
 #if HOST_OS == OS_WINDOWS || FEAT_SHREC != DYNAREC_JIT
 	;
-#elif HOST_OS == OS_LINUX
+#elif HOST_OS == OS_LINUX || HOST_OS == OS_FREEBSD
 	__attribute__((section(".text")));
 #elif HOST_OS==OS_DARWIN
 	__attribute__((section("__TEXT,.text")));

--- core/hw/aica/dsp_x64.cpp.orig	2021-05-17 21:23:19 UTC
+++ core/hw/aica/dsp_x64.cpp
@@ -37,6 +37,8 @@ DECL_ALIGN(4096) static u8 CodeBuffer[32 * 1024]
 	__attribute__((section(".text")));
 #elif defined(__MACH__)
 	__attribute__((section("__TEXT,.text")));
+#elif defined(__FreeBSD__)
+	__attribute__((section(".text")));
 #else
 	#error CodeBuffer code section unknown
 #endif

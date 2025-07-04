--- src/threading.cpp.orig	2025-07-04 20:51:54 UTC
+++ src/threading.cpp
@@ -532,6 +532,8 @@ gb_internal gb_inline void yield_thread(void) {
 #elif defined(GB_CPU_RISCV)
 	// I guess?
 	__asm__ volatile ("nop" : : : "memory");
+#elif defined(GB_CPU_PPC)
+	__asm__ volatile ("ori 0,0,0" : : : "memory");
 #else
 #error Unknown architecture
 #endif

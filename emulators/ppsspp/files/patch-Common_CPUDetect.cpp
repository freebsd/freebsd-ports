--- Common/CPUDetect.cpp.orig	2015-02-26 20:05:06 UTC
+++ Common/CPUDetect.cpp
@@ -62,17 +62,7 @@ static unsigned long long _xgetbv(unsign
 #define _XCR_XFEATURE_ENABLED_MASK 0
 #endif
 
-#if defined __FreeBSD__
-#include <sys/types.h>
-#include <machine/cpufunc.h>
-
-void do_cpuidex(u32 regs[4], u32 cpuid_leaf, u32 ecxval) {
-	__cpuidex((int *)regs, cpuid_leaf, ecxval);
-}
-void do_cpuid(u32 regs[4], u32 cpuid_leaf) {
-	__cpuid((int *)regs, cpuid_leaf);
-}
-#elif !defined(MIPS)
+#if !defined(MIPS)
 
 void do_cpuidex(u32 regs[4], u32 cpuid_leaf, u32 ecxval) {
 #if defined(__i386__) && defined(__PIC__)

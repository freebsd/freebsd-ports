--- processor_support.h.orig	2020-07-24 20:07:54 UTC
+++ processor_support.h
@@ -12,7 +12,7 @@
 
 #if defined(__INTEL_COMPILER)
 #   define USING_INTEL_COMPILER
-#elif defined(__GNUC__)
+#elif defined(__GNUC__) && (defined(__amd64__) || defined(__i386__))
 #   define USING_GCC_COMPILER
 #   include <cpuid.h>
 #elif defined(_MSC_VER)
@@ -52,8 +52,7 @@ class ProcessorSupport { (public)
 #elif defined(USING_GCC_COMPILER)
         __get_cpuid(0x1, &regs.EAX, &regs.EBX, &regs.ECX, &regs.EDX);
 #else
-        std::cerr << "ERROR: please define __cpuid() for this build.\n"; 
-        assert(0);
+	return false;
 #endif
         if( !( (regs.ECX & BIT(20)) && (regs.ECX & BIT(23)) ) ) return false;
     }

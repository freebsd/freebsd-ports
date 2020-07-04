--- processor_support.h.orig	2020-07-04 10:42:26 UTC
+++ processor_support.h
@@ -49,7 +49,7 @@ class ProcessorSupport { (public)
 #elif defined(USING_GCC_COMPILER)
         __get_cpuid(0x1, &regs.EAX, &regs.EBX, &regs.ECX, &regs.EDX);
 #else
-        std::cerr << “ERROR: please define __cpuid() for this build.\n”; 
+        std::cerr << "ERROR: please define __cpuid() for this build.\n"; 
         assert(0);
 #endif
         if( !( (regs.ECX & BIT(20)) && (regs.ECX & BIT(23)) ) ) return false;

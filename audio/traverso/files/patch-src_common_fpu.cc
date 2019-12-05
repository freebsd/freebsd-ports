--- src/common/fpu.cc.orig	2019-12-05 16:58:12 UTC
+++ src/common/fpu.cc
@@ -33,9 +33,7 @@ FPU::FPU ()
 
 	_flags = Flags (0);
 
-#ifndef ARCH_X86
-	return;
-#endif
+#ifdef ARCH_X86
 	
 #ifndef USE_X86_64_ASM
 	asm volatile (
@@ -108,6 +106,7 @@ FPU::FPU ()
 			free (fxbuf);
 		}
 	}
+#endif
 }			
 
 FPU::~FPU ()

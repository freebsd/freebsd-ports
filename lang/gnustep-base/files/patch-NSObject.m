--- Source/NSObject.m.orig	Sun Nov 10 10:29:45 2002
+++ Source/NSObject.m	Sat Dec  7 08:45:28 2002
@@ -779,6 +779,7 @@
 #endif
       
 #ifdef __FreeBSD__
+#if defined __i386__
       // Manipulate the FPU to add the exception mask. (Fixes SIGFPE
       // problems on *BSD)
 
@@ -789,6 +790,7 @@
 	cw |= 1; /* Mask 'invalid' exception */
 	__asm__ volatile ("fldcw (%0)" : : "g" (&cw));
       }
+#endif
 #endif
 
       GSSetLocaleC("");		// Set up locale from environment.

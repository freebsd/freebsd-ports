--- setup/FreeBSD/oss/build/osscore.c.orig	2008-12-14 16:35:26.000000000 -0500
+++ setup/FreeBSD/oss/build/osscore.c	2009-07-10 16:14:12.000000000 -0400
@@ -419,20 +419,20 @@
   if (!(flags_reg & FLAGS_ID))
     return 0;
 
-#define CPUID_FXSR	(1<<24)
-#define CPUID_SSE	(1<<25)
-#define CPUID_SSE2	(1<<26)
+#define OSS_CPUID_FXSR	(1<<24)
+#define OSS_CPUID_SSE	(1<<25)
+#define OSS_CPUID_SSE2	(1<<26)
 
   cpuid (1, &eax, &ebx, &ecx, &edx);
 
-  if (!(edx & CPUID_FXSR))
+  if (!(edx & OSS_CPUID_FXSR))
     return 0;
 
   /*
    * Older machines require different FP handling than the latest ones. Use the SSE
    * instruction set as an indicator.
    */
-  if (!(edx & CPUID_SSE))
+  if (!(edx & OSS_CPUID_SSE))
     old_arch = 1;
 
   return 1;

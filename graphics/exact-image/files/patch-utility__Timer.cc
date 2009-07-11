--- utility/Timer.cc.orig	2009-07-10 11:30:14.000000000 -0400
+++ utility/Timer.cc	2009-07-10 11:30:30.000000000 -0400
@@ -145,7 +145,7 @@
 		   );
   return ((uint64_t)hi << 32) | lo;
 #endif
-#elif define(__mips__)
+#elif defined(__mips__)
   unsigned int ticks;
   __asm__ __volatile__ ("dmfc0 %0,$9" : "=r" (ticks));
   return ticks;

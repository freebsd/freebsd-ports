--- fec.h.orig	2007-07-02 13:26:12.000000000 -0400
+++ fec.h	2007-07-02 13:38:26.000000000 -0400
@@ -262,7 +262,7 @@
 void find_cpu_mode(void); /* Call this once at startup to set Cpu_mode */
 
 /* Determine parity of argument: 1 = odd, 0 = even */
-#ifdef __i386__
+#ifdef notyet__i386__
 static inline int parityb(unsigned char x){
   __asm__ __volatile__ ("test %1,%1;setpo %0" : "=g"(x) : "r" (x));
   return x;

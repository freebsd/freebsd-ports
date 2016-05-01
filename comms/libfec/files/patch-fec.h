--- fec.h.orig	2006-10-13 01:10:53 UTC
+++ fec.h
@@ -262,7 +262,7 @@ extern enum cpu_mode {UNKNOWN=0,PORT,MMX
 void find_cpu_mode(void); /* Call this once at startup to set Cpu_mode */
 
 /* Determine parity of argument: 1 = odd, 0 = even */
-#ifdef __i386__
+#ifdef notyet__i386__
 static inline int parityb(unsigned char x){
   __asm__ __volatile__ ("test %1,%1;setpo %0" : "=g"(x) : "r" (x));
   return x;

--- src/cputest.c.orig	2005-02-28 00:26:01 UTC
+++ src/cputest.c
@@ -31,18 +31,33 @@ static int mm_support(void)
 {
 #ifdef ARCH_X86
     int rval;
+#ifdef __x86_64__
+    int64_t eax, ebx, ecx, edx;
+#else
     int eax, ebx, ecx, edx;
+#endif
     char vendor[13] = "UnknownVndr";
     
     __asm__ __volatile__ (
                           /* See if CPUID instruction is supported ... */
                           /* ... Get copies of EFLAGS into eax and ecx */
-                          "pushf\n\t"
 #ifdef __x86_64__
+                          "pushf\n\t"
+                          "pop %0\n\t"
+                          "mov %0, %1\n\t"
+                          
+                          /* ... Toggle the ID bit in one copy and store */
+                          /*     to the EFLAGS reg */
+                          "xor $0x200000, %0\n\t"
+                          "push %0\n\t"
+                          "popf\n\t"
+                          
+                          /* ... Get the (hopefully modified) EFLAGS */
+                          "pushf\n\t"
                           "pop %0\n\t"
 #else
+                          "pushf\n\t"
                           "popl %0\n\t"
-#endif
                           "movl %0, %1\n\t"
                           
                           /* ... Toggle the ID bit in one copy and store */
@@ -53,9 +68,6 @@ static int mm_support(void)
                           
                           /* ... Get the (hopefully modified) EFLAGS */
                           "pushf\n\t"
-#ifdef __x86_64__
-                          "pop %0\n\t"
-#else
                           "popl %0\n\t"
 #endif
                           : "=a" (eax), "=c" (ecx)

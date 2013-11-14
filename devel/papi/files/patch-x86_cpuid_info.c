--- x86_cpuid_info.c.orig	2013-08-06 20:12:26.000000000 +0400
+++ x86_cpuid_info.c	2013-11-14 16:49:25.000000000 +0400
@@ -1252,11 +1252,14 @@
                     unsigned int* ecx, unsigned int* edx, 
                     unsigned int index, unsigned int ecx_in )
 {
-  unsigned int a,b,c,d;
-  __asm__ __volatile__ (".byte 0x53\n\tcpuid\n\tmovl %%ebx, %%esi\n\t.byte 0x5b"
-		: "=a" (a), "=S" (b), "=c" (c), "=d" (d) \
-		: "0" (index), "2"(ecx_in) );
-  *eax = a; *ebx = b; *ecx = c; *edx = d;
+  __asm__ __volatile__ (
+		"mov	%%ebx, %%esi;"
+		"cpuid;"
+		"mov	%%ebx, %3;"
+		"mov	%%esi, %%ebx;"
+		: "=a" (*eax), "=c" (*ecx), "=d" (*edx)
+		: "m" (*ebx), "0" (index), "1" (ecx_in), "2" (42)
+		: "esi", "memory" );
 }
 
 

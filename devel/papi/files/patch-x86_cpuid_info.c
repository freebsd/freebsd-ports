--- x86_cpuid_info.c.orig	2015-12-03 22:41:35 UTC
+++ x86_cpuid_info.c
@@ -1274,11 +1274,14 @@ cpuid2 ( unsigned int* eax, unsigned int
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
 #endif
 

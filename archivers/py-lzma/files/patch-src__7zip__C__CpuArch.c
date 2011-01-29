--- ./src/7zip/C/CpuArch.c.orig	2010-07-21 22:13:50.000000000 +0200
+++ ./src/7zip/C/CpuArch.c	2011-01-27 02:31:44.000000000 +0100
@@ -72,14 +72,15 @@
 
   #else
 
- 	__asm__ __volatile__ (
- 		"cpuid"
- 		: "=a" (*a) ,
- 		  "=b" (*b) ,
- 		  "=c" (*c) ,
- 		  "=d" (*d)
-		: "0" (function)) ;
-
+ /* fix GCC build error with -fPIC by storing ebx value before calling cpuid */
+  __asm__ __volatile__(
+		"pushl %%ebx \n\t"
+                "cpuid \n\t"
+                "movl %%ebx, %1 \n\t"
+                "popl %%ebx \n\t"
+                : "=a"(*a), "=r"(*b), "=c"(*c), "=d"(*d)
+                : "a"(function)
+                : "cc");
   #endif
   
   #else

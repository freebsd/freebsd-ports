--- extern/ode/dist/ode/src/timer.cpp.orig	Tue Oct 14 23:33:02 2003
+++ extern/ode/dist/ode/src/timer.cpp	Tue Oct 14 23:34:59 2003
@@ -106,9 +106,9 @@
 
 static inline void getClockCount (unsigned long cc[2])
 {
-  asm volatile ("
-	rdtsc
-	movl %%eax,(%%esi)
+  asm volatile ("\
+	rdtsc \n\
+	movl %%eax,(%%esi) \n\
 	movl %%edx,4(%%esi)"
 	: : "S" (cc) : "%eax","%edx","cc","memory");
 }
@@ -116,8 +116,8 @@
 
 static inline void serialize()
 {
-  asm volatile ("
-	mov $0,%%eax
+  asm volatile (" \
+	mov $0,%%eax \n\
 	cpuid"
 	: : : "%eax","%ebx","%ecx","%edx","cc","memory");
 }

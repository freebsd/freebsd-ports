--- src/cpuinfo/SDL_cpuinfo.c.orig	Tue Feb 10 16:31:35 2004
+++ src/cpuinfo/SDL_cpuinfo.c	Sun May 16 19:19:48 2004
@@ -22,7 +22,7 @@
 
 #ifdef SAVE_RCSID
 static char rcsid =
- "@(#) $Id: SDL_cpuinfo.c,v 1.14 2004/02/10 15:31:35 slouken Exp $";
+ "@(#) $Id: SDL_cpuinfo.c,v 1.16 2004/05/16 17:19:48 slouken Exp $";
 #endif
 
 /* CPU feature detection for SDL */
@@ -81,6 +81,26 @@
 	:
 	: "%eax", "%ecx"
 	);
+#elif defined(__GNUC__) && defined(__x86_64__)
+/* Technically, if this is being compiled under __x86_64__ then it has 
+CPUid by definition.  But it's nice to be able to prove it.  :)      */
+	__asm__ (
+"        pushfq                      # Get original EFLAGS             \n"
+"        popq    %%rax                                                 \n"
+"        movq    %%rax,%%rcx                                           \n"
+"        xorl    $0x200000,%%eax     # Flip ID bit in EFLAGS           \n"
+"        pushq   %%rax               # Save new EFLAGS value on stack  \n"
+"        popfq                       # Replace current EFLAGS value    \n"
+"        pushfq                      # Get new EFLAGS                  \n"
+"        popq    %%rax               # Store new EFLAGS in EAX         \n"
+"        xorl    %%ecx,%%eax         # Can not toggle ID bit,          \n"
+"        jz      1f                  # Processor=80486                 \n"
+"        movl    $1,%0               # We have CPUID support           \n"
+"1:                                                                    \n"
+	: "=m" (has_CPUID)
+	:
+	: "%rax", "%rcx"
+	);
 #elif defined(_MSC_VER)
 	__asm {
         pushfd                      ; Get original EFLAGS
@@ -103,7 +123,7 @@
 static __inline__ int CPU_getCPUIDFeatures()
 {
 	int features = 0;
-#if defined(__GNUC__) && defined(i386)
+#if defined(__GNUC__) && ( defined(i386) || defined(__x86_64__) )
 	__asm__ (
 "        movl    %%ebx,%%edi\n"
 "        xorl    %%eax,%%eax         # Set up for CPUID instruction    \n"
@@ -118,7 +138,7 @@
 "        movl    %%edi,%%ebx\n"
 	: "=m" (features)
 	:
-	: "%eax", "%ebx", "%ecx", "%edx", "%edi"
+	: "%eax", "%ecx", "%edx", "%edi"
 	);
 #elif defined(_MSC_VER)
 	__asm {
@@ -139,7 +159,7 @@
 static __inline__ int CPU_getCPUIDFeaturesExt()
 {
 	int features = 0;
-#if defined(__GNUC__) && defined(i386)
+#if defined(__GNUC__) && (defined(i386) || defined (__x86_64__) )
 	__asm__ (
 "        movl    %%ebx,%%edi\n"
 "        movl    $0x80000000,%%eax   # Query for extended functions    \n"
@@ -153,7 +173,7 @@
 "        movl    %%edi,%%ebx\n"
 	: "=m" (features)
 	:
-	: "%eax", "%ebx", "%ecx", "%edx", "%edi"
+	: "%eax", "%ecx", "%edx", "%edi"
 	);
 #elif defined(_MSC_VER)
 	__asm {

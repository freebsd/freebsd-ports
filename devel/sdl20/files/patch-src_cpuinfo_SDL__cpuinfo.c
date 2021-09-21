--- src/cpuinfo/SDL_cpuinfo.c.orig	2020-03-11 01:36:18 UTC
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -53,6 +53,9 @@
 #include <sys/param.h>
 #include <sys/sysctl.h> /* For AltiVec check */
 #include <machine/cpu.h>
+#elif defined(__FreeBSD__) && defined(__powerpc__)
+#include <machine/cpu.h>
+#include <sys/auxv.h>
 #elif SDL_ALTIVEC_BLITTERS && HAVE_SETJMP
 #include <signal.h>
 #include <setjmp.h>
@@ -110,7 +113,7 @@
 #define CPU_HAS_AVX512F (1 << 12)
 #define CPU_HAS_ARM_SIMD (1 << 13)
 
-#if SDL_ALTIVEC_BLITTERS && HAVE_SETJMP && !__MACOSX__ && !__OpenBSD__
+#if SDL_ALTIVEC_BLITTERS && HAVE_SETJMP && !__MACOSX__ && !__OpenBSD__ && !__FreeBSD__
 /* This is the brute force way of detecting instruction sets...
    the idea is borrowed from the libmpeg2 library - thanks!
  */
@@ -325,6 +328,11 @@ CPU_haveAltiVec(void)
     int error = sysctl(selectors, 2, &hasVectorUnit, &length, NULL, 0);
     if (0 == error)
         altivec = (hasVectorUnit != 0);
+#elif defined(__FreeBSD__) && defined(__powerpc__)
+    unsigned long cpufeatures;
+    elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures));
+    altivec = cpufeatures & PPC_FEATURE_HAS_ALTIVEC;
+    return altivec;
 #elif SDL_ALTIVEC_BLITTERS && HAVE_SETJMP
     void (*handler) (int sig);
     handler = signal(SIGILL, illegal_instruction);

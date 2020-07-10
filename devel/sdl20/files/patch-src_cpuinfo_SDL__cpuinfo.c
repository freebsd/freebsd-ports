--- src/cpuinfo/SDL_cpuinfo.c.orig	2020-03-11 01:36:18 UTC
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -49,7 +49,7 @@
 #endif
 #if defined(__MACOSX__) && (defined(__ppc__) || defined(__ppc64__))
 #include <sys/sysctl.h>         /* For AltiVec check */
-#elif defined(__OpenBSD__) && defined(__powerpc__)
+#elif (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__powerpc__)
 #include <sys/param.h>
 #include <sys/sysctl.h> /* For AltiVec check */
 #include <machine/cpu.h>
@@ -314,9 +314,11 @@ CPU_haveAltiVec(void)
 {
     volatile int altivec = 0;
 #ifndef SDL_CPUINFO_DISABLED
-#if (defined(__MACOSX__) && (defined(__ppc__) || defined(__ppc64__))) || (defined(__OpenBSD__) && defined(__powerpc__))
+#if (defined(__MACOSX__) && (defined(__ppc__) || defined(__ppc64__))) || (defined(__OpenBSD__) && defined(__powerpc__)) || (defined(__FreeBSD__) && defined(__powerpc__))
 #ifdef __OpenBSD__
     int selectors[2] = { CTL_MACHDEP, CPU_ALTIVEC };
+#elif __FreeBSD__
+    int selectors[2] = { CTL_HW, PPC_FEATURE_HAS_ALTIVEC };
 #else
     int selectors[2] = { CTL_HW, HW_VECTORUNIT };
 #endif

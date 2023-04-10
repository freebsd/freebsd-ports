--- include/my_cpu.h.orig	2021-09-27 13:32:48 UTC
+++ include/my_cpu.h
@@ -23,7 +23,8 @@
   The defines are the same ones used by the linux kernel
 */
 
-#ifdef _ARCH_PWR8
+#if defined(_ARCH_PWR8)
+#if defined(linux)
 #include <sys/platform/ppc.h>
 /* Very low priority */
 #define HMT_very_low() __ppc_set_ppr_very_low()
@@ -37,6 +38,22 @@
 #define HMT_medium_high() __ppc_set_ppr_med_high()
 /* High priority */
 #define HMT_high() asm volatile("or 3,3,3")
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+/* Very low priority */
+#define HMT_very_low() __asm__ volatile ("or 31,31,31")
+/* Low priority */
+#define HMT_low() __asm__ volatile ("or 1,1,1")
+/* Medium low priority */
+#define HMT_medium_low() __asm__ volatile ("or 6,6,6")
+/* Medium priority */
+#define HMT_medium() __asm__ volatile ("or 2,2,2")
+/* Medium high priority */
+#define HMT_medium_high() __asm__ volatile ("or 5,5,5")
+/* High priority */
+#define HMT_high() asm volatile("or 3,3,3")
+#endif
 #else
 #define HMT_very_low()
 #define HMT_low()
@@ -81,7 +98,12 @@ static inline void MY_RELAX_CPU(void)
   __asm__ __volatile__ ("pause");
 #endif
 #elif defined(_ARCH_PWR8)
+#if defined(linux)
   __ppc_get_timebase();
+#elif defined(__FreeBSD__)
+  uint64_t __tb;
+  __asm__ volatile ("mfspr %0, 268" : "=r" (__tb));
+#endif
 #elif defined __GNUC__ && (defined __arm__ || defined __aarch64__)
   /* Mainly, prevent the compiler from optimizing away delay loops */
 #ifdef _aarch64_

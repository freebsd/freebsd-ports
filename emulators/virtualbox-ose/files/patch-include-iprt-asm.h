--- include/iprt/asm.h.orig	2017-03-08 17:15:12 UTC
+++ include/iprt/asm.h
@@ -140,7 +140,9 @@
  * Used to work around some 4.3.x register allocation issues in this version of
  * the compiler. So far this workaround is still required for 4.4 and 4.5 but
  * definitely not for 5.x */
-#define RT_INLINE_ASM_GCC_4_3_X_X86 (RT_GNUC_PREREQ(4, 3) && !RT_GNUC_PREREQ(5, 0) && defined(__i386__))
+#ifndef __clang__
+# define RT_INLINE_ASM_GCC_4_3_X_X86 (RT_GNUC_PREREQ(4, 3) && !RT_GNUC_PREREQ(5, 0) && defined(__i386__))
+#endif
 #ifndef RT_INLINE_ASM_GCC_4_3_X_X86
 # define RT_INLINE_ASM_GCC_4_3_X_X86 0
 #endif
@@ -158,6 +160,8 @@
 #  define RT_INLINE_DONT_MIX_CMPXCHG8B_AND_PIC 1
 # elif defined(_MSC_VER) /* Visual C++ has trouble too, but it'll only tell us when C4688 is enabled. */
 #  define RT_INLINE_DONT_MIX_CMPXCHG8B_AND_PIC 0
+# elif defined(__clang__)
+#  define RT_INLINE_DONT_MIX_CMPXCHG8B_AND_PIC 0
 # else
 #  define RT_INLINE_DONT_MIX_CMPXCHG8B_AND_PIC \
     (   (defined(PIC) || defined(__PIC__)) \

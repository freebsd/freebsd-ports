--- ./newlib/libc/include/sys/config.h.orig	2010-12-02 19:30:46.000000000 +0000
+++ ./newlib/libc/include/sys/config.h	2012-01-25 19:33:12.000000000 +0000
@@ -130,6 +130,12 @@
 #define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
 #endif
 
+/* We compile newlib with -G0 for PSP, but if we're compiling an app with $gp enabled,
+   then _impure_ptr is expected to live in .sdata. */
+#if defined(__psp__)
+#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
+#endif
+
 #ifdef __xstormy16__
 #define __SMALL_BITFIELDS
 #undef INT_MAX

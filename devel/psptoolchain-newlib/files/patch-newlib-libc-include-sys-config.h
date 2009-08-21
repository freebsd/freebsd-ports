--- newlib/libc/include/sys/config.h.orig	2006-08-30 00:00:59.000000000 +0300
+++ newlib/libc/include/sys/config.h	2007-06-01 12:22:26.000000000 +0300
@@ -98,6 +98,12 @@
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

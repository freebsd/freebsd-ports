--- ./newlib/libc/include/machine/time.h.orig	2009-04-06 22:04:33.000000000 +0000
+++ ./newlib/libc/include/machine/time.h	2012-01-25 19:33:11.000000000 +0000
@@ -9,6 +9,10 @@
 #endif
 #endif /* !__rtems__ */
 
+#if defined(__psp__)
+#define _CLOCKS_PER_SEC_  1000000
+#endif
+
 #ifdef __SPU__
 #include <sys/types.h>
 int nanosleep (const struct timespec *, struct timespec *);

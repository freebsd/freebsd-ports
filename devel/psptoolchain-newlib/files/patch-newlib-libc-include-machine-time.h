--- newlib/libc/include/machine/time.h.orig	2000-12-04 21:06:37.000000000 +0200
+++ newlib/libc/include/machine/time.h	2007-06-01 12:22:26.000000000 +0300
@@ -9,6 +9,10 @@
 #endif
 #endif /* !__rtems__ */
 
+#if defined(__psp__)
+#define _CLOCKS_PER_SEC_  1000000
+#endif
+
 #endif	/* _MACHTIME_H_ */
 
 

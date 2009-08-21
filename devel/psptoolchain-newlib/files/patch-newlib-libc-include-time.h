--- newlib/libc/include/time.h.orig	2005-11-18 17:57:24.000000000 +0200
+++ newlib/libc/include/time.h	2007-06-01 12:22:26.000000000 +0300
@@ -174,6 +174,16 @@
 }
 #endif
 #endif /* _POSIX_TIMERS */
+#if defined(__psp__)
+#ifdef __cplusplus
+extern "C" {
+#endif
+int _EXFUN(nanosleep, (const struct timespec  *rqtp, struct timespec *rmtp));
+#ifdef __cplusplus
+}
+#endif
+#endif /*  __psp__ */
+
 
 #ifdef __cplusplus
 extern "C" {

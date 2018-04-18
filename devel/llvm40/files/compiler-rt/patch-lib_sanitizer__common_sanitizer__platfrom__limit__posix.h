--- lib/sanitizer_common/sanitizer_platform_limits_posix.h.orig	2017-05-24 19:09:24.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.h	2017-05-24 20:12:47.183536000 +0000
@@ -485,7 +485,12 @@
   };
 #elif SANITIZER_FREEBSD
   struct __sanitizer_dirent {
+#if __FreeBSD_version < 1200031
     unsigned int d_fileno;
+#else
+    unsigned long long d_fileno;
+    unsigned long long d_off;
+#endif
     unsigned short d_reclen;
     // more fields that we don't care about
   };

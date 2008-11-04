--- ../pr/include/md/_freebsd.h
+++ ../pr/include/md/_freebsd.h
@@ -57,6 +57,8 @@
 #define _PR_SI_ARCHITECTURE "ia64"
 #elif defined(__amd64__)
 #define _PR_SI_ARCHITECTURE "amd64"
+#elif defined(__powerpc__)
+#define _PR_SI_ARCHITECTURE "powerpc"
 #else
 #error "Unknown CPU architecture"
 #endif
@@ -106,6 +108,16 @@
 #define _PR_IPV6_V6ONLY_PROBE
 #endif
 
+#if (__FreeBSD_version >= 700016) || (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)
+#if defined(_PR_PTHREADS)
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#define _PR_HAVE_GETHOST_R
+#define _PR_HAVE_GETHOST_R_INT
+#define _PR_HAVE_THREADSAFE_GETHOST
+#endif
+#endif
+
 #define USE_SETJMP
 
 #ifndef _PR_PTHREADS

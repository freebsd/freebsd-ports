--- dbdimp.c.orig	Thu Aug 29 06:28:30 2002
+++ dbdimp.c	Tue Sep 10 16:35:15 2002
@@ -2430,8 +2430,13 @@
 #  define S_INT64_DEC_FULL    ".%%%dLd%%1Ld"
 #  define S_INT64_DEC_NOSCALE ".%%1Ld"
 #else                        /* others: linux, xBSD, solaris, hp-ux, ... */
+#ifdef __FreeBSD__
+#  define S_INT64_FULL        "%%qd.%%%dlld%%1lld"
+#  define S_INT64_NOSCALE     "%%qd.%%1lld"
+#else
 #  define S_INT64_FULL        "%%lld.%%%dlld%%1lld"
 #  define S_INT64_NOSCALE     "%%lld.%%1lld"
+#endif
 #  define S_INT64_DEC_FULL    ".%%%dlld%%1lld"
 #  define S_INT64_DEC_NOSCALE ".%%1lld"
 #endif

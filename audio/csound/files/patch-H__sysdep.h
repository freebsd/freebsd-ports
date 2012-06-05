--- H/sysdep.h.orig	2012-05-29 02:41:30.000000000 +0900
+++ H/sysdep.h	2012-05-31 11:19:28.000000000 +0900
@@ -96,7 +96,11 @@
   #define EXP exp
   #define LOG log
   #define LOG10 log10
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+  #define LOG2(x) (log(x) / log(2))
+#else
   #define LOG2 log2
+#endif
   #define POWER pow
   #define SQRT sqrt
   #define HYPOT hypot
@@ -122,7 +126,11 @@
   #define EXP expf
   #define LOG logf
   #define LOG10 log10f
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+  #define LOG2(x) (logf(x) / logf(2))
+#else
   #define LOG2 log2f
+#endif
   #define POWER powf
   #define SQRT sqrtf
   #define HYPOT hypotf

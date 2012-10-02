--- H/sysdep.h.bak	2012-09-27 02:58:13.000000000 +0000
+++ H/sysdep.h	2012-09-27 03:02:06.000000000 +0000
@@ -100,6 +100,11 @@
   #define EXP exp
   #define LOG log
   #define LOG10 log10
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+  #define LOG2(x) (log(x) / log(2))
+#else
+   #define LOG2 log2
+#endif
   /* #define LOG2 log2 */
   #define POWER pow
   #define SQRT sqrt
@@ -126,6 +131,11 @@
   #define EXP expf
   #define LOG logf
   #define LOG10 log10f
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+  #define LOG2(x) (logf(x) / logf(2))
+#else
+   #define LOG2 log2f
+#endif
   /* #define LOG2 log2f */
   #define POWER powf
   #define SQRT sqrtf

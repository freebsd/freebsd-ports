--- src/common/darktable.c.orig	2015-07-26 11:47:47 UTC
+++ src/common/darktable.c
@@ -403,7 +403,7 @@ int dt_init(int argc, char *argv[], cons
 #else
   int sse3_supported = 0;
 
-#if(__GNUC_PREREQ(4, 8) || __has_builtin(__builtin_cpu_supports))
+#if(__GNUC_PREREQ(4, 8) || (!defined(__FreeBSD__) && __has_builtin(__builtin_cpu_supports)))
   // NOTE: _may_i_use_cpu_feature() looks better, but only avaliable in ICC
   sse3_supported = __builtin_cpu_supports("sse3");
 #else

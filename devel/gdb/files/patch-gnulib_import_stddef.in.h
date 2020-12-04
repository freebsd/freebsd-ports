--- gnulib/import/stddef.in.h.orig	2020-09-13 04:33:41.000000000 +0200
+++ gnulib/import/stddef.in.h	2020-11-01 15:46:55.395133000 +0100
@@ -90,7 +90,7 @@
 #if defined _MSC_VER && defined __cplusplus
 # include <cstddef>
 #else
-# if ! (@HAVE_MAX_ALIGN_T@ || defined _GCC_MAX_ALIGN_T)
+# if 0
 #  if !GNULIB_defined_max_align_t
 /* On the x86, the maximum storage alignment of double, long, etc. is 4,
    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,

--- gnulib/import/stddef.in.h.orig	2023-02-01 20:45:52.000000000 -0800
+++ gnulib/import/stddef.in.h	2023-02-24 09:49:57.368290000 -0800
@@ -116,7 +116,7 @@
     && defined __cplusplus
 # include <cstddef>
 #else
-# if ! (@HAVE_MAX_ALIGN_T@ || (defined _GCC_MAX_ALIGN_T && !defined __clang__))
+# if 0
 #  if !GNULIB_defined_max_align_t
 /* On the x86, the maximum storage alignment of double, long, etc. is 4,
    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,

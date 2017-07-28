diff --git gdb/gnulib/import/stddef.in.h gdb/gnulib/import/stddef.in.h
index f4c4a1070d..023ea2064d 100644
--- gdb/gnulib/import/stddef.in.h
+++ gdb/gnulib/import/stddef.in.h
@@ -84,7 +84,7 @@
 /* Some platforms lack max_align_t.  The check for _GCC_MAX_ALIGN_T is
    a hack in case the configure-time test was done with g++ even though
    we are currently compiling with gcc.  */
-#if ! (@HAVE_MAX_ALIGN_T@ || defined _GCC_MAX_ALIGN_T)
+#if 0
 /* On the x86, the maximum storage alignment of double, long, etc. is 4,
    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,
    and the C11 standard allows this.  Work around this problem by

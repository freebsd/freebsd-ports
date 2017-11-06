--- src/gdb/gdb/gnulib/import/stddef.in.h.orig	2015-08-26 16:08:17 UTC
+++ src/gdb/gdb/gnulib/import/stddef.in.h
@@ -82,7 +82,7 @@
 #endif
 
 /* Some platforms lack max_align_t.  */
-#if !@HAVE_MAX_ALIGN_T@
+#if 0
 /* On the x86, the maximum storage alignment of double, long, etc. is 4,
    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,
    and the C11 standard allows this.  Work around this problem by

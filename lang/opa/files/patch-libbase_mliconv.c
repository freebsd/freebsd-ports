--- libbase/mliconv.c.orig	2012-06-11 16:27:50.000000000 -0500
+++ libbase/mliconv.c	2012-06-11 16:28:06.000000000 -0500
@@ -137,9 +137,9 @@
 	CAMLparam2(conv, source);
 	CAMLlocal1(result);
 	struct mliconv_t *internal = mliconv_val(conv);
-/* #if !defined(__APPLE__) */
-/* 	const */
-/* #endif */
+#ifdef _LIBICONV_H
+ 	const
+#endif
 	char *s = String_val(source);
 	size_t s_len = caml_string_length(source);
 	size_t d_len = s_len * 6;

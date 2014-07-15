--- src/cook.c.orig	2014-07-16 00:43:47.656653653 +0800
+++ src/cook.c	2014-07-16 00:47:26.498655673 +0800
@@ -471,7 +471,12 @@
 
 		/* convert network to local charset, tex2iso, iso2asc etc. */
 		ncharset = get_param(part->params, "charset");
+#ifndef CHARSET_CONVERSION
 		process_charsets(&line, &max_line_len, ncharset ? ncharset : "US-ASCII" , tinrc.mm_local_charset, curr_group->attribute->tex2iso_conv && art->tex2iso);
+#else
+		/* use undeclared charset */
+		process_charsets(&line, &max_line_len, get_param(part->params, "charset") ? get_param(part->params, "charset") : curr_group->attribute->undeclared_charset, tinrc.mm_local_charset, curr_group->attribute->tex2iso_conv && art->tex2iso);
+#endif
 
 #if defined(MULTIBYTE_ABLE) && !defined(NO_LOCALE)
 		if (IS_LOCAL_CHARSET("UTF-8"))

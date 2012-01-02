--- src/cook.c.orig	2011-08-18 03:58:24.288554846 +0800
+++ src/cook.c	2011-08-18 13:36:23.791151539 +0800
@@ -472,7 +472,12 @@
 			break;	/* premature end of file, file error etc. */
 
 		/* convert network to local charset, tex2iso, iso2asc etc. */
+#ifndef CHARSET_CONVERSION
 		process_charsets(&line, &max_line_len, get_param(part->params, "charset"), tinrc.mm_local_charset, curr_group->attribute->tex2iso_conv && art->tex2iso);
+#else
+		/* use undeclared charset */
+		process_charsets(&line, &max_line_len, get_param(part->params, "charset") ? get_param(part->params, "charset") : curr_group->attribute->undeclared_charset, tinrc.mm_local_charset, curr_group->attribute->tex2iso_conv && art->tex2iso);
+#endif
 
 #if defined(MULTIBYTE_ABLE) && !defined(NO_LOCALE)
 		if (IS_LOCAL_CHARSET("UTF-8"))

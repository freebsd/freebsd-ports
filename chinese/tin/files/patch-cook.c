--- src/cook.c.orig	Wed Dec  1 18:48:37 2004
+++ src/cook.c	Fri Mar 18 23:34:58 2005
@@ -408,8 +408,13 @@
 		if (!(line && strlen(line)))
 			break;	/* premature end of file, file error etc. */
 
+#ifndef CHARSET_CONVERSION
 		/* convert network to local charset, tex2iso, iso2asc etc. */
 		process_charsets(&line, &max_line_len, get_param(part->params, "charset"), tinrc.mm_local_charset, curr_group->attribute->tex2iso_conv && art->tex2iso);
+#else
+		// force to use undeclared_charset first
+		process_charsets(&line, &max_line_len, (curr_group->attribute->undeclared_charset) ? (curr_group->attribute->undeclared_charset) : get_param(part->params, "charset"), tinrc.mm_local_charset, curr_group->attribute->tex2iso_conv && art->tex2iso);
+#endif /* !CHARSET_CONVERSION */
 
 #if defined(MULTIBYTE_ABLE) && !defined(NO_LOCALE)
 		if (IS_LOCAL_CHARSET("UTF-8"))

--- src/cook.c.orig	Tue Aug 26 20:34:07 2003
+++ src/cook.c	Wed Oct  8 15:05:05 2003
@@ -719,7 +719,12 @@
 			break;	/* premature end of file, file error etc. */
 
 		/* convert network to local charset, tex2iso, iso2asc etc. */
+#ifndef CHARSET_CONVERSION
 		process_charsets(&line, &max_line_len, get_param(part->params, "charset"), tinrc.mm_local_charset, CURR_GROUP.attribute->tex2iso_conv && art->tex2iso);
+#else
+		// force to use undeclared_charset first
+		process_charsets(&line, &max_line_len, (CURR_GROUP.attribute->undeclared_charset) ? (CURR_GROUP.attribute->undeclared_charset) : get_param(part->params, "charset"), tinrc.mm_local_charset, CURR_GROUP.attribute->tex2iso_conv && art->tex2iso);
+#endif /* !CHARSET_CONVERSION */
 
 		len = (int) strlen(line);
 

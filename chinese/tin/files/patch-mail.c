--- src/mail.c.orig	Sun Aug 10 21:27:36 2003
+++ src/mail.c	Wed Oct  8 14:52:42 2003
@@ -327,7 +327,12 @@
 			 *
 			 * TODO: change US-ASCII to UTF-8 when NNTP draft becomes RFC
 			 */
+#ifndef CHARSET_CONVERSION
 			process_charsets(&r, &r_len, "US-ASCII", tinrc.mm_local_charset, FALSE);
+#else
+			process_charsets(&r, &r_len, (CURR_GROUP.attribute->undeclared_charset) ? (CURR_GROUP.attribute->undeclared_charset) : "US-ASCII", tinrc.mm_local_charset, FALSE);
+#endif /* !CHARSET_CONVERSION */
+
 			group->description = convert_to_printable(r);
 		}
 

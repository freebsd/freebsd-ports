--- src/mail.c.orig	2014-07-16 00:48:14.918652518 +0800
+++ src/mail.c	2014-07-16 00:48:50.462660253 +0800
@@ -514,7 +514,11 @@
 			/*
 			 * Protect against invalid character sequences.
 			 */
+#ifndef CHARSET_CONVERSION
 			process_charsets(&r, &r_len, "UTF-8", tinrc.mm_local_charset, FALSE);
+#else
+			process_charsets(&r, &r_len, (CURR_GROUP.attribute->undeclared_charset) ? (CURR_GROUP.attribute->undeclared_charset) : "UTF-8", tinrc.mm_local_charset, FALSE);
+#endif
 			group->description = convert_to_printable(r, FALSE);
 		}
 

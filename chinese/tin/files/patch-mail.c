--- src/mail.c.orig	2011-04-17 15:14:00.000000000 -0700
+++ src/mail.c	2012-01-02 05:08:38.000000000 -0800
@@ -510,7 +510,12 @@
 			/*
 			 * Protect against invalid character sequences.
 			 */
+#ifndef CHARSET_CONVERSION
 			process_charsets(&r, &r_len, "UTF-8", tinrc.mm_local_charset, FALSE);
+#else
+			process_charsets(&r, &r_len, (CURR_GROUP.attribute->undeclared_charset) ? (CURR_GROUP.attribute->undeclared_charset) : "UTF-8", tinrc.mm_local_charset, FALSE);
+#endif
+
 			group->description = convert_to_printable(r, FALSE);
 		}
 

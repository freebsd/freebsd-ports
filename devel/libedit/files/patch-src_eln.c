--- src/eln.c.orig	2015-03-25 21:02:28.000000000 +0100
+++ src/eln.c	2015-03-28 11:42:29.913925000 +0100
@@ -75,12 +75,17 @@ public const char *
 el_gets(EditLine *el, int *nread)
 {
 	const wchar_t *tmp;
+	int nwread;
+
+	*nread = 0;
 
 	if (!(el->el_flags & CHARSET_IS_UTF8))
 		el->el_flags |= IGNORE_EXTCHARS;
-	tmp = el_wgets(el, nread);
+	tmp = el_wgets(el, &nwread);
 	if (!(el->el_flags & CHARSET_IS_UTF8))
 		el->el_flags &= ~IGNORE_EXTCHARS;
+	for (int i = 0; i < nwread; i++)
+		*nread += ct_enc_width(tmp[i]);
 	return ct_encode_string(tmp, &el->el_lgcyconv);
 }
 

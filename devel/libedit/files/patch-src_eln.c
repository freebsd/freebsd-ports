--- src/eln.c.orig	2014-06-18 21:06:34.000000000 +0200
+++ src/eln.c	2015-01-09 08:48:42.000000000 +0100
@@ -75,10 +75,18 @@ public const char *
 el_gets(EditLine *el, int *nread)
 {
 	const wchar_t *tmp;
+	int nwread;
+
+	*nread = 0;
+
+	if (!(el->el_flags & CHARSET_IS_UTF8))
+		el->el_flags |= IGNORE_EXTCHARS;
+	tmp = el_wgets(el, &nwread);
+	if (!(el->el_flags & CHARSET_IS_UTF8))
+		el->el_flags &= ~IGNORE_EXTCHARS;
+	for (int i = 0; i < nwread; i++)
+		*nread += ct_enc_width(tmp[i]);
 
-	el->el_flags |= IGNORE_EXTCHARS;
-	tmp = el_wgets(el, nread);
-	el->el_flags &= ~IGNORE_EXTCHARS;
 	return ct_encode_string(tmp, &el->el_lgcyconv);
 }
 

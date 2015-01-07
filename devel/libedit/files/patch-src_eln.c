--- src/eln.c.orig	2015-01-07 22:26:24 UTC
+++ src/eln.c
@@ -76,9 +76,11 @@ el_gets(EditLine *el, int *nread)
 {
 	const wchar_t *tmp;
 
-	el->el_flags |= IGNORE_EXTCHARS;
+	if (!(el->el_flags & CHARSET_IS_UTF8))
+		el->el_flags |= IGNORE_EXTCHARS;
 	tmp = el_wgets(el, nread);
-	el->el_flags &= ~IGNORE_EXTCHARS;
+	if (!(el->el_flags & CHARSET_IS_UTF8))
+		el->el_flags &= ~IGNORE_EXTCHARS;
 	return ct_encode_string(tmp, &el->el_lgcyconv);
 }
 

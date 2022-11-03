--- ex/ex_subst.c.orig	2020-08-01 22:27:51 UTC
+++ ex/ex_subst.c
@@ -1194,7 +1194,8 @@ re_tag_conv(SCR *sp, CHAR_T **ptrnp, size_t *plenp, in
 	for (; len > 0; --len) {
 		if (p[0] == '\\' && (p[1] == '/' || p[1] == '?')) {
 			++p;
-			--len;
+			if (len > 1)
+				--len;
 		} else if (STRCHR(L("^.[]$*"), p[0]))
 			*t++ = '\\';
 		*t++ = *p++;

Argh, FreeBSD 4.X has a wctype.h header that does nothing.

--- lib/util.c.orig	Sat Nov 13 17:41:09 2004
+++ lib/util.c	Wed Jan 19 07:01:41 2005
@@ -28,9 +28,7 @@
 #if defined HAVE_WCHAR_H
 #include <wchar.h>
 #endif
-#if defined HAVE_WCTYPE_H
-#include <wctype.h>
-#endif
+#include <ctype.h>
 #endif
 #include <locale.h>
 #include <time.h>
@@ -464,7 +462,7 @@ strip_invalid_chars_testing(char *str)
 
     /* Replace illegals to legal */
     for (wstrp = w_in; *wstrp; wstrp++) {
-	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iswcntrl(*wstrp)))
+	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iscntrl(*wstrp)))
 	    continue;
 	*wstrp = replacement;
     }
@@ -543,7 +541,7 @@ strip_invalid_chars_stable(char *str)
 
     /* Replace illegals to legal */
     for (wstrp = w_in; *wstrp; wstrp++) {
-	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iswcntrl(*wstrp)))
+	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iscntrl(*wstrp)))
 	    continue;
 	*wstrp = replacement;
     }

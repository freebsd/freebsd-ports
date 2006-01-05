Argh, FreeBSD 4.X has a wctype.h header that does nothing.

--- lib/util.c.orig	Sun Sep 11 12:46:20 2005
+++ lib/util.c	Sun Sep 11 12:46:20 2005
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
@@ -450,7 +448,7 @@
 
     /* Replace illegals to legal */
     for (wstrp = w_in; *wstrp; wstrp++) {
-	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iswcntrl(*wstrp)))
+	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iscntrl(*wstrp)))
 	    continue;
 	*wstrp = replacement;
     }
@@ -525,7 +523,7 @@
 
     /* Replace illegals to legal */
     for (wstrp = w_in; *wstrp; wstrp++) {
-	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iswcntrl(*wstrp)))
+	if ((wcschr(w_invalid, *wstrp) == NULL) && (!iscntrl(*wstrp)))
 	    continue;
 	*wstrp = replacement;
     }

--- readline/chardefs.h.orig	Sun May 19 23:29:25 2002
+++ readline/chardefs.h	Sun May 19 23:29:37 2002
@@ -32,9 +32,6 @@
 #    endif
 #    include <string.h>
 #  endif /* HAVE_STRING_H */
-#  if defined (HAVE_STRINGS_H)
-#    include <strings.h>
-#  endif /* HAVE_STRINGS_H */
 #else
 #  include <string.h>
 #endif /* !HAVE_CONFIG_H */

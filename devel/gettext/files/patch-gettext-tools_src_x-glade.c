--- gettext-tools/src/x-glade.c.orig	Sat Aug 28 11:53:08 2004
+++ gettext-tools/src/x-glade.c	Sat Aug 28 11:53:48 2004
@@ -30,7 +30,11 @@
 # include <dlfcn.h>
 #else
 # if HAVE_LIBEXPAT
-#  include <expat.h>
+#  if HAVE_BSDXML
+#   include <bsdxml.h>
+#  else
+#   include <expat.h>
+#  endif
 # endif
 #endif
 

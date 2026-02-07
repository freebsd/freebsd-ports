--- src/translation.h.orig	2013-12-16 00:04:52.000000000 +0100
+++ src/translation.h	2013-12-16 00:05:10.000000000 +0100
@@ -21,7 +21,7 @@
 #ifndef REGEXXER_TRANSLATION_H_INCLUDED
 #define REGEXXER_TRANSLATION_H_INCLUDED
 
-#include <glib/gmacros.h>
+#include <glib.h>
 #include <glibmm/ustring.h>
 
 #ifndef gettext_noop

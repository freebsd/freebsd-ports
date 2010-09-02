--- src/i18n.h~
+++ src/i18n.h
@@ -20,6 +20,7 @@
 
 #ifdef USE_GETTEXT
 
+#include <iconv.h>
 #include <libintl.h>
 #define _(String) gettext (String)
 

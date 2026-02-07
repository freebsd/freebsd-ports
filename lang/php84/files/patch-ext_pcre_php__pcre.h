--- ext/pcre/php_pcre.h.orig	2024-07-28 11:55:02 UTC
+++ ext/pcre/php_pcre.h
@@ -20,7 +20,7 @@
 #ifdef HAVE_BUNDLED_PCRE
 #include "pcre2lib/pcre2.h"
 #else
-#include "pcre2.h"
+#include <pcre2.h>
 #endif
 
 #include <locale.h>

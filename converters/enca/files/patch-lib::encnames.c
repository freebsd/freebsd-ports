--- lib/encnames.c.orig	Sun Aug 18 13:05:20 2002
+++ lib/encnames.c	Wed Sep 18 17:36:39 2002
@@ -25,7 +25,7 @@
 
 #include "enca.h"
 #include "internal.h"
-#include "encodings.h"
+#include "tools/encodings.h"
 
 #define NCHARSETS (sizeof(CHARSET_INFO)/sizeof(EncaCharsetInfo))
 #define NALIASES (sizeof(ALIAS_LIST)/sizeof(char *))

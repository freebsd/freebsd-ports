--- src/pinyin_internal.h.orig	2011-12-19 23:45:40.000000000 -0600
+++ src/pinyin_internal.h	2012-02-06 09:53:12.804569766 -0600
@@ -47,6 +47,7 @@
 #include "flexible_ngram.h"
 
 using namespace pinyin;
+#define ENODATA		ENOENT
 
 
 #endif

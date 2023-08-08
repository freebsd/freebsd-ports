--- src/mongo/db/fts/stemmer.h.orig	2022-09-26 08:31:59 UTC
+++ src/mongo/db/fts/stemmer.h
@@ -32,7 +32,7 @@
 
 #include "mongo/base/string_data.h"
 #include "mongo/db/fts/fts_language.h"
-#include "third_party/libstemmer_c/include/libstemmer.h"
+#include "libstemmer.h"
 
 namespace mongo {
 

--- util/google/sparsehash/sparseconfig.h.orig	2013-12-16 12:42:46.000000000 +0100
+++ util/google/sparsehash/sparseconfig.h	2013-12-16 12:43:09.000000000 +0100
@@ -5,7 +5,7 @@
 #define GOOGLE_NAMESPACE ::google
 
 /* the location of <hash_fun.h>/<stl_hash_fun.h> */
-#define HASH_FUN_H "hash_fun.h"
+#define HASH_FUN_H <ext/hash_fun.h>
 
 /* the location of <hash_map> */
 #define HASH_MAP_H <ext/hash_map>

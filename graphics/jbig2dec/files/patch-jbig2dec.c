--- jbig2dec.c.orig	2020-09-10 15:14:14 UTC
+++ jbig2dec.c
@@ -33,7 +33,10 @@
 #endif
 
 #include "os_types.h"
-#include "sha1.h"
+#include <sha.h>
+#ifndef SHA1_DIGEST_SIZE
+#	define SHA1_DIGEST_SIZE	20
+#endif
 
 #ifdef JBIG_EXTERNAL_MEMENTO_H
 #include JBIG_EXTERNAL_MEMENTO_H
@@ -217,7 +220,7 @@ hash_print(jbig2dec_params_t *params, FILE *out)
     char digest[2 * SHA1_DIGEST_SIZE + 1];
     int i;
 
-    SHA1_Final(params->hash_ctx, md);
+    SHA1_Final(md, params->hash_ctx);
     for (i = 0; i < SHA1_DIGEST_SIZE; i++) {
         snprintf(&(digest[2 * i]), 3, "%02x", md[i]);
     }

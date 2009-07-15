--- src/baz/libarch/pfs-signatures.c.old	Wed Nov  2 21:46:56 2005
+++ src/baz/libarch/pfs-signatures.c	Wed Nov  2 21:47:09 2005
@@ -29,7 +29,7 @@
 #include "libarch/namespace.h"
 #include "libarch/archives.h"
 #include "libarch/cached-archive.h"
-#include <gpgme.h>
+#include <gpgme/gpgme.h>
 #include "libarch/pfs-signatures.h"
 
 
@@ -1154,6 +1154,7 @@
     gpgme_ctx_t context;
     gpgme_data_t signature_data;
     gpgme_data_t signed_content;
+    gpgme_check_version (NULL);
     invariant (GPG_ERR_NO_ERROR == gpgme_new (&context));
     invariant (GPG_ERR_NO_ERROR == gpgme_data_new_from_mem (&signature_data, *signed_message, str_length (*signed_message), 0));
     invariant (GPG_ERR_NO_ERROR == gpgme_data_new (&signed_content));

--- src/lib/nfs/Error.cxx.orig	2019-04-03 10:23:57 UTC
+++ src/lib/nfs/Error.cxx
@@ -33,12 +33,13 @@
 #include "Error.hxx"
 #include "util/StringFormat.hxx"
 
+#include <assert.h>
+#include <string.h>
+#include <sys/time.h>
+
 extern "C" {
 #include <nfsc/libnfs.h>
 }
-
-#include <assert.h>
-#include <string.h>
 
 static StringBuffer<256>
 FormatNfsClientError(struct nfs_context *nfs, const char *msg) noexcept

--- src/lib/nfs/Error.cxx.orig	2020-09-23 13:26:51 UTC
+++ src/lib/nfs/Error.cxx
@@ -33,13 +33,13 @@
 #include "Error.hxx"
 #include "util/StringFormat.hxx"
 
+#include <cassert>
+#include <string.h>
+#include <sys/time.h>
+
 extern "C" {
 #include <nfsc/libnfs.h>
 }
-
-#include <cassert>
-
-#include <string.h>
 
 static StringBuffer<256>
 FormatNfsClientError(struct nfs_context *nfs, const char *msg) noexcept

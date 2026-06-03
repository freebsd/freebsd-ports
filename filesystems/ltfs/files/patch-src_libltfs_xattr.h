--- src/libltfs/xattr.h.orig	2025-08-23 03:05:20 UTC
+++ src/libltfs/xattr.h
@@ -66,7 +66,9 @@ extern "C" {
 #include "libltfs/arch/freebsd/xattr.h"
 #endif
 
-#include "fuse.h"
+
+#include "libltfs/ltfs_fuse_version.h"
+#include <fuse.h>
 #include "ltfs.h"
 
 #define LTFS_PRIVATE_PREFIX "ltfs."

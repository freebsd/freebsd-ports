--- sysdeps/common/fsusage.h.orig	Thu Mar 11 15:54:03 2004
+++ sysdeps/common/fsusage.h	Thu Mar 11 15:56:12 2004
@@ -20,15 +20,17 @@
 #if !defined FSUSAGE_H_
 # define FSUSAGE_H_
 
+#include <sys/types.h>
+
 struct fs_usage
 {
   int fsu_blocksize;		/* Size of a block.  */
-  uintmax_t fsu_blocks;		/* Total blocks. */
-  uintmax_t fsu_bfree;		/* Free blocks available to superuser. */
-  uintmax_t fsu_bavail;		/* Free blocks available to non-superuser. */
+  uint64_t fsu_blocks;		/* Total blocks. */
+  uint64_t fsu_bfree;		/* Free blocks available to superuser. */
+  uint64_t fsu_bavail;		/* Free blocks available to non-superuser. */
   int fsu_bavail_top_bit_set;	/* 1 if fsu_bavail represents a value < 0.  */
-  uintmax_t fsu_files;		/* Total file nodes. */
-  uintmax_t fsu_ffree;		/* Free file nodes. */
+  uint64_t fsu_files;		/* Total file nodes. */
+  uint64_t fsu_ffree;		/* Free file nodes. */
 };
 
 # ifndef PARAMS

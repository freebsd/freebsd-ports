--- libxfs/xfs_attr_remote.c.orig	2015-07-24 04:28:04 UTC
+++ libxfs/xfs_attr_remote.c
@@ -19,6 +19,7 @@
 #include <xfs.h>
 
 #define ATTR_RMTVALUE_MAPSIZE	1	/* # of map entries at once */
+#define XATTR_SIZE_MAX	65536
 
 /*
  * Each contiguous block has a header, so it is not just a simple attribute

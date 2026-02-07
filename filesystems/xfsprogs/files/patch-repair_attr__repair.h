--- repair/attr_repair.h.orig	2015-07-24 04:28:04 UTC
+++ repair/attr_repair.h
@@ -71,6 +71,7 @@ struct xfs_acl {
  * For v4 superblocks, that is limited to 25 entries. For v5 superblocks, it is
  * limited only by the maximum size of the xattr that stores the information.
  */
+#define XATTR_SIZE_MAX 65536
 #define XFS_ACL_MAX_ENTRIES(mp) \
 	(xfs_sb_version_hascrc(&mp->m_sb) \
 		?  (XATTR_SIZE_MAX - sizeof(struct xfs_acl)) / \

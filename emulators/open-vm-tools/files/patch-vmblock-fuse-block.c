--- vmblock-fuse/block.c.orig	2009-02-18 17:02:53.000000000 +0900
+++ vmblock-fuse/block.c	2009-03-01 16:37:11.000000000 +0900
@@ -519,11 +519,7 @@
    struct DblLnkLst_Links *curr;
 
    /* XXX The following is only temporary. */
-#ifdef __FreeBSD__
-   os_assert_rwlock_held(&blockedFilesLock);
-#else
    ASSERT(os_rwlock_held(&blockedFilesLock));
-#endif
 
    DblLnkLst_ForEach(curr, &blockedFiles) {
       BlockInfo *currBlock = DblLnkLst_Container(curr, BlockInfo, links);

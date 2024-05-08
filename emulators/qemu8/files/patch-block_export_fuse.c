--- block/export/fuse.c.orig	2023-12-19 21:24:34 UTC
+++ block/export/fuse.c
@@ -690,12 +690,6 @@ static void fuse_fallocate(fuse_req_t req, fuse_ino_t 
         return;
     }
 
-#ifdef CONFIG_FALLOCATE_PUNCH_HOLE
-    if (mode & FALLOC_FL_KEEP_SIZE) {
-        length = MIN(length, blk_len - offset);
-    }
-#endif /* CONFIG_FALLOCATE_PUNCH_HOLE */
-
     if (!mode) {
         /* We can only fallocate at the EOF with a truncate */
         if (offset < blk_len) {
@@ -715,53 +709,6 @@ static void fuse_fallocate(fuse_req_t req, fuse_ino_t 
         ret = fuse_do_truncate(exp, offset + length, true,
                                PREALLOC_MODE_FALLOC);
     }
-#ifdef CONFIG_FALLOCATE_PUNCH_HOLE
-    else if (mode & FALLOC_FL_PUNCH_HOLE) {
-        if (!(mode & FALLOC_FL_KEEP_SIZE)) {
-            fuse_reply_err(req, EINVAL);
-            return;
-        }
-
-        do {
-            int size = MIN(length, BDRV_REQUEST_MAX_BYTES);
-
-            ret = blk_pwrite_zeroes(exp->common.blk, offset, size,
-                                    BDRV_REQ_MAY_UNMAP | BDRV_REQ_NO_FALLBACK);
-            if (ret == -ENOTSUP) {
-                /*
-                 * fallocate() specifies to return EOPNOTSUPP for unsupported
-                 * operations
-                 */
-                ret = -EOPNOTSUPP;
-            }
-
-            offset += size;
-            length -= size;
-        } while (ret == 0 && length > 0);
-    }
-#endif /* CONFIG_FALLOCATE_PUNCH_HOLE */
-#ifdef CONFIG_FALLOCATE_ZERO_RANGE
-    else if (mode & FALLOC_FL_ZERO_RANGE) {
-        if (!(mode & FALLOC_FL_KEEP_SIZE) && offset + length > blk_len) {
-            /* No need for zeroes, we are going to write them ourselves */
-            ret = fuse_do_truncate(exp, offset + length, false,
-                                   PREALLOC_MODE_OFF);
-            if (ret < 0) {
-                fuse_reply_err(req, -ret);
-                return;
-            }
-        }
-
-        do {
-            int size = MIN(length, BDRV_REQUEST_MAX_BYTES);
-
-            ret = blk_pwrite_zeroes(exp->common.blk,
-                                    offset, size, 0);
-            offset += size;
-            length -= size;
-        } while (ret == 0 && length > 0);
-    }
-#endif /* CONFIG_FALLOCATE_ZERO_RANGE */
     else {
         ret = -EOPNOTSUPP;
     }

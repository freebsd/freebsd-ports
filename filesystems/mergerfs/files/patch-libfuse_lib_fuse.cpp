--- libfuse/lib/fuse.cpp.orig	2025-11-18 14:35:27 UTC
+++ libfuse/lib/fuse.cpp
@@ -1636,12 +1636,12 @@ fuse_lib_setattr(fuse_req_t            *req_,
           if(arg->valid & FATTR_ATIME_NOW)
             tv[0].tv_nsec = UTIME_NOW;
           else if(arg->valid & FATTR_ATIME)
-            tv[0] = (struct timespec){ static_cast<time_t>(arg->atime), arg->atimensec };
+            tv[0] = (struct timespec){ static_cast<time_t>(arg->atime), static_cast<long>(arg->atimensec) };
 
           if(arg->valid & FATTR_MTIME_NOW)
             tv[1].tv_nsec = UTIME_NOW;
           else if(arg->valid & FATTR_MTIME)
-            tv[1] = (struct timespec){ static_cast<time_t>(arg->mtime), arg->mtimensec };
+            tv[1] = (struct timespec){ static_cast<time_t>(arg->mtime), static_cast<long>(arg->mtimensec) };
 
           err = ((fusepath != NULL) ?
                  f.ops.utimens(&req_->ctx,&fusepath[1],tv) :

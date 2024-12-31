--- src/coroutine/system.cc.orig	2024-11-28 03:39:05 UTC
+++ src/coroutine/system.cc
@@ -701,7 +701,8 @@ std::shared_ptr<AsyncLock> async_lock(void *resource) 
                            "resource(%p) has already been bound to another coroutine#%ld, "
                            "%s of the same resource in coroutine#%ld at the same time is not allowed",
                            resource,
-                           *iter,
+			   iter->second,
+			   iter->first,
                            Coroutine::get_current_cid());
         return nullptr;
     }

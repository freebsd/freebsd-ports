--- src/coroutine/system.cc.orig	2023-10-01 03:15:13 UTC
+++ src/coroutine/system.cc
@@ -711,7 +711,8 @@ std::shared_ptr<AsyncLock> async_lock(void *resource) 
                            "resource(%p) has already been bound to another coroutine#%ld, "
                            "%s of the same resource in coroutine#%ld at the same time is not allowed",
                            resource,
-                           *iter,
+			   iter->second,
+			   iter->first,
                            Coroutine::get_current_cid());
         return nullptr;
     }

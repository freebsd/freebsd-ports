--- cpp.orig/src/Freeze/TransactionalEvictorI.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/TransactionalEvictorI.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -346,7 +346,7 @@ Freeze::TransactionalEvictorI::dispatch(Request& request)
         {
         }
         
-        ~CtxHolder()
+        ~CtxHolder() ICE_NOEXCEPT_FALSE
         {
             if(_ownCtx)
             {

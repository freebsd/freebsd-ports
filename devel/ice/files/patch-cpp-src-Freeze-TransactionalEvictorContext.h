--- cpp.orig/src/Freeze/TransactionalEvictorContext.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/TransactionalEvictorContext.h	2012-09-10 11:43:58.000000000 +0200
@@ -34,7 +34,7 @@ public:
     public:
         
         ServantHolder();
-        ~ServantHolder();
+        ~ServantHolder() ICE_NOEXCEPT_FALSE;
 
         void init(const TransactionalEvictorContextPtr&, const Ice::Current&, ObjectStore<TransactionalEvictorElement>*);
 

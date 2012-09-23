--- cpp.orig/src/Freeze/TransactionalEvictorContext.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/TransactionalEvictorContext.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -273,7 +273,7 @@ Freeze::TransactionalEvictorContext::ServantHolder::ServantHolder() :
 }
 
 
-Freeze::TransactionalEvictorContext::ServantHolder::~ServantHolder()
+Freeze::TransactionalEvictorContext::ServantHolder::~ServantHolder() ICE_NOEXCEPT_FALSE
 {
     if(_ownBody && _body.ownServant)
     {

--- cpp/src/FreezeScript/Util.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/src/FreezeScript/Util.cpp
@@ -209,7 +209,7 @@ FreezeScript::readCatalog(const Ice::CommunicatorPtr& 
 {
     CatalogDataMap result;
 
-    DbEnv dbEnv(0);
+    DbEnv dbEnv((u_int32_t)0);
     try
     {
 #ifdef _WIN32

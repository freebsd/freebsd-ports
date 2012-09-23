--- cpp.orig/src/Freeze/ObjectStore.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/ObjectStore.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -189,7 +189,7 @@ Freeze::ObjectStoreBase::ObjectStoreBase(const string& facet, const string& face
     }
 }
 
-Freeze::ObjectStoreBase::~ObjectStoreBase()
+Freeze::ObjectStoreBase::~ObjectStoreBase() ICE_NOEXCEPT_FALSE
 {
     try
     {

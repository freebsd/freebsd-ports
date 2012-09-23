--- cpp.orig/src/Freeze/ObjectStore.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/ObjectStore.h	2012-09-10 11:43:58.000000000 +0200
@@ -36,7 +36,7 @@ public:
     ObjectStoreBase(const std::string&, const std::string&, bool, EvictorIBase*, 
                     const std::vector<IndexPtr>&, bool);
 
-    virtual ~ObjectStoreBase();
+    virtual ~ObjectStoreBase() ICE_NOEXCEPT_FALSE;
 
     const Ice::ObjectPtr& sampleServant() const;
 

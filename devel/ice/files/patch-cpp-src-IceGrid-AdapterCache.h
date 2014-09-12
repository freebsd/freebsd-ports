--- cpp/src/IceGrid/AdapterCache.h.orig	2013-03-11 15:19:47.000000000 +0000
+++ cpp/src/IceGrid/AdapterCache.h	2014-09-08 14:21:13.335195726 +0000
@@ -62,7 +62,7 @@ protected:
 
     AdapterCache& _cache;
     const std::string _id;
-    const std::string _application;
+    std::string _application;
 };
 typedef IceUtil::Handle<AdapterEntry> AdapterEntryPtr;
 
@@ -105,9 +105,9 @@ public:
     virtual AdapterPrx getProxy(const std::string&, bool) const { return 0; }
 
     void addReplica(const std::string&, const ServerAdapterEntryPtr&);
-    void removeReplica(const std::string&);
+    bool removeReplica(const std::string&);
 
-    void update(const LoadBalancingPolicyPtr&);
+    void update(const std::string&, const LoadBalancingPolicyPtr&);
     bool hasAdaptersFromOtherApplications() const;
 
 private:

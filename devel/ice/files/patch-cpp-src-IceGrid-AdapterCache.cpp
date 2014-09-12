--- cpp/src/IceGrid/AdapterCache.cpp.orig	2013-03-11 15:19:47.000000000 +0000
+++ cpp/src/IceGrid/AdapterCache.cpp	2014-09-08 14:21:13.335195726 +0000
@@ -202,8 +202,12 @@ AdapterCache::addServerAdapter(const AdapterDescriptor& desc, const ServerEntryP
         ReplicaGroupEntryPtr repEntry = ReplicaGroupEntryPtr::dynamicCast(getImpl(desc.replicaGroupId));
         if(!repEntry)
         {
-            Ice::Error out(_communicator->getLogger());
-            out << "can't add adapter `" << desc.id << "' to unknown replica group `" << desc.replicaGroupId << "'";
+            //
+            // Add an un-assigned replica group, the replica group will in theory be added
+            // shortly after when its application is loaded.
+            //
+            repEntry = new ReplicaGroupEntry(*this, desc.replicaGroupId, "", new RandomLoadBalancingPolicy("0"));
+            addImpl(desc.replicaGroupId, repEntry);
         }
         repEntry->addReplica(desc.id, entry);
     }
@@ -213,13 +217,24 @@ void
 AdapterCache::addReplicaGroup(const ReplicaGroupDescriptor& desc, const string& app)
 {
     Lock sync(*this);
-    if(getImpl(desc.id))
+    ReplicaGroupEntryPtr repEntry = ReplicaGroupEntryPtr::dynamicCast(getImpl(desc.id));
+    if(repEntry)
     {
-        Ice::Error out(_communicator->getLogger());
-        out << "can't add duplicate replica group `" << desc.id << "'";
+        //
+        // If the replica group isn't assigned to an application,
+        // assign it. Otherwise, it's a duplicate so we log an error.
+        //
+        if(repEntry->getApplication().empty())
+        {
+            repEntry->update(app, desc.loadBalancing);
+        }
+        else
+        {
+            Ice::Error out(_communicator->getLogger());
+            out << "can't add duplicate replica group `" << desc.id << "'";
+        }
         return;
     }
-
     addImpl(desc.id, new ReplicaGroupEntry(*this, desc.id, app, desc.loadBalancing));
 }
 
@@ -258,7 +273,16 @@ AdapterCache::removeServerAdapter(const string& id)
             Ice::Error out(_communicator->getLogger());
             out << "can't remove adapter `" << id << "' from unknown replica group `" << replicaGroupId << "'";
         }
-        repEntry->removeReplica(id);
+        else
+        {
+            //
+            // If the replica group is empty and it's not assigned, remove it.
+            //
+            if(repEntry->removeReplica(id))
+            {
+                removeImpl(replicaGroupId);
+            }
+        }
     }
 }
 
@@ -440,7 +464,7 @@ ReplicaGroupEntry::ReplicaGroupEntry(AdapterCache& cache,
     _lastReplica(0),
     _requestInProgress(false)
 {
-    update(policy);
+    update(application, policy);
 }
 
 bool
@@ -502,7 +526,7 @@ ReplicaGroupEntry::addReplica(const string& /*replicaId*/, const ServerAdapterEn
     _replicas.push_back(adapter);
 }
 
-void
+bool
 ReplicaGroupEntry::removeReplica(const string& replicaId)
 {
     Lock sync(*this);
@@ -516,14 +540,18 @@ ReplicaGroupEntry::removeReplica(const string& replicaId)
             break;
         }
     }
+
+    // Replica group can be removed if not assigned to an application and there's no more replicas
+    return _replicas.empty() && _application.empty();
 }
 
 void
-ReplicaGroupEntry::update(const LoadBalancingPolicyPtr& policy)
+ReplicaGroupEntry::update(const string& application, const LoadBalancingPolicyPtr& policy)
 {
     Lock sync(*this);
     assert(policy);
 
+    _application = application;
     _loadBalancing = policy;
 
     istringstream is(_loadBalancing->nReplicas);

--- cpp/src/IceGrid/Database.cpp.orig	2013-03-11 15:19:47.000000000 +0000
+++ cpp/src/IceGrid/Database.cpp	2014-09-08 14:21:13.335195726 +0000
@@ -2088,7 +2088,7 @@ Database::reload(const ApplicationHelper& oldApp,
         {
             ReplicaGroupEntryPtr entry = ReplicaGroupEntryPtr::dynamicCast(_adapterCache.get(r->id));
             assert(entry);
-            entry->update(r->loadBalancing);
+            entry->update(application, r->loadBalancing);
         }
         catch(const AdapterNotExistException&)
         {

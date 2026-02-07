--- sql/mdl_context_backup.cc.orig	2023-11-24 10:33:10 UTC
+++ sql/mdl_context_backup.cc
@@ -159,7 +159,7 @@ bool MDL_context_backup_manager::create_backup(const M
   DBUG_TRACE;
 
   try {
-    MDL_context_backup_key key_obj(key, keylen);
+    MDL_context_backup_key key_obj(key, key + keylen);
 
     /*
       Since this method is called as part of THD cleaning up, every XA
@@ -192,7 +192,7 @@ bool MDL_context_backup_manager::create_backup(MDL_req
 
   bool result = false;
   try {
-    MDL_context_backup_key key_obj(key, keylen);
+    MDL_context_backup_key key_obj(key, key + keylen);
     /*
       Check for presence a record with specified key in the collection of
       MDL_context_backup elements. It is ok to already have a record with
@@ -238,7 +238,7 @@ bool MDL_context_backup_manager::restore_backup(MDL_co
 
   MUTEX_LOCK(guard, &m_LOCK_mdl_context_backup);
 
-  auto result = m_backup_map.find(MDL_context_backup_key(key, keylen));
+  auto result = m_backup_map.find(MDL_context_backup_key(key, key + keylen));
   if (result != m_backup_map.end()) {
     element = result->second.get();
     res = mdl_context->clone_tickets(element->get_context(), MDL_TRANSACTION);
@@ -251,5 +251,5 @@ void MDL_context_backup_manager::delete_backup(const u
                                                const size_t keylen) {
   DBUG_TRACE;
   MUTEX_LOCK(guard, &m_LOCK_mdl_context_backup);
-  m_backup_map.erase(MDL_context_backup_key(key, keylen));
+  m_backup_map.erase(MDL_context_backup_key(key, key + keylen));
 }

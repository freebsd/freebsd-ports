--- plugin/keyring/common/system_keys_container.cc.orig	2018-08-27 16:50:01 UTC
+++ plugin/keyring/common/system_keys_container.cc
@@ -125,7 +125,7 @@ void System_keys_container::store_or_upd
   if (is_system_key_with_version(key, system_key_id, key_version))
   {
     if (system_key_id_to_system_key.count(system_key_id) == 0) // add a new system key
-      system_key_id_to_system_key.insert(std::make_pair<std::string, System_key_adapter*>(system_key_id, new System_key_adapter(key_version, key)));
+      system_key_id_to_system_key.insert(std::make_pair(system_key_id, new System_key_adapter(key_version, key)));
     else
       update_system_key(key, system_key_id, key_version);
   }

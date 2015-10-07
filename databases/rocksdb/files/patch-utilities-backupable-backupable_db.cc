--- utilities/backupable/backupable_db.cc.orig	2015-08-31 20:23:39.000000000 +0200
+++ utilities/backupable/backupable_db.cc	2015-09-08 00:08:37.375425000 +0200
@@ -560,10 +560,10 @@ Status BackupEngineImpl::Initialize() {
       continue;
     }
     assert(backups_.find(backup_id) == backups_.end());
-    backups_.insert(std::move(
+    backups_.insert(
         std::make_pair(backup_id, unique_ptr<BackupMeta>(new BackupMeta(
                                       GetBackupMetaFile(backup_id),
-                                      &backuped_file_infos_, backup_env_)))));
+                                      &backuped_file_infos_, backup_env_))));
   }
 
   if (options_.destroy_old_data) {  // Destroy old data
@@ -701,10 +701,10 @@ Status BackupEngineImpl::CreateNewBackup
 
   BackupID new_backup_id = latest_backup_id_ + 1;
   assert(backups_.find(new_backup_id) == backups_.end());
-  auto ret = backups_.insert(std::move(
+  auto ret = backups_.insert(
       std::make_pair(new_backup_id, unique_ptr<BackupMeta>(new BackupMeta(
                                         GetBackupMetaFile(new_backup_id),
-                                        &backuped_file_infos_, backup_env_)))));
+                                        &backuped_file_infos_, backup_env_))));
   assert(ret.second == true);
   auto& new_backup = ret.first->second;
   new_backup->RecordTimestamp();

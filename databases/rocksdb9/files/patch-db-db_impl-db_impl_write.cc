Reference:	https://github.com/facebook/rocksdb/commit/1f0426c44b9416d90a90266a87d6a198b5f61627

--- db/db_impl/db_impl_write.cc.orig	2024-12-16 20:45:14 UTC
+++ db/db_impl/db_impl_write.cc
@@ -205,7 +205,7 @@ Status DBImpl::IngestWBWI(std::shared_ptr<WriteBatchWi
   ColumnFamilySet* cf_set = versions_->GetColumnFamilySet();
 
   // Create WBWIMemTables
-  for (const auto [cf_id, stat] : wbwi->GetCFStats()) {
+  for (const auto& [cf_id, stat] : wbwi->GetCFStats()) {
     ColumnFamilyData* cfd = cf_set->GetColumnFamily(cf_id);
     if (!cfd) {
       if (ignore_missing_cf) {

--- sql/binlog.cc.orig	2021-03-22 08:44:50 UTC
+++ sql/binlog.cc
@@ -9156,8 +9156,8 @@ void MYSQL_BIN_LOG::report_missing_purged_gtids(
 
   char *missing_gtids = NULL;
   char *slave_executed_gtids = NULL;
-  gtid_missing.to_string(&missing_gtids, NULL);
-  slave_executed_gtid_set->to_string(&slave_executed_gtids, NULL);
+  gtid_missing.to_string(&missing_gtids);
+  slave_executed_gtid_set->to_string(&slave_executed_gtids);
 
   /*
      Log the information about the missing purged GTIDs to the error log.
@@ -9210,8 +9210,8 @@ void MYSQL_BIN_LOG::report_missing_gtids(
   Gtid_set gtid_missing(slave_executed_gtid_set->get_sid_map());
   gtid_missing.add_gtid_set(slave_executed_gtid_set);
   gtid_missing.remove_gtid_set(previous_gtid_set);
-  gtid_missing.to_string(&missing_gtids, NULL);
-  slave_executed_gtid_set->to_string(&slave_executed_gtids, NULL);
+  gtid_missing.to_string(&missing_gtids);
+  slave_executed_gtid_set->to_string(&slave_executed_gtids);
 
   String tmp_uuid;
 

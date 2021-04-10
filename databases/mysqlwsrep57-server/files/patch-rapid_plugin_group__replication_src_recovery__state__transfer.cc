--- rapid/plugin/group_replication/src/recovery_state_transfer.cc.orig	2020-11-02 12:09:01 UTC
+++ rapid/plugin/group_replication/src/recovery_state_transfer.cc
@@ -711,6 +711,7 @@ int Recovery_state_transfer::purge_recovery_slave_thre
     donor_connection_interface.initialize_channel(const_cast<char*>("<NULL>"),
                                                   0,
                                                   NULL, NULL,
+                                                  false,
                                                   NULL,
                                                   NULL,
                                                   NULL,
@@ -718,8 +719,7 @@ int Recovery_state_transfer::purge_recovery_slave_thre
                                                   NULL,
                                                   NULL,
                                                   NULL,
-                                                  NULL,
-                                                  NULL,
+                                                  false,
                                                   DEFAULT_THREAD_PRIORITY,
                                                   1, false);
 

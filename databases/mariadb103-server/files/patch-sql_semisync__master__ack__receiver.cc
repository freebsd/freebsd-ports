diff --git a/sql/semisync_master_ack_receiver.cc b/sql/semisync_master_ack_rece>
index ac17c7de40b..fc36ee35d5d 100644
--- sql/semisync_master_ack_receiver.cc.orig
+++ sql/semisync_master_ack_receiver.cc
@@ -43,8 +43,7 @@ Ack_receiver::Ack_receiver()
   DBUG_ENTER("Ack_receiver::Ack_receiver");
 
   m_status= ST_DOWN;
-  mysql_mutex_init(key_LOCK_ack_receiver, &m_mutex,
-                   MY_MUTEX_INIT_FAST);
+  mysql_mutex_init(key_LOCK_ack_receiver, &m_mutex, NULL);
   mysql_cond_init(key_COND_ack_receiver, &m_cond, NULL);
   m_pid= 0;

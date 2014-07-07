--- plugin/innodb_memcached/innodb_memcache/src/innodb_engine.c.orig	2014-07-05 20:51:49.603580203 +0000
+++ plugin/innodb_memcached/innodb_memcache/src/innodb_engine.c	2014-07-05 21:00:01.470581456 +0000
@@ -791,6 +791,11 @@
 	read_crsr = conn_data->read_crsr;
 
 	if (lock_mode == IB_LOCK_TABLE_X) {
+		// Fixes a bug where using "flush all" would crash the server
+		if (ib_cb_trx_state(conn_data->crsr_trx) == IB_TRX_NOT_STARTED) {
+			ib_cb_trx_release(conn_data->crsr_trx);
+			conn_data->crsr_trx = NULL;
+		}
 		assert(!conn_data->crsr_trx);
 
 		conn_data->crsr_trx = ib_cb_trx_begin(

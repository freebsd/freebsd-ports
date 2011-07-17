--- BDB.xs.orig	2010-03-31 08:42:15.000000000 +0800
+++ BDB.xs	2011-06-07 12:17:51.440226550 +0800
@@ -33,8 +33,8 @@
 
 #include <db.h>
 
-#if DB_VERSION_MAJOR != 4 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR < 3)
-# error you need Berkeley DB 4.3 or a newer 4.x version installed
+#if DB_VERSION_MAJOR < 4 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR < 3)
+# error you need Berkeley DB 4.3 or a newer 4.x/5.x version installed
 #endif
 
 /* number of seconds after which idle threads exit */
@@ -52,7 +52,7 @@
 typedef DBC         DBC_ornuked;
 typedef DB          DB_ornuked;
 
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
 typedef DB_SEQUENCE DB_SEQUENCE_ornull;
 typedef DB_SEQUENCE DB_SEQUENCE_ornuked;
 #endif
@@ -69,7 +69,7 @@
   *bdb_db_stash,
   *bdb_sequence_stash;
 
-#if DB_VERSION_MINOR >= 6
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 6)
 # define c_close close 
 # define c_count count 
 # define c_del   del   
@@ -188,7 +188,7 @@
 
   DBT dbt1, dbt2, dbt3;
   DB_KEY_RANGE key_range;
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
   DB_SEQUENCE *seq;
   db_seq_t seq_t;
 #endif
@@ -399,7 +399,7 @@
         }
         break;
 
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
       case REQ_SEQ_GET:
         SvREADONLY_off (req->sv1);
 
@@ -751,7 +751,7 @@
         req->result = req->db->close (req->db, req->uint1);
         break;
 
-#if DB_VERSION_MINOR >= 4
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 4)
       case REQ_DB_COMPACT:
         req->result = req->db->compact (req->db, req->txn, req->dbt1.data ? &req->dbt1 : 0, req->dbt2.data ? &req->dbt2 : 0, 0, req->uint1, 0);
         break;
@@ -773,7 +773,7 @@
         req->result = req->db->put (req->db, req->txn, &req->dbt1, &req->dbt2, req->uint1);
         break;
 
-#if DB_VERSION_MINOR >= 6
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 6)
       case REQ_DB_EXISTS:
         req->result = req->db->exists (req->db, req->txn, &req->dbt1, req->uint1);
         break;
@@ -841,7 +841,7 @@
         req->result = req->dbc->c_del (req->dbc, req->uint1);
         break;
 
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
       case REQ_SEQ_OPEN:
         req->result = req->seq->open (req->seq, req->txn, &req->dbt1, req->uint1);
         break;
@@ -1195,7 +1195,9 @@
           IV iv;
         } *civ, const_iv[] = {
 #define const_iv(name) { # name, (IV)DB_ ## name },
+#if DB_VERSION_MAJOR == 4
           const_iv (RPCCLIENT)
+#endif
           const_iv (INIT_CDB)
           const_iv (INIT_LOCK)
           const_iv (INIT_LOG)
@@ -1228,7 +1230,7 @@
           const_iv (WRITECURSOR)
           const_iv (YIELDCPU)
           const_iv (ENCRYPT_AES)
-#if DB_VERSION_MINOR < 8
+#if DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR < 8
           const_iv (XA_CREATE)
 #endif
           const_iv (BTREE)
@@ -1346,7 +1348,7 @@
           const_iv (VERSION_PATCH)
           const_iv (LOGVERSION)
           const_iv (LOGOLDVER)
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
           const_iv (INORDER)
           const_iv (LOCK_MAXWRITE)
           const_iv (SEQ_DEC)
@@ -1356,7 +1358,7 @@
           const_iv (LOG_BUFFER_FULL)
           const_iv (VERSION_MISMATCH)
 #endif
-#if DB_VERSION_MINOR >= 4
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 4)
           const_iv (REGISTER)
           const_iv (DSYNC_DB)
           const_iv (READ_COMMITTED)
@@ -1368,11 +1370,11 @@
           const_iv (FREELIST_ONLY)
           const_iv (VERB_REGISTER)
 #endif
-#if DB_VERSION_MINOR >= 5
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 5)
           const_iv (MULTIVERSION)
           const_iv (TXN_SNAPSHOT)
 #endif
-#if DB_VERSION_MINOR >= 6
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 6)
           const_iv (PREV_DUP)
           const_iv (PRIORITY_UNCHANGED)
           const_iv (PRIORITY_VERY_LOW)
@@ -1382,7 +1384,7 @@
           const_iv (PRIORITY_VERY_HIGH)
           const_iv (IGNORE_LEASE)
 #endif
-#if DB_VERSION_MINOR >= 7
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 7)
           //const_iv (MULTIPLE_KEY)
           const_iv (LOG_DIRECT)
           const_iv (LOG_DSYNC)
@@ -1396,7 +1398,7 @@
           const_iv (DSYNC_LOG)
           const_iv (LOG_INMEMORY)
 # endif
-#if DB_VERSION_MINOR >= 8
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 8)
           const_iv (LOGVERSION_LATCHING)
 #endif
 #endif
@@ -1765,7 +1767,7 @@
         REQ_SEND;
 }
 
-#if DB_VERSION_MINOR >= 4
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 4)
 
 void
 db_compact (DB *db, DB_TXN_ornull *txn = 0, SV *start = 0, SV *stop = 0, SV *unused1 = 0, U32 flags = DB_FREE_SPACE, SV *unused2 = 0, SV *callback = 0)
@@ -1854,7 +1856,7 @@
         REQ_SEND;
 }
 
-#if DB_VERSION_MINOR >= 6
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 6)
 
 void
 db_exists (DB *db, DB_TXN_ornull *txn, SV *key, U32 flags = 0, SV *callback = 0)
@@ -2097,7 +2099,7 @@
 }
 
 
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
 
 void
 db_sequence_open (DB_SEQUENCE *seq, DB_TXN_ornull *txnid, SV *key, U32 flags = 0, SV *callback = 0)
@@ -2201,7 +2203,7 @@
 	OUTPUT:
         RETVAL
 
-#if DB_VERSION_MINOR >= 7
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 7)
 
 int set_intermediate_dir_mode (DB_ENV *env, const char *mode)
 	CODE:
@@ -2298,7 +2300,7 @@
 	OUTPUT:
         RETVAL
 
-#if DB_VERSION_MINOR >= 4
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 4)
 
 int mutex_set_max (DB_ENV *env, U32 max)
         CODE:
@@ -2335,7 +2337,7 @@
         OUTPUT:
         RETVAL
 
-#if DB_VERSION_MINOR >= 5
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 5)
 
 DB_TXN *
 cdsgroup_begin (DB_ENV *env)
@@ -2447,7 +2449,7 @@
         OUTPUT:
         RETVAL
 
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
 
 DB_SEQUENCE *
 sequence (DB *db, U32 flags = 0)
@@ -2492,7 +2494,7 @@
         if (dbc)
           dbc->c_close (dbc);
 
-#if DB_VERSION_MINOR >= 6
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 6)
 
 int set_priority (DBC *dbc, int priority)
         CODE:
@@ -2500,7 +2502,7 @@
 
 #endif
 
-#if DB_VERSION_MINOR >= 3
+#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
 
 MODULE = BDB		PACKAGE = BDB::Sequence
 

--- src/transaction.c.orig	2011-04-06 19:35:39 UTC
+++ src/transaction.c
@@ -139,7 +139,9 @@ bdb_txn_commit(int argc, VALUE *argv, VALUE obj)
     VALUE a;
     int flags;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     flags = 0;
     if (rb_scan_args(argc, argv, "01", &a) == 1) {
         flags = NUM2INT(a);
@@ -552,7 +554,9 @@ bdb_env_recover(VALUE obj)
     if (!rb_block_given_p()) {
         rb_raise(bdb_eFatal, "call out of an iterator");
     }
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetEnvDB(obj, envst);
     txnv = Data_Make_Struct(bdb_cTxn, bdb_TXN, bdb_txn_mark, bdb_txn_free, txnst);
     txnst->env = obj;
@@ -584,7 +588,9 @@ bdb_txn_discard(VALUE obj)
     bdb_TXN *txnst;
     int flags;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     flags = 0;
     GetTxnDB(obj, txnst);
 #if HAVE_ST_DB_TXN_DISCARD
@@ -761,7 +767,9 @@ bdb_env_dbremove(int argc, VALUE *argv, VALUE obj)
     bdb_TXN *txnst;
     DB_TXN *txnid;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     a = b = c = Qnil;
     file = database = NULL;
     flags = 0;
@@ -810,7 +818,9 @@ bdb_env_dbrename(int argc, VALUE *argv, VALUE obj)
     bdb_TXN *txnst;
     DB_TXN *txnid;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     a = b = c = Qnil;
     file = database = newname = NULL;
     flags = 0;

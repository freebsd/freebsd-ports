--- ext/bdb1/bdb1.c.orig	2022-05-09 10:22:04 UTC
+++ ext/bdb1/bdb1.c
@@ -733,9 +733,11 @@ bdb1_close(VALUE obj)
     VALUE opt;
     bdb1_DB *dbst;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4) {
 	rb_raise(rb_eSecurityError, "Insecure: can't close the database");
     }
+#endif
     Data_Get_Struct(obj, bdb1_DB, dbst);
     bdb1_i_close(dbst);
     return Qnil;
@@ -752,15 +754,15 @@ bdb1_s_alloc(VALUE obj)
     dbst->options |= BDB1_NOT_OPEN;
     cl = obj;
     while (cl) {
-	if (cl == bdb1_cBtree || RCLASS(cl)->m_tbl == RCLASS(bdb1_cBtree)->m_tbl) {
+	if (cl == bdb1_cBtree || rb_obj_classname(cl) == rb_class2name(bdb1_cBtree)) {
 	    dbst->type = DB_BTREE;
 	    break;
 	}
-	else if (cl == bdb1_cHash || RCLASS(cl)->m_tbl == RCLASS(bdb1_cHash)->m_tbl) {
+	else if (cl == bdb1_cHash || rb_obj_classname(cl) == rb_class2name(bdb1_cHash)) {
 	    dbst->type = DB_HASH;
 	    break;
 	}
-	else if (cl == bdb1_cRecnum || RCLASS(cl)->m_tbl == RCLASS(bdb1_cRecnum)->m_tbl) {
+	else if (cl == bdb1_cRecnum || rb_obj_classname(cl) == rb_class2name(bdb1_cRecnum)) {
 	    dbst->type = DB_RECNO;
 	    break;
 	}
@@ -878,7 +880,9 @@ bdb1_put(int argc, VALUE *argv, VALUE obj)
     int ret, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     if (rb_scan_args(argc, argv, "21", &a, &b, &c) == 3)
         flags = NUM2INT(c);
@@ -1071,7 +1075,9 @@ bdb1_del(VALUE obj, VALUE a)
     db_recno_t recno;
     volatile VALUE c = Qnil;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     if (dbst->type == DB_HASH) {
 	rb_warning("delete can give strange result with DB_HASH");
@@ -1112,7 +1118,9 @@ bdb1_delete_if(VALUE obj)
     int ret, ret1, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     INIT_RECNO(dbst, key, recno);
     DATA_ZERO(data);
@@ -1138,7 +1146,9 @@ bdb1_clear(VALUE obj)
     int ret, value, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     INIT_RECNO(dbst, key, recno);
     DATA_ZERO(data);
@@ -1536,8 +1546,10 @@ bdb1_sync(VALUE obj)
 {
     bdb1_DB *dbst;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4)
 	rb_raise(rb_eSecurityError, "Insecure: can't sync the database");
+#endif
     GetDB(obj, dbst);
     bdb1_test_error(dbst->dbp->sync(dbst->dbp, 0));
     return Qtrue;

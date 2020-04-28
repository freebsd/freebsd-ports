--- src/common.c.orig	2011-04-06 19:35:39 UTC
+++ src/common.c
@@ -1080,9 +1080,11 @@ bdb_close(int argc, VALUE *argv, VALUE obj)
     bdb_DB *dbst;
     int flags = 0;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4) {
 	rb_raise(rb_eSecurityError, "Insecure: can't close the database");
     }
+#endif
     Data_Get_Struct(obj, bdb_DB, dbst);
     if (dbst->dbp != NULL) {
 	if (rb_scan_args(argc, argv, "01", &opt)) {
@@ -1229,7 +1231,7 @@ bdb_s_new(int argc, VALUE *argv, VALUE obj)
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE v, f = argv[argc - 1];
 
-	if ((v = rb_hash_aref(f, rb_str_new2("txn"))) != RHASH(f)->ifnone) {
+	if ((v = rb_hash_lookup(f, rb_str_new2("txn"))) != Qnil) {
 	    if (!rb_obj_is_kind_of(v, bdb_cTxn)) {
 		rb_raise(bdb_eFatal, "argument of txn must be a transaction");
 	    }
@@ -1241,7 +1243,7 @@ bdb_s_new(int argc, VALUE *argv, VALUE obj)
 	    dbst->options |= envst->options & BDB_NO_THREAD;
 	    dbst->marshal = txnst->marshal;
 	}
-	else if ((v = rb_hash_aref(f, rb_str_new2("env"))) != RHASH(f)->ifnone) {
+	else if ((v = rb_hash_lookup(f, rb_str_new2("env"))) != Qnil) {
 	    if (!rb_obj_is_kind_of(v, bdb_cEnv)) {
 		rb_raise(bdb_eFatal, "argument of env must be an environnement");
 	    }
@@ -1254,11 +1256,11 @@ bdb_s_new(int argc, VALUE *argv, VALUE obj)
 #if HAVE_CONST_DB_ENCRYPT 
 	if (envst && (envst->options & BDB_ENV_ENCRYPT)) {
 	    VALUE tmp = rb_str_new2("set_flags");
-	    if ((v = rb_hash_aref(f, rb_intern("set_flags"))) != RHASH(f)->ifnone) {
+	    if ((v = rb_hash_lookup(f, rb_intern("set_flags"))) != Qnil) {
 		rb_hash_aset(f, rb_intern("set_flags"), 
 			     INT2NUM(NUM2INT(v) | DB_ENCRYPT));
 	    }
-	    else if ((v = rb_hash_aref(f, tmp)) != RHASH(f)->ifnone) {
+	    else if ((v = rb_hash_lookup(f, tmp)) != Qnil) {
 		rb_hash_aset(f, tmp, INT2NUM(NUM2INT(v) | DB_ENCRYPT));
 	    }
 	    else {
@@ -1431,15 +1433,19 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
 	dbst->options |= BDB_FEEDBACK;
     }
 #endif
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     if (flags & DB_TRUNCATE) {
 	rb_secure(2);
     }
+#endif
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (flags & DB_CREATE) {
 	rb_secure(4);
     }
     if (rb_safe_level() >= 4) {
 	flags |= DB_RDONLY;
     }
+#endif
 #if HAVE_CONST_DB_DUPSORT
     if (dbst->options & BDB_DUP_COMPARE) {
 #if HAVE_TYPE_DB_INFO
@@ -1570,10 +1576,10 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
 #endif
 	switch(dbst->type) {
 	case DB_BTREE:
-	    RBASIC(obj)->klass = bdb_cBtree;
+	    RBASIC_SET_CLASS_RAW(obj, bdb_cBtree);
 	    break;
 	case DB_HASH:
-	    RBASIC(obj)->klass = bdb_cHash;
+	    RBASIC_SET_CLASS_RAW(obj, bdb_cHash);
 	    break;
 	case DB_RECNO:
 	{
@@ -1581,17 +1587,17 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
 
 	    rb_warning("It's hard to distinguish Recnum with Recno for all versions of Berkeley DB");
 	    if ((count = bdb_is_recnum(dbst->dbp)) != -1) {
-		RBASIC(obj)->klass = bdb_cRecnum;
+		RBASIC_SET_CLASS_RAW(obj, bdb_cRecnum);
 		dbst->len = count;
 	    }
 	    else {
-		RBASIC(obj)->klass = bdb_cRecno;
+		RBASIC_SET_CLASS_RAW(obj, bdb_cRecno);
 	    }
 	    break;
 	}
 #if HAVE_CONST_DB_QUEUE
 	case DB_QUEUE:
-	    RBASIC(obj)->klass = bdb_cQueue;
+	    RBASIC_SET_CLASS_RAW(obj, bdb_cQueue);
 	    break;
 #endif
 	default:
@@ -1635,29 +1641,29 @@ bdb_s_alloc(obj)
     dbst->options = BDB_NOT_OPEN;
     cl = obj;
     while (cl) {
-	if (cl == bdb_cBtree || RCLASS(cl)->m_tbl == RCLASS(bdb_cBtree)->m_tbl) {
+	if (cl == bdb_cBtree || RCLASS_M_TBL(cl) == RCLASS_M_TBL(bdb_cBtree)) {
 	    dbst->type = DB_BTREE; 
 	    break;
 	}
-	if (cl == bdb_cRecnum || RCLASS(cl)->m_tbl == RCLASS(bdb_cRecnum)->m_tbl) {
+	if (cl == bdb_cRecnum || RCLASS_M_TBL(cl) == RCLASS_M_TBL(bdb_cRecnum)) {
 	    dbst->type = DB_RECNO; 
 	    break;
 	}
-	else if (cl == bdb_cHash || RCLASS(cl)->m_tbl == RCLASS(bdb_cHash)->m_tbl) {
+	else if (cl == bdb_cHash || RCLASS_M_TBL(cl) == RCLASS_M_TBL(bdb_cHash)) {
 	    dbst->type = DB_HASH; 
 	    break;
 	}
-	else if (cl == bdb_cRecno || RCLASS(cl)->m_tbl == RCLASS(bdb_cRecno)->m_tbl) {
+	else if (cl == bdb_cRecno || RCLASS_M_TBL(cl) == RCLASS_M_TBL(bdb_cRecno)) {
 	    dbst->type = DB_RECNO;
 	    break;
     }
 #if HAVE_CONST_DB_QUEUE
-	else if (cl == bdb_cQueue || RCLASS(cl)->m_tbl == RCLASS(bdb_cQueue)->m_tbl) {
+	else if (cl == bdb_cQueue || RCLASS_M_TBL(cl) == RCLASS_M_TBL(bdb_cQueue)) {
 	    dbst->type = DB_QUEUE;
 	    break;
 	}
 #endif
-	else if (cl == bdb_cUnknown || RCLASS(cl)->m_tbl == RCLASS(bdb_cUnknown)->m_tbl) {
+	else if (cl == bdb_cUnknown || RCLASS_M_TBL(cl) == RCLASS_M_TBL(bdb_cUnknown)) {
 	    dbst->type = DB_UNKNOWN;
 	    break;
 	}
@@ -1802,7 +1808,9 @@ bdb_append_internal(argc, argv, obj, flag, retval)
     VALUE *a, ary = Qnil;
     volatile VALUE res = Qnil;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     if (argc < 1)
 	return obj;
     INIT_TXN(txnid, obj, dbst);
@@ -1885,7 +1893,9 @@ bdb_put(int argc, VALUE *argv, VALUE obj)
     int ret, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     INIT_TXN(txnid, obj, dbst);
     flags = 0;
     a = b = c = Qnil;
@@ -2374,7 +2384,9 @@ bdb_consume(obj)
     int ret;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     INIT_TXN(txnid, obj, dbst);
     MEMZERO(&key, DBT, 1);
     MEMZERO(&data, DBT, 1);
@@ -2551,7 +2563,9 @@ bdb_del(obj, a)
     db_recno_t recno;
     volatile VALUE b = Qnil;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     INIT_TXN(txnid, obj, dbst);
 #if HAVE_CONST_DB_AUTO_COMMIT
     if (txnid == NULL && (dbst->options & BDB_AUTO_COMMIT)) {
@@ -3004,8 +3018,8 @@ bdb_each_kvc(argc, argv, obj, sens, replace, type)
 
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE g, f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_lookup(f, rb_intern("flags"))) != Qnil ||
+	    (g = rb_hash_lookup(f, rb_str_new2("flags"))) != Qnil) {
 	    flags = NUM2INT(g);
 	}
 	argc--;
@@ -3053,9 +3067,11 @@ bdb_each_kvc(argc, argv, obj, sens, replace, type)
     }
 #endif
     type &= ~BDB_ST_ONE;
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if ((type & ~BDB_ST_PREFIX) == BDB_ST_DELETE) {
 	rb_secure(4);
     }
+#endif
     INIT_TXN(txnid, obj, dbst);
 #if HAVE_DB_CURSOR_4
     bdb_test_error(dbst->dbp->cursor(dbst->dbp, txnid, &dbcp, flags));
@@ -3309,7 +3325,9 @@ bdb_clear(int argc, VALUE *argv, VALUE obj)
 #endif
     int flags = 0;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
 #if HAVE_ST_DB_TRUNCATE
     INIT_TXN(txnid, obj, dbst);
 #if HAVE_CONST_DB_AUTO_COMMIT
@@ -3323,8 +3341,8 @@ bdb_clear(int argc, VALUE *argv, VALUE obj)
     flags = 0;
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE g, f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_lookup(f, rb_intern("flags"))) != Qnil ||
+	    (g = rb_hash_lookup(f, rb_str_new2("flags"))) != Qnil) {
 	    flags = NUM2INT(g);
 	}
 	argc--;
@@ -3348,8 +3366,8 @@ bdb_replace(int argc, VALUE *argv, VALUE obj)
     flags = 0;
     if (TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_lookup(f, rb_intern("flags"))) != Qnil ||
+	    (g = rb_hash_lookup(f, rb_str_new2("flags"))) != Qnil) {
 	    flags = NUM2INT(g);
 	}
 	argc--;
@@ -3557,8 +3575,10 @@ bdb_sync(obj)
 {
     bdb_DB *dbst;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4)
 	rb_raise(rb_eSecurityError, "Insecure: can't sync the database");
+#endif
     GetDB(obj, dbst);
     bdb_test_error(dbst->dbp->sync(dbst->dbp, 0));
     return Qtrue;
@@ -3884,7 +3904,9 @@ bdb_s_upgrade(int argc, VALUE *argv, VALUE obj)
     int flags;
     VALUE val;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     flags = 0;
     if (rb_scan_args(argc, argv, "11", &a, &b) == 2) {
 	flags = NUM2INT(b);
@@ -3908,7 +3930,9 @@ bdb_s_remove(int argc, VALUE *argv, VALUE obj)
     VALUE a, b, c;
     char *name, *subname;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     c = bdb_i_create(obj);
     GetDB(c, dbst);
     name = subname = NULL;
@@ -3936,7 +3960,9 @@ bdb_s_rename(int argc, VALUE *argv, VALUE obj)
     VALUE a, b, c;
     char *name, *subname, *newname;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     c = bdb_i_create(obj);
     GetDB(c, dbst);
     name = subname = NULL;
@@ -4222,7 +4248,9 @@ bdb_verify(int argc, VALUE *argv, VALUE obj)
 #endif
     FILE *io = NULL;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     file = database = NULL;
     switch(rb_scan_args(argc, argv, "02", &iov, &flagv)) {
     case 2:

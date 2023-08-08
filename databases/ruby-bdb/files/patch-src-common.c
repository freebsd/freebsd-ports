--- src/common.c.orig	2011-04-06 19:35:39 UTC
+++ src/common.c
@@ -273,7 +273,7 @@ bdb_test_load(VALUE obj, DBT *a, int type_kv)
                 res = Qnil;
             }
             else {
-                res = rb_tainted_str_new(a->data, a->size);
+                res = rb_str_new(a->data, a->size);
                 if (dbst->filter[2 + posi]) {
                     if (FIXNUM_P(dbst->filter[2 + posi])) {
                         res = rb_funcall(obj, NUM2INT(dbst->filter[2 + posi]),
@@ -494,7 +494,7 @@ bdb_h_hash(DB *dbbd, const void *bytes, u_int32_t leng
 #endif
 
     GetIdDbSec(obj, dbst, dbbd);
-    st = rb_tainted_str_new((char *)bytes, length);
+    st = rb_str_new((char *)bytes, length);
     if (dbst->h_hash == 0)
 	res = rb_funcall(obj, id_h_hash, 1, st);
     else
@@ -603,7 +603,7 @@ compar_func(VALUE value)
 }
 
 static VALUE
-bdb_i_options(VALUE obj, VALUE dbstobj)
+bdb_i_options(VALUE obj, VALUE dbstobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     char *options, *str;
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
@@ -1140,8 +1142,7 @@ bdb_hard_count(dbp)
 #endif
 
 static long
-bdb_is_recnum(dbp)
-    DB *dbp;
+bdb_is_recnum(DB *dbp)
 {
     DB_BTREE_STAT *bdb_stat;
     long count;
@@ -1172,8 +1173,7 @@ bdb_is_recnum(dbp)
 }
 
 static VALUE
-bdb_recno_length(obj)
-    VALUE obj;
+bdb_recno_length(VALUE obj)
 {
     bdb_DB *dbst;
     DB_BTREE_STAT *bdb_stat;
@@ -1229,7 +1229,7 @@ bdb_s_new(int argc, VALUE *argv, VALUE obj)
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE v, f = argv[argc - 1];
 
-	if ((v = rb_hash_aref(f, rb_str_new2("txn"))) != RHASH(f)->ifnone) {
+	if ((v = rb_hash_lookup(f, rb_str_new2("txn"))) != Qnil) {
 	    if (!rb_obj_is_kind_of(v, bdb_cTxn)) {
 		rb_raise(bdb_eFatal, "argument of txn must be a transaction");
 	    }
@@ -1241,7 +1241,7 @@ bdb_s_new(int argc, VALUE *argv, VALUE obj)
 	    dbst->options |= envst->options & BDB_NO_THREAD;
 	    dbst->marshal = txnst->marshal;
 	}
-	else if ((v = rb_hash_aref(f, rb_str_new2("env"))) != RHASH(f)->ifnone) {
+	else if ((v = rb_hash_lookup(f, rb_str_new2("env"))) != Qnil) {
 	    if (!rb_obj_is_kind_of(v, bdb_cEnv)) {
 		rb_raise(bdb_eFatal, "argument of env must be an environnement");
 	    }
@@ -1254,11 +1254,11 @@ bdb_s_new(int argc, VALUE *argv, VALUE obj)
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
@@ -1338,7 +1338,7 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
 #endif
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	hash_arg = argv[argc - 1];
-	rb_iterate(rb_each, argv[argc - 1], bdb_i_options, obj);
+	rb_block_call(argv[argc - 1], rb_intern("each"), 0, NULL, bdb_i_options, obj);
         argc--;
     }
     mode = flags = 0;
@@ -1431,15 +1431,19 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
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
@@ -1540,12 +1544,12 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
     }
     dbst->filename = dbst->database = Qnil;
     if (name) {
-	dbst->filename = rb_tainted_str_new2(name);
+	dbst->filename = rb_str_new_cstr(name);
 	OBJ_FREEZE(dbst->filename);
     }
 #if HAVE_ST_DB_OPEN
     if (subname) {
-	dbst->database = rb_tainted_str_new2(subname);
+	dbst->database = rb_str_new_cstr(subname);
 	OBJ_FREEZE(dbst->database);
     }
 #endif
@@ -1570,10 +1574,10 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
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
@@ -1581,17 +1585,17 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
 
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
@@ -1625,8 +1629,7 @@ bdb_init(int argc, VALUE *argv, VALUE obj)
 }
 
 static VALUE
-bdb_s_alloc(obj)
-    VALUE obj;
+bdb_s_alloc(VALUE obj)
 {
     VALUE res, cl;
     bdb_DB *dbst;
@@ -1635,29 +1638,29 @@ bdb_s_alloc(obj)
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
@@ -1671,8 +1674,7 @@ bdb_s_alloc(obj)
 }
 
 static VALUE
-bdb_i_s_create(obj, db)
-    VALUE obj, db;
+bdb_i_s_create(VALUE obj, VALUE db, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE tmp[2];
     tmp[0] = rb_ary_entry(obj, 0);
@@ -1689,7 +1691,7 @@ bdb_s_create(int argc, VALUE *argv, VALUE obj)
 
     res = rb_funcall2(obj, rb_intern("new"), 0, 0);
     if (argc == 1 && TYPE(argv[0]) == T_HASH) {
-	rb_iterate(rb_each, argv[0], bdb_i_s_create, res);
+	rb_block_call(argv[0], rb_intern("each"), 0, NULL, bdb_i_s_create, res);
 	return res;
     }
     if (argc % 2 != 0) {
@@ -1718,8 +1720,7 @@ struct re {
 };
 
 static VALUE
-bdb_queue_i_search_re_len(obj, restobj)
-    VALUE obj, restobj;
+bdb_queue_i_search_re_len(VALUE obj, VALUE restobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     char *str;
@@ -1760,14 +1761,14 @@ bdb_queue_s_new(int argc, VALUE *argv, VALUE obj) 
     rest->re_len = -1;
     rest->re_pad = -1;
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
-	rb_iterate(rb_each, argv[argc - 1], bdb_queue_i_search_re_len, restobj);
+	rb_block_call(argv[argc - 1], rb_intern("each"), 0, NULL, bdb_queue_i_search_re_len, restobj);
 	if (rest->re_len <= 0) {
 	    rest->re_len = DEFAULT_RECORD_LENGTH;
-	    rb_hash_aset(argv[argc - 1], rb_tainted_str_new2("set_re_len"), INT2NUM(rest->re_len));
+	    rb_hash_aset(argv[argc - 1], rb_str_new_cstr("set_re_len"), INT2NUM(rest->re_len));
 	}
 	if (rest->re_pad < 0) {
 	    rest->re_pad = DEFAULT_RECORD_PAD;
-	    rb_hash_aset(argv[argc - 1], rb_tainted_str_new2("set_re_pad"), INT2NUM(rest->re_pad));
+	    rb_hash_aset(argv[argc - 1], rb_str_new_cstr("set_re_pad"), INT2NUM(rest->re_pad));
 	}
 	nargv = argv;
     }
@@ -1777,8 +1778,8 @@ bdb_queue_s_new(int argc, VALUE *argv, VALUE obj) 
 	nargv[argc] = rb_hash_new();
 	rest->re_len = DEFAULT_RECORD_LENGTH;
 	rest->re_pad = DEFAULT_RECORD_PAD;
-	rb_hash_aset(nargv[argc], rb_tainted_str_new2("set_re_len"), INT2NUM(DEFAULT_RECORD_LENGTH));
-	rb_hash_aset(nargv[argc], rb_tainted_str_new2("set_re_pad"), INT2NUM(DEFAULT_RECORD_PAD));
+	rb_hash_aset(nargv[argc], rb_str_new_cstr("set_re_len"), INT2NUM(DEFAULT_RECORD_LENGTH));
+	rb_hash_aset(nargv[argc], rb_str_new_cstr("set_re_pad"), INT2NUM(DEFAULT_RECORD_PAD));
 	argc += 1;
     }
     ret = bdb_s_new(argc, nargv, obj);
@@ -1790,9 +1791,7 @@ bdb_queue_s_new(int argc, VALUE *argv, VALUE obj) 
 #endif
 
 static VALUE
-bdb_append_internal(argc, argv, obj, flag, retval)
-    int argc, flag;
-    VALUE *argv, obj;
+bdb_append_internal(int argc, VALUE *argv, VALUE obj, int flag, retval)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -1800,9 +1799,11 @@ bdb_append_internal(argc, argv, obj, flag, retval)
     db_recno_t recno;
     int i;
     VALUE *a, ary = Qnil;
-    volatile VALUE res = Qnil;
+    volatile VALUE res;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     if (argc < 1)
 	return obj;
     INIT_TXN(txnid, obj, dbst);
@@ -1876,7 +1877,7 @@ bdb_unshift(int argc, VALUE *argv, VALUE obj)
 VALUE
 bdb_put(int argc, VALUE *argv, VALUE obj)
 {
-    volatile VALUE a0 = Qnil;
+    volatile VALUE a0;
     volatile VALUE b0 = Qnil;
     VALUE a, b, c;
     bdb_DB *dbst;
@@ -1885,7 +1886,9 @@ bdb_put(int argc, VALUE *argv, VALUE obj)
     int ret, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     INIT_TXN(txnid, obj, dbst);
     flags = 0;
     a = b = c = Qnil;
@@ -1924,8 +1927,7 @@ bdb_put(int argc, VALUE *argv, VALUE obj)
 }
 
 static VALUE
-bdb_aset(obj, a, b)
-    VALUE obj, a, b;
+bdb_aset(VALUE obj, VALUE a, VALUE b)
 {
     VALUE tmp[2];
     tmp[0] = a;
@@ -1935,9 +1937,7 @@ bdb_aset(obj, a, b)
 }
 
 VALUE
-bdb_test_load_key(obj, key)
-    VALUE obj;
-    DBT *key;
+bdb_test_load_key(VALUE obj, DBT *key)
 {
     bdb_DB *dbst;
     Data_Get_Struct(obj, bdb_DB, dbst);
@@ -1947,18 +1947,14 @@ bdb_test_load_key(obj, key)
 }
 
 VALUE
-bdb_assoc(obj, key, data)
-    VALUE obj;
-    DBT *key, *data;
+bdb_assoc(VALUE obj, DBT *key, DBT *data)
 {
     return rb_assoc_new(bdb_test_load_key(obj, key), 
 			bdb_test_load(obj, data, FILTER_VALUE));
 }
 
 VALUE
-bdb_assoc_dyna(obj, key, data)
-    VALUE obj;
-    DBT *key, *data;
+bdb_assoc_dyna(VALUE obj, DBT *key, DBT *data)
 {
     VALUE k, v;
     int to_free = key->flags & DB_DBT_MALLOC;
@@ -1976,9 +1972,7 @@ bdb_assoc_dyna(obj, key, data)
 #if HAVE_ST_DB_PGET
 
 static VALUE
-bdb_assoc2(obj, skey, pkey, data)
-    VALUE obj;
-    DBT *skey, *pkey, *data;
+bdb_assoc2(VALUE obj, DBT *skey, DBT *pkey, DBT *data)
 {
     return rb_assoc_new(
 	rb_assoc_new(bdb_test_load_key(obj, skey), bdb_test_load_key(obj, pkey)),
@@ -1988,9 +1982,7 @@ bdb_assoc2(obj, skey, pkey, data)
 #endif
 
 VALUE
-bdb_assoc3(obj, skey, pkey, data)
-    VALUE obj;
-    DBT *skey, *pkey, *data;
+bdb_assoc3(VALUE obj, DBT *skey, DBT *pkey, DBT *data)
 {
     return rb_ary_new3(3, bdb_test_load_key(obj, skey), 
 		       bdb_test_load_key(obj, pkey),
@@ -2006,12 +1998,7 @@ static VALUE bdb_has_both_internal _((VALUE, VALUE, VA
 #endif
 
 static VALUE
-bdb_get_internal(argc, argv, obj, notfound, dyna)
-    int argc;
-    VALUE *argv;
-    VALUE obj;
-    VALUE notfound;
-    int dyna;
+bdb_get_internal(int argc, VALUE *argv, VALUE obj, VALUE notfound, int dyna)
 {
     VALUE a = Qnil;
     VALUE b = Qnil;
@@ -2019,13 +2006,12 @@ bdb_get_internal(argc, argv, obj, notfound, dyna)
     bdb_DB *dbst;
     DB_TXN *txnid;
     DBT key, data;
-    int flagss;
     int ret, flags;
     db_recno_t recno;
     void *tmp_data = 0;
 
     INIT_TXN(txnid, obj, dbst);
-    flagss = flags = 0;
+    flags = 0;
     MEMZERO(&key, DBT, 1);
     MEMZERO(&data, DBT, 1);
     data.flags |= DB_DBT_MALLOC;
@@ -2043,7 +2029,7 @@ bdb_get_internal(argc, argv, obj, notfound, dyna)
         }
 	break;
     case 2:
-	flagss = flags = NUM2INT(b);
+	flags = NUM2INT(b);
 	break;
     }
     a = bdb_test_recno(obj, &key, &recno, a);
@@ -2128,13 +2114,12 @@ bdb_pget(int argc, VALUE *argv, VALUE obj)
     bdb_DB *dbst;
     DB_TXN *txnid;
     DBT pkey, data, skey;
-    int flagss;
     int ret, flags;
     db_recno_t srecno;
     void *tmp_data = 0;
 
     INIT_TXN(txnid, obj, dbst);
-    flagss = flags = 0;
+    flags = 0;
     MEMZERO(&skey, DBT, 1);
     MEMZERO(&pkey, DBT, 1);
     MEMZERO(&data, DBT, 1);
@@ -2150,7 +2135,7 @@ bdb_pget(int argc, VALUE *argv, VALUE obj)
         }
 	break;
     case 2:
-	flagss = flags = NUM2INT(b);
+	flags = NUM2INT(b);
 	break;
     }
     a = bdb_test_recno(obj, &skey, &srecno, a);
@@ -2174,15 +2159,14 @@ bdb_pget(int argc, VALUE *argv, VALUE obj)
 #if HAVE_TYPE_DB_KEY_RANGE
 
 static VALUE
-bdb_btree_key_range(obj, a)
-    VALUE obj, a;
+bdb_btree_key_range(VALUE obj, VALUE a)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
     DBT key;
     db_recno_t recno;
     DB_KEY_RANGE key_range;
-    volatile VALUE b = Qnil;
+    volatile VALUE b;
 
     INIT_TXN(txnid, obj, dbst);
     MEMZERO(&key, DBT, 1);
@@ -2203,8 +2187,7 @@ struct data_flags {
 };
 
 static VALUE
-bdb_compact_i(obj, dataobj)
-    VALUE obj, dataobj;
+bdb_compact_i(VALUE obj, VALUE dataobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     char *str;
@@ -2255,10 +2238,10 @@ bdb_treerec_compact(int argc, VALUE *argv, VALUE obj)
 	    struct data_flags *dtf;
 	    VALUE dtobj;
 		
-	    dtobj = Data_Make_Struct(rb_cData, struct data_flags, 0, free, dtf);
+	    dtobj = Data_Make_Struct(rb_cObject, struct data_flags, 0, free, dtf);
 	    dtf->cdata = &cdata;
 	    dtf->flags = 0;
-	    rb_iterate(rb_each, c, bdb_compact_i, dtobj);
+	    rb_block_call(c, rb_intern("each"), 0, NULL, bdb_compact_i, dtobj);
 	    flags = dtf->flags;
 	}
 	/* ... */
@@ -2280,16 +2263,16 @@ bdb_treerec_compact(int argc, VALUE *argv, VALUE obj)
     bdb_test_error(dbst->dbp->compact(dbst->dbp, txnid, pstart, pstop, &cdata,
 				      flags, &end));
     result = rb_hash_new();
-    rb_hash_aset(result, rb_tainted_str_new2("end"), bdb_test_load_key(obj, &end));
-    rb_hash_aset(result, rb_tainted_str_new2("compact_deadlock"),
+    rb_hash_aset(result, rb_str_new_cstr("end"), bdb_test_load_key(obj, &end));
+    rb_hash_aset(result, rb_str_new_cstr("compact_deadlock"),
 		 INT2NUM(cdata.compact_deadlock));
-    rb_hash_aset(result, rb_tainted_str_new2("compact_levels"),
+    rb_hash_aset(result, rb_str_new_cstr("compact_levels"),
 		 INT2NUM(cdata.compact_levels));
-    rb_hash_aset(result, rb_tainted_str_new2("compact_pages_free"),
+    rb_hash_aset(result, rb_str_new_cstr("compact_pages_free"),
 		 INT2NUM(cdata.compact_pages_free));
-    rb_hash_aset(result, rb_tainted_str_new2("compact_pages_examine"),
+    rb_hash_aset(result, rb_str_new_cstr("compact_pages_examine"),
 		 INT2NUM(cdata.compact_pages_examine));
-    rb_hash_aset(result, rb_tainted_str_new2("compact_pages_truncated"),
+    rb_hash_aset(result, rb_str_new_cstr("compact_pages_truncated"),
 		 INT2NUM(cdata.compact_pages_truncated));
     return result;
 }
@@ -2301,8 +2284,7 @@ bdb_treerec_compact(int argc, VALUE *argv, VALUE obj)
 #if HAVE_CONST_DB_NEXT_DUP
 
 static VALUE
-bdb_count(obj, a)
-    VALUE obj, a;
+bdb_count(VALUE obj, VALUE a)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -2311,7 +2293,7 @@ bdb_count(obj, a)
     int ret, flags27;
     db_recno_t recno;
     db_recno_t count;
-    volatile VALUE b = Qnil;
+    volatile VALUE b;
 
     INIT_TXN(txnid, obj, dbst);
     MEMZERO(&key, DBT, 1);
@@ -2364,8 +2346,7 @@ bdb_count(obj, a)
 #if HAVE_CONST_DB_CONSUME
 
 static VALUE
-bdb_consume(obj)
-    VALUE obj;
+bdb_consume(VALUE obj)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -2374,7 +2355,9 @@ bdb_consume(obj)
     int ret;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     INIT_TXN(txnid, obj, dbst);
     MEMZERO(&key, DBT, 1);
     MEMZERO(&data, DBT, 1);
@@ -2396,8 +2379,7 @@ bdb_consume(obj)
 #endif
 
 static VALUE
-bdb_has_key(obj, key)
-    VALUE obj, key;
+bdb_has_key(VALUE obj, VALUE key)
 {
     return (bdb_get_internal(1, &key, obj, Qundef, 0) == Qundef)?Qfalse:Qtrue;
 }
@@ -2405,8 +2387,7 @@ bdb_has_key(obj, key)
 #if CANT_DB_CURSOR_GET_BOTH
 
 static VALUE
-bdb_has_both_internal(obj, a, b, flag)
-    VALUE obj, a, b, flag;
+bdb_has_both_internal(VALUE obj, VALUE a, VALUE b, VALUE flag)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -2491,8 +2472,7 @@ bdb_has_both_internal(obj, a, b, flag)
 #endif
 
 static VALUE
-bdb_has_both(obj, a, b)
-    VALUE obj, a, b;
+bdb_has_both(VALUE obj, VALUE a, VALUE b)
 {
 #if ! HAVE_CONST_DB_GET_BOTH
     return bdb_has_both_internal(obj, a, b, Qfalse);
@@ -2502,8 +2482,8 @@ bdb_has_both(obj, a, b)
     DBT key, data;
     int ret, flags;
     db_recno_t recno;
-    volatile VALUE c = Qnil;
-    volatile VALUE d = Qnil;
+    volatile VALUE c;
+    volatile VALUE d;
     void *tmp_key, *tmp_data;
 
     INIT_TXN(txnid, obj, dbst);
@@ -2540,8 +2520,7 @@ bdb_has_both(obj, a, b)
 }
 
 VALUE
-bdb_del(obj, a)
-    VALUE a, obj;
+bdb_del(VALUE obj, VALUE a)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -2549,9 +2528,11 @@ bdb_del(obj, a)
     DBT key;
     int ret;
     db_recno_t recno;
-    volatile VALUE b = Qnil;
+    volatile VALUE b;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     INIT_TXN(txnid, obj, dbst);
 #if HAVE_CONST_DB_AUTO_COMMIT
     if (txnid == NULL && (dbst->options & BDB_AUTO_COMMIT)) {
@@ -2568,8 +2549,7 @@ bdb_del(obj, a)
 }
 
 static VALUE
-bdb_empty(obj)
-    VALUE obj;
+bdb_empty(VALUE obj)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -2603,8 +2583,7 @@ bdb_empty(obj)
 }
 
 static VALUE
-bdb_lgth_intern(obj, delete)
-    VALUE obj, delete;
+bdb_lgth_intern(VALUE obj, VALUE delete)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -2646,8 +2625,7 @@ bdb_lgth_intern(obj, delete)
 }
 
 static VALUE
-bdb_length(obj)
-    VALUE obj;
+bdb_length(VALUE obj)
 {
     return bdb_lgth_intern(obj, Qfalse);
 }
@@ -2667,10 +2645,10 @@ typedef struct {
 } eachst;
 
 static VALUE
-bdb_each_ensure(st)
-    eachst *st;
+bdb_each_ensure(VALUE pst)
 {
 #if HAVE_CONST_DB_MULTIPLE_KEY
+    eachst *st = (eachst *)pst;
     if (st->len && st->data) {
 	free(st->data);
     }
@@ -2680,9 +2658,7 @@ bdb_each_ensure(st)
 }
 
 static void
-bdb_treat(st, pkey, key, data)
-    eachst *st;
-    DBT *pkey, *key, *data;
+bdb_treat(eachst *st, DBT *pkey, DBT *key, DBT *data)
 {
     bdb_DB *dbst;
     DBC *dbcp;
@@ -2772,10 +2748,7 @@ bdb_treat(st, pkey, key, data)
 }
 
 static int
-bdb_i_last_prefix(dbcp, key, pkey, data, orig, st)
-    DBC *dbcp;
-    DBT *key, *pkey, *data, *orig;
-    eachst *st;
+bdb_i_last_prefix(DBC *dbcp, DBT *key, DBT *pkey, DBT *data, DBT *orig, eachst *st)
 {
     int ret, flags = DB_LAST;
 
@@ -2811,15 +2784,14 @@ bdb_i_last_prefix(dbcp, key, pkey, data, orig, st)
 }
 
 static VALUE
-bdb_i_each_kv(st)
-    eachst *st;
+bdb_i_each_kv(VALUE pst)
 {
+    eachst *st = (eachst *)pst;
     bdb_DB *dbst;
     DBC *dbcp;
     DBT pkey, key, data, orig;
     int ret, init = Qfalse, prefix = Qfalse;
     db_recno_t recno;
-    volatile VALUE res = Qnil;
     
     prefix = st->type & BDB_ST_PREFIX;
     st->type &= ~BDB_ST_PREFIX;
@@ -2834,7 +2806,7 @@ bdb_i_each_kv(st)
     MEMZERO(&pkey, DBT, 1);
     pkey.flags = DB_DBT_MALLOC;
     if (!NIL_P(st->set)) {
-	res = bdb_test_recno(st->db, &key, &recno, st->set);
+	bdb_test_recno(st->db, &key, &recno, st->set);
         if (prefix) {
             init = Qtrue;
             orig.size = key.size;
@@ -2929,9 +2901,9 @@ bdb_i_each_kv(st)
 #if HAVE_CONST_DB_MULTIPLE_KEY
 
 static VALUE
-bdb_i_each_kv_bulk(st)
-    eachst *st;
+bdb_i_each_kv_bulk(VALUE pst)
 {
+    eachst *st = (eachst *)pst;
     bdb_DB *dbst;
     DBC *dbcp;
     DBT key, data;
@@ -2940,7 +2912,6 @@ bdb_i_each_kv_bulk(st)
     int ret, init;
     db_recno_t recno;
     void *p;
-    volatile VALUE res = Qnil;
     
     GetDB(st->db, dbst);
     dbcp = st->dbcp;
@@ -2958,7 +2929,7 @@ bdb_i_each_kv_bulk(st)
     init = 1;
     do {
 	if (init && !NIL_P(st->set)) {
-	    res = bdb_test_recno(st->db, &key, &recno, st->set);
+	    bdb_test_recno(st->db, &key, &recno, st->set);
 	    ret = bdb_test_error(dbcp->c_get(dbcp, &key, &data, 
                                              ((st->type & BDB_ST_DUP)?DB_SET:
                                               DB_SET_RANGE)|DB_MULTIPLE_KEY));
@@ -2990,11 +2961,7 @@ bdb_i_each_kv_bulk(st)
 #endif
 
 VALUE
-bdb_each_kvc(argc, argv, obj, sens, replace, type)
-    VALUE obj, *argv;
-    int argc, sens;
-    VALUE replace;
-    int type;
+bdb_each_kvc(int argc, VALUE *argv, VALUE obj, int sens, VALUE replace, int type)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -3004,8 +2971,8 @@ bdb_each_kvc(argc, argv, obj, sens, replace, type)
 
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE g, f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_lookup(f, rb_intern("flags"))) != Qnil ||
+	    (g = rb_hash_lookup(f, rb_str_new2("flags"))) != Qnil) {
 	    flags = NUM2INT(g);
 	}
 	argc--;
@@ -3053,9 +3020,11 @@ bdb_each_kvc(argc, argv, obj, sens, replace, type)
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
@@ -3211,8 +3180,7 @@ bdb_each_riap_prim(int argc, VALUE *argv, VALUE obj) 
 }
 
 VALUE
-bdb_to_type(obj, result, flag)
-    VALUE obj, result, flag;
+bdb_to_type(VALUE obj, VALUE result, VALUE flag)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -3266,15 +3234,13 @@ bdb_to_type(obj, result, flag)
 }
 
 static VALUE
-bdb_to_a(obj)
-    VALUE obj;
+bdb_to_a(VALUE obj)
 {
     return bdb_to_type(obj, rb_ary_new(), Qtrue);
 }
 
 static VALUE
-bdb_update_i(pair, obj)
-    VALUE pair, obj;
+bdb_update_i(VALUE pair, VALUE obj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     Check_Type(pair, T_ARRAY);
     if (RARRAY_LEN(pair) < 2) {
@@ -3285,17 +3251,15 @@ bdb_update_i(pair, obj)
 }
 
 static VALUE
-each_pair(obj)
-    VALUE obj;
+each_pair(VALUE obj)
 {
     return rb_funcall(obj, rb_intern("each_pair"), 0, 0);
 }
 
 static VALUE
-bdb_update(obj, other)
-    VALUE obj, other;
+bdb_update(VALUE obj, VALUE other)
 {
-    rb_iterate(each_pair, other, bdb_update_i, obj);
+    rb_block_call(other, each_pair, 0, NULL, bdb_update_i, obj);
     return obj;
 }
 
@@ -3309,7 +3273,9 @@ bdb_clear(int argc, VALUE *argv, VALUE obj)
 #endif
     int flags = 0;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
 #if HAVE_ST_DB_TRUNCATE
     INIT_TXN(txnid, obj, dbst);
 #if HAVE_CONST_DB_AUTO_COMMIT
@@ -3323,8 +3289,8 @@ bdb_clear(int argc, VALUE *argv, VALUE obj)
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
@@ -3348,8 +3314,8 @@ bdb_replace(int argc, VALUE *argv, VALUE obj)
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
@@ -3359,28 +3325,24 @@ bdb_replace(int argc, VALUE *argv, VALUE obj)
     }
     g = INT2FIX(flags);
     bdb_clear(1, &g, obj);
-    rb_iterate(each_pair, argv[0], bdb_update_i, obj);
+    rb_block_call(argv[0], rb_intern("each_pair"), 0, NULL, bdb_update_i, obj);
     return obj;
 }
 
 static VALUE
-bdb_invert(obj)
-    VALUE obj;
+bdb_invert(VALUE obj)
 {
     return bdb_to_type(obj, rb_hash_new(), Qfalse);
 }
 
 static VALUE
-bdb_to_hash(obj)
-    VALUE obj;
+bdb_to_hash(VALUE obj)
 {
     return bdb_to_type(obj, rb_hash_new(), Qtrue);
 }
  
 static VALUE
-bdb_kv(obj, type)
-    VALUE obj;
-    int type;
+bdb_kv(VALUE obj, int type)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -3426,23 +3388,19 @@ bdb_kv(obj, type)
 }
 
 static VALUE
-bdb_values(obj)
-    VALUE obj;
+bdb_values(VALUE obj)
 {
     return bdb_kv(obj, BDB_ST_VALUE);
 }
 
 static VALUE
-bdb_keys(obj)
-    VALUE obj;
+bdb_keys(VALUE obj)
 {
     return bdb_kv(obj, BDB_ST_KEY);
 }
 
 VALUE
-bdb_internal_value(obj, a, b, sens)
-    VALUE obj, a, b;
-    int sens;
+bdb_internal_value(VALUE obj, VALUE a, VALUE b, int sens)
 {
     bdb_DB *dbst;
     DB_TXN *txnid;
@@ -3490,8 +3448,7 @@ bdb_internal_value(obj, a, b, sens)
 }
 
 VALUE
-bdb_index(obj, a)
-    VALUE obj, a;
+bdb_index(VALUE obj, VALUE a)
 {
     return bdb_internal_value(obj, a, Qtrue, DB_NEXT);
 }
@@ -3545,20 +3502,20 @@ bdb_select(int argc, VALUE *argv, VALUE obj)
 }
 
 VALUE
-bdb_has_value(obj, a)
-    VALUE obj, a;
+bdb_has_value(VALUE obj, VALUE a)
 {
     return bdb_internal_value(obj, a, Qfalse, DB_NEXT);
 }
 
 static VALUE
-bdb_sync(obj)
-    VALUE obj;
+bdb_sync(VALUE obj)
 {
     bdb_DB *dbst;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4)
 	rb_raise(rb_eSecurityError, "Insecure: can't sync the database");
+#endif
     GetDB(obj, dbst);
     bdb_test_error(dbst->dbp->sync(dbst->dbp, 0));
     return Qtrue;
@@ -3597,36 +3554,36 @@ bdb_hash_stat(int argc, VALUE *argv, VALUE obj)
     bdb_test_error(dbst->dbp->stat(dbst->dbp, &bdb_stat, flags));
 #endif
     hash = rb_hash_new();
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_magic"), INT2NUM(bdb_stat->hash_magic));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_version"), INT2NUM(bdb_stat->hash_version));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_pagesize"), INT2NUM(bdb_stat->hash_pagesize));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_magic"), INT2NUM(bdb_stat->hash_magic));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_version"), INT2NUM(bdb_stat->hash_version));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_pagesize"), INT2NUM(bdb_stat->hash_pagesize));
 #if HAVE_ST_DB_HASH_STAT_HASH_NKEYS
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_nkeys"), INT2NUM(bdb_stat->hash_nkeys));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_nkeys"), INT2NUM(bdb_stat->hash_nkeys));
 #if ! HAVE_ST_DB_HASH_STAT_HASH_NRECS
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_nrecs"), INT2NUM(bdb_stat->hash_nkeys));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_nrecs"), INT2NUM(bdb_stat->hash_nkeys));
 #endif
 #endif
 #if HAVE_ST_DB_HASH_STAT_HASH_NRECS
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_nrecs"), INT2NUM(bdb_stat->hash_nrecs));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_nrecs"), INT2NUM(bdb_stat->hash_nrecs));
 #endif
 #if HAVE_ST_DB_HASH_STAT_HASH_NDATA
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_ndata"), INT2NUM(bdb_stat->hash_ndata));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_ndata"), INT2NUM(bdb_stat->hash_ndata));
 #endif
 #if HAVE_ST_DB_HASH_STAT_HASH_NELEM
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_nelem"), INT2NUM(bdb_stat->hash_nelem));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_nelem"), INT2NUM(bdb_stat->hash_nelem));
 #endif
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_ffactor"), INT2NUM(bdb_stat->hash_ffactor));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_buckets"), INT2NUM(bdb_stat->hash_buckets));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_free"), INT2NUM(bdb_stat->hash_free));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_bfree"), INT2NUM(bdb_stat->hash_bfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_bigpages"), INT2NUM(bdb_stat->hash_bigpages));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_big_bfree"), INT2NUM(bdb_stat->hash_big_bfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_overflows"), INT2NUM(bdb_stat->hash_overflows));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_ovfl_free"), INT2NUM(bdb_stat->hash_ovfl_free));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_dup"), INT2NUM(bdb_stat->hash_dup));
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_dup_free"), INT2NUM(bdb_stat->hash_dup_free));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_ffactor"), INT2NUM(bdb_stat->hash_ffactor));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_buckets"), INT2NUM(bdb_stat->hash_buckets));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_free"), INT2NUM(bdb_stat->hash_free));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_bfree"), INT2NUM(bdb_stat->hash_bfree));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_bigpages"), INT2NUM(bdb_stat->hash_bigpages));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_big_bfree"), INT2NUM(bdb_stat->hash_big_bfree));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_overflows"), INT2NUM(bdb_stat->hash_overflows));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_ovfl_free"), INT2NUM(bdb_stat->hash_ovfl_free));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_dup"), INT2NUM(bdb_stat->hash_dup));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_dup_free"), INT2NUM(bdb_stat->hash_dup_free));
 #if HAVE_ST_DB_HASH_STAT_HASH_PAGECNT
-    rb_hash_aset(hash, rb_tainted_str_new2("hash_pagecnt"), INT2NUM(bdb_stat->hash_pagecnt));
+    rb_hash_aset(hash, rb_str_new_cstr("hash_pagecnt"), INT2NUM(bdb_stat->hash_pagecnt));
 #endif
     free(bdb_stat);
     return hash;
@@ -3666,37 +3623,37 @@ bdb_tree_stat(int argc, VALUE *argv, VALUE obj)
     bdb_test_error(dbst->dbp->stat(dbst->dbp, &bdb_stat, flags));
 #endif
     hash = rb_hash_new();
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_magic"), INT2NUM(bdb_stat->bt_magic));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_version"), INT2NUM(bdb_stat->bt_version));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_dup_pg"), INT2NUM(bdb_stat->bt_dup_pg));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_dup_pgfree"), INT2NUM(bdb_stat->bt_dup_pgfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_free"), INT2NUM(bdb_stat->bt_free));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_int_pg"), INT2NUM(bdb_stat->bt_int_pg));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_int_pgfree"), INT2NUM(bdb_stat->bt_int_pgfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_leaf_pg"), INT2NUM(bdb_stat->bt_leaf_pg));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_leaf_pgfree"), INT2NUM(bdb_stat->bt_leaf_pgfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_levels"), INT2NUM(bdb_stat->bt_levels));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_minkey"), INT2NUM(bdb_stat->bt_minkey));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_magic"), INT2NUM(bdb_stat->bt_magic));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_version"), INT2NUM(bdb_stat->bt_version));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_dup_pg"), INT2NUM(bdb_stat->bt_dup_pg));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_dup_pgfree"), INT2NUM(bdb_stat->bt_dup_pgfree));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_free"), INT2NUM(bdb_stat->bt_free));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_int_pg"), INT2NUM(bdb_stat->bt_int_pg));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_int_pgfree"), INT2NUM(bdb_stat->bt_int_pgfree));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_leaf_pg"), INT2NUM(bdb_stat->bt_leaf_pg));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_leaf_pgfree"), INT2NUM(bdb_stat->bt_leaf_pgfree));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_levels"), INT2NUM(bdb_stat->bt_levels));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_minkey"), INT2NUM(bdb_stat->bt_minkey));
 #if HAVE_ST_DB_BTREE_STAT_BT_NRECS
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_nrecs"), INT2NUM(bdb_stat->bt_nrecs));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_nrecs"), INT2NUM(bdb_stat->bt_nrecs));
 #endif
 #if HAVE_ST_DB_BTREE_STAT_BT_NKEYS
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_nkeys"), INT2NUM(bdb_stat->bt_nkeys));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_nkeys"), INT2NUM(bdb_stat->bt_nkeys));
 #if ! HAVE_ST_DB_BTREE_STAT_BT_NRECS
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_nrecs"), INT2NUM(bdb_stat->bt_nkeys));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_nrecs"), INT2NUM(bdb_stat->bt_nkeys));
 #endif
 #endif
 #if HAVE_ST_DB_BTREE_STAT_BT_NDATA
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_ndata"), INT2NUM(bdb_stat->bt_ndata));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_ndata"), INT2NUM(bdb_stat->bt_ndata));
 #endif
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_over_pg"), INT2NUM(bdb_stat->bt_over_pg));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_over_pgfree"), INT2NUM(bdb_stat->bt_over_pgfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_pagesize"), INT2NUM(bdb_stat->bt_pagesize));
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_re_len"), INT2NUM(bdb_stat->bt_re_len));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_over_pg"), INT2NUM(bdb_stat->bt_over_pg));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_over_pgfree"), INT2NUM(bdb_stat->bt_over_pgfree));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_pagesize"), INT2NUM(bdb_stat->bt_pagesize));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_re_len"), INT2NUM(bdb_stat->bt_re_len));
     pad = (char)bdb_stat->bt_re_pad;
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_re_pad"), rb_tainted_str_new(&pad, 1));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_re_pad"), rb_str_new(&pad, 1));
 #if HAVE_ST_DB_BTREE_STAT_BT_PAGECNT
-    rb_hash_aset(hash, rb_tainted_str_new2("bt_pagecnt"), INT2NUM(bdb_stat->bt_pagecnt));
+    rb_hash_aset(hash, rb_str_new_cstr("bt_pagecnt"), INT2NUM(bdb_stat->bt_pagecnt));
 #endif
     free(bdb_stat);
     return hash;
@@ -3736,38 +3693,37 @@ bdb_queue_stat(int argc, VALUE *argv, VALUE obj)
     bdb_test_error(dbst->dbp->stat(dbst->dbp, &bdb_stat, flags));
 #endif
     hash = rb_hash_new();
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_magic"), INT2NUM(bdb_stat->qs_magic));
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_version"), INT2NUM(bdb_stat->qs_version));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_magic"), INT2NUM(bdb_stat->qs_magic));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_version"), INT2NUM(bdb_stat->qs_version));
 #if HAVE_ST_DB_QUEUE_STAT_QS_NKEYS
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_nkeys"), INT2NUM(bdb_stat->qs_nkeys));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_nkeys"), INT2NUM(bdb_stat->qs_nkeys));
 #if ! HAVE_ST_DB_QUEUE_STAT_QS_NRECS
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_nrecs"), INT2NUM(bdb_stat->qs_nkeys));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_nrecs"), INT2NUM(bdb_stat->qs_nkeys));
 #endif
 #endif
 #if HAVE_ST_DB_QUEUE_STAT_QS_NDATA
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_ndata"), INT2NUM(bdb_stat->qs_ndata));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_ndata"), INT2NUM(bdb_stat->qs_ndata));
 #endif
 #if HAVE_ST_DB_QUEUE_STAT_QS_NRECS
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_nrecs"), INT2NUM(bdb_stat->qs_nrecs));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_nrecs"), INT2NUM(bdb_stat->qs_nrecs));
 #endif
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_pages"), INT2NUM(bdb_stat->qs_pages));
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_pagesize"), INT2NUM(bdb_stat->qs_pagesize));
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_pgfree"), INT2NUM(bdb_stat->qs_pgfree));
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_re_len"), INT2NUM(bdb_stat->qs_re_len));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_pages"), INT2NUM(bdb_stat->qs_pages));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_pagesize"), INT2NUM(bdb_stat->qs_pagesize));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_pgfree"), INT2NUM(bdb_stat->qs_pgfree));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_re_len"), INT2NUM(bdb_stat->qs_re_len));
     pad = (char)bdb_stat->qs_re_pad;
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_re_pad"), rb_tainted_str_new(&pad, 1));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_re_pad"), rb_str_new(&pad, 1));
 #if HAVE_ST_DB_QUEUE_STAT_QS_START
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_start"), INT2NUM(bdb_stat->qs_start));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_start"), INT2NUM(bdb_stat->qs_start));
 #endif
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_first_recno"), INT2NUM(bdb_stat->qs_first_recno));
-    rb_hash_aset(hash, rb_tainted_str_new2("qs_cur_recno"), INT2NUM(bdb_stat->qs_cur_recno));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_first_recno"), INT2NUM(bdb_stat->qs_first_recno));
+    rb_hash_aset(hash, rb_str_new_cstr("qs_cur_recno"), INT2NUM(bdb_stat->qs_cur_recno));
     free(bdb_stat);
     return hash;
 }
 
 static VALUE
-bdb_queue_padlen(obj)
-    VALUE obj;
+bdb_queue_padlen(VALUE obj)
 {
     bdb_DB *dbst;
     DB_QUEUE_STAT *bdb_stat;
@@ -3794,7 +3750,7 @@ bdb_queue_padlen(obj)
     bdb_test_error(dbst->dbp->stat(dbst->dbp, &bdb_stat, 0));
 #endif
     pad = (char)bdb_stat->qs_re_pad;
-    hash = rb_assoc_new(rb_tainted_str_new(&pad, 1), INT2NUM(bdb_stat->qs_re_len));
+    hash = rb_assoc_new(rb_str_new(&pad, 1), INT2NUM(bdb_stat->qs_re_len));
     free(bdb_stat);
     return hash;
 }
@@ -3802,8 +3758,7 @@ bdb_queue_padlen(obj)
 #endif
 
 static VALUE
-bdb_set_partial(obj, a, b)
-    VALUE obj, a, b;
+bdb_set_partial(VALUE obj, VALUE a, VALUE b)
 {
     bdb_DB *dbst;
     VALUE ret;
@@ -3823,8 +3778,7 @@ bdb_set_partial(obj, a, b)
 }
 
 static VALUE
-bdb_clear_partial(obj)
-    VALUE obj;
+bdb_clear_partial(VALUE obj)
 {
     bdb_DB *dbst;
     VALUE ret;
@@ -3844,8 +3798,7 @@ bdb_clear_partial(obj)
 #if HAVE_ST_DB_SET_ERRCALL
 
 static VALUE
-bdb_i_create(obj)
-    VALUE obj;
+bdb_i_create(VALUE obj)
 {
     DB *dbp;
     bdb_ENV *envst = 0;
@@ -3884,7 +3837,9 @@ bdb_s_upgrade(int argc, VALUE *argv, VALUE obj)
     int flags;
     VALUE val;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     flags = 0;
     if (rb_scan_args(argc, argv, "11", &a, &b) == 2) {
 	flags = NUM2INT(b);
@@ -3908,7 +3863,9 @@ bdb_s_remove(int argc, VALUE *argv, VALUE obj)
     VALUE a, b, c;
     char *name, *subname;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     c = bdb_i_create(obj);
     GetDB(c, dbst);
     name = subname = NULL;
@@ -3936,7 +3893,9 @@ bdb_s_rename(int argc, VALUE *argv, VALUE obj)
     VALUE a, b, c;
     char *name, *subname, *newname;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     c = bdb_i_create(obj);
     GetDB(c, dbst);
     name = subname = NULL;
@@ -3959,9 +3918,9 @@ bdb_s_rename(int argc, VALUE *argv, VALUE obj)
 #if HAVE_ST_DB_JOIN
 
 static VALUE
-bdb_i_joinclose(st)
-    eachst *st;
+bdb_i_joinclose(VALUE pst)
 {
+    eachst *st = (eachst *)pst;
     bdb_DB *dbst;
 
     GetDB(st->db, dbst);
@@ -3973,9 +3932,9 @@ bdb_i_joinclose(st)
 
  
 static VALUE
-bdb_i_join(st)
-    eachst *st;
+bdb_i_join(VALUE pst)
 {
+    eachst *st = (eachst *)pst;
     int ret;
     DBT key, data;
     db_recno_t recno;
@@ -4004,9 +3963,8 @@ bdb_join(int argc, VALUE *argv, VALUE obj)
     DBC *dbc, **dbcarr;
     int flags, i;
     eachst st;
-    VALUE a, b, c;
+    VALUE a, b;
 
-    c = 0;
     flags = 0;
     GetDB(obj, dbst);
     if (rb_scan_args(argc, argv, "11", &a, &b) == 2) {
@@ -4050,8 +4008,7 @@ bdb_join(int argc, VALUE *argv, VALUE obj)
 #if HAVE_ST_DB_BYTESWAPPED || HAVE_ST_DB_GET_BYTESWAPPED
 
 static VALUE
-bdb_byteswapp(obj)
-    VALUE obj;
+bdb_byteswapp(VALUE obj)
 {
     bdb_DB *dbst;
     int byteswap = 0;
@@ -4072,18 +4029,14 @@ bdb_byteswapp(obj)
 #if HAVE_ST_DB_ASSOCIATE
 
 static VALUE
-bdb_internal_second_call(tmp)
-    VALUE *tmp;
+bdb_internal_second_call(VALUE ptmp)
 {
+    VALUE *tmp = (VALUE *)ptmp;
     return rb_funcall2(tmp[0], bdb_id_call, 3, tmp + 1);
 }
 
 static int
-bdb_call_secondary(secst, pkey, pdata, skey)
-    DB *secst;
-    DBT *pkey;
-    DBT *pdata;
-    DBT *skey;
+bdb_call_secondary(DB *secst, DBT *pkey, DBT *pdata, DBT *skey)
 {
     VALUE obj, ary, second;
     bdb_DB *dbst, *secondst;
@@ -4189,8 +4142,7 @@ bdb_associate(int argc, VALUE *argv, VALUE obj)
 #endif
 
 static VALUE
-bdb_filename(obj)
-    VALUE obj;
+bdb_filename(VALUE obj)
 {
     bdb_DB *dbst;
     GetDB(obj, dbst);
@@ -4198,8 +4150,7 @@ bdb_filename(obj)
 }
 
 static VALUE
-bdb_database(obj)
-    VALUE obj;
+bdb_database(VALUE obj)
 {
     bdb_DB *dbst;
     GetDB(obj, dbst);
@@ -4222,7 +4173,9 @@ bdb_verify(int argc, VALUE *argv, VALUE obj)
 #endif
     FILE *io = NULL;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     file = database = NULL;
     switch(rb_scan_args(argc, argv, "02", &iov, &flagv)) {
     case 2:
@@ -4346,8 +4299,7 @@ bdb_feedback_set(VALUE obj, VALUE a)
 #endif
 
 static VALUE
-bdb_i_conf(obj, a)
-    VALUE obj, a;
+bdb_i_conf(VALUE obj, VALUE a)
 {
     bdb_DB *dbst;
     u_int32_t value;
@@ -4390,13 +4342,13 @@ bdb_i_conf(obj, a)
 	bdb_test_error(dbst->dbp->get_dbname(dbst->dbp, &filename, &dbname));
 	res = rb_ary_new2(3);
 	if (filename && strlen(filename)) {
-	    rb_ary_push(res, rb_tainted_str_new2(filename));
+	    rb_ary_push(res, rb_str_new_cstr(filename));
 	}
 	else {
 	    rb_ary_push(res, Qnil);
 	}
 	if (dbname && strlen(dbname)) {
-	    rb_ary_push(res, rb_tainted_str_new2(dbname));
+	    rb_ary_push(res, rb_str_new_cstr(dbname));
 	}
 	else {
 	    rb_ary_push(res, Qnil);
@@ -4463,7 +4415,7 @@ bdb_i_conf(obj, a)
 
 	bdb_test_error(dbst->dbp->get_re_source(dbst->dbp, &strval));
 	if (strval && strlen(strval)) {
-	    return rb_tainted_str_new2(strval);
+	    return rb_str_new_cstr(strval);
 	}
 	return Qnil;
     }
@@ -4539,9 +4491,9 @@ struct optst {
 };
 
 static VALUE
-bdb_intern_conf(optp)
-    struct optst *optp;
+bdb_intern_conf(VALUE poptp)
 {
+    struct optst *optp = (struct optst *)poptp;
     return bdb_i_conf(optp->obj, optp->str);
 }
 

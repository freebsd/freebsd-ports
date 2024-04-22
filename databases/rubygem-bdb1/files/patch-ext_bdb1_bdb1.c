--- ext/bdb1/bdb1.c.orig	2024-03-25 10:10:37 UTC
+++ ext/bdb1/bdb1.c
@@ -115,7 +115,6 @@ VALUE
 bdb1_test_load(VALUE obj, const DBT *a, int type_kv)
 {
     VALUE res;
-    int i;
     bdb1_DB *dbst;
 
     Data_Get_Struct(obj, bdb1_DB, dbst);
@@ -138,7 +137,7 @@ bdb1_test_load(VALUE obj, const DBT *a, int type_kv)
 	    res = Qnil;
 	}
 	else {
-	    res = rb_tainted_str_new(a->data, a->size);
+	    res = rb_str_new(a->data, a->size);
 	    if (dbst->filter[2 + type_kv]) {
 		if (FIXNUM_P(dbst->filter[2 + type_kv])) {
 		    res = rb_funcall(obj,
@@ -230,7 +229,7 @@ bdb1_h_hash(const void *bytes, size_t length)
 	rb_raise(bdb1_eFatal, "BUG : current_db not set");
     }
     Data_Get_Struct(obj, bdb1_DB, dbst);
-    st = rb_tainted_str_new((char *)bytes, length);
+    st = rb_str_new((char *)bytes, length);
     if (dbst->h_hash == 0)
 	res = rb_funcall(obj, id_h_hash, 1, st);
     else
@@ -270,7 +269,7 @@ bdb1_mark(bdb1_DB *dbst)
 }
 
 static VALUE
-bdb1_i185_btree(VALUE obj, VALUE dbstobj)
+bdb1_i185_btree(VALUE obj, VALUE dbstobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     bdb1_DB *dbst;
@@ -323,7 +322,7 @@ bdb1_i185_btree(VALUE obj, VALUE dbstobj)
 }
 
 static VALUE
-bdb1_i185_hash(VALUE obj, VALUE dbstobj)
+bdb1_i185_hash(VALUE obj, VALUE dbstobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     bdb1_DB *dbst;
@@ -363,7 +362,7 @@ bdb1_i185_hash(VALUE obj, VALUE dbstobj)
 }
 
 static VALUE
-bdb1_i185_recno(VALUE obj, VALUE dbstobj)
+bdb1_i185_recno(VALUE obj, VALUE dbstobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     bdb1_DB *dbst;
@@ -379,7 +378,6 @@ bdb1_i185_recno(VALUE obj, VALUE dbstobj)
 	dbst->info.ri.flags = NUM2INT(value);
     }
     else if (strcmp(options, "set_re_delim") == 0) {
-	int ch;
 	if (TYPE(value) == T_STRING) {
 	    str = StringValueCStr(value);
 	    dbst->info.ri.bval = str[0];
@@ -396,7 +394,6 @@ bdb1_i185_recno(VALUE obj, VALUE dbstobj)
 	dbst->info.ri.flags |= R_FIXEDLEN;
     }
     else if (strcmp(options, "set_re_pad") == 0) {
-	int ch;
 	if (TYPE(value) == T_STRING) {
 	    str = StringValueCStr(value);
 	    dbst->info.ri.bval = str[0];
@@ -444,7 +441,7 @@ bdb1_load_dump(VALUE obj)
 }
 
 static VALUE
-bdb1_i185_common(VALUE obj, VALUE dbstobj)
+bdb1_i185_common(VALUE obj, VALUE dbstobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE key, value;
     bdb1_DB *dbst;
@@ -682,7 +679,7 @@ bdb1_init(int argc, VALUE *argv, VALUE obj)
 	}
 	switch(dbst->type) {
 	case 0:
-	    rb_iterate(rb_each, f, bdb1_i185_btree, obj);
+  	    rb_block_call(f, rb_intern("each"), 0, NULL, bdb1_i185_btree, obj);
 	    if (dbst->bt_compare == 0 && rb_respond_to(obj, id_bt_compare)) {
 		dbst->has_info = Qtrue;
 		dbst->options |= BDB1_BT_COMPARE;
@@ -695,7 +692,7 @@ bdb1_init(int argc, VALUE *argv, VALUE obj)
 	    }
 	    break;
 	case 1:
-	    rb_iterate(rb_each, f, bdb1_i185_hash, obj);
+  	    rb_block_call(f, rb_intern("each"), 0, NULL, bdb1_i185_hash, obj);
 	    if (dbst->h_hash == 0 && rb_respond_to(obj, id_h_hash)) {
 		dbst->has_info = Qtrue;
 		dbst->options |= BDB1_H_HASH;
@@ -703,10 +700,10 @@ bdb1_init(int argc, VALUE *argv, VALUE obj)
 	    }
 	    break;
 	case 2:
-	    rb_iterate(rb_each, f, bdb1_i185_recno, obj);
+  	    rb_block_call(f, rb_intern("each"), 0, NULL, bdb1_i185_recno, obj);
 	    break;
 	}
-	rb_iterate(rb_each, f, bdb1_i185_common, obj);
+  	rb_block_call(f, rb_intern("each"), 0, NULL, bdb1_i185_common, obj);
     }
     if (name == NULL) oflags = O_CREAT | O_RDWR;
     if (dbst->has_info) openinfo = &dbst->info;
@@ -733,9 +730,11 @@ bdb1_close(VALUE obj)
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
@@ -752,15 +751,15 @@ bdb1_s_alloc(VALUE obj)
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
@@ -802,7 +801,7 @@ bdb1_s_create(int argc, VALUE *argv, VALUE obj)
 }
 
 static VALUE
-bdb1_i_create(VALUE obj, VALUE db)
+bdb1_i_create(VALUE obj, VALUE db, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     VALUE tmp[2];
     tmp[0] = rb_ary_entry(obj, 0);
@@ -826,12 +825,12 @@ bdb1_i_create(VALUE obj, VALUE db)
 static VALUE
 bdb1_s_aref(int argc, VALUE *argv, VALUE obj)
 {
-    VALUE res, tmp[2];
+    VALUE res;
     int i;
 
     res = rb_funcall2(obj, rb_intern("new"), 0, 0);
     if (argc == 1 && TYPE(argv[0]) == T_HASH) {
-	rb_iterate(rb_each, argv[0], bdb1_i_create, res);
+	rb_block_call(argv[0], rb_intern("each"), 0, NULL, bdb1_i_create, res);
 	return res;
     }
     if (argc % 2 != 0) {
@@ -870,7 +869,7 @@ bdb1_s_open(int argc, VALUE *argv, VALUE obj)
 VALUE
 bdb1_put(int argc, VALUE *argv, VALUE obj)
 {
-    volatile VALUE a0 = Qnil;
+    volatile VALUE a0;
     volatile VALUE b0 = Qnil;
     VALUE a, b, c;
     bdb1_DB *dbst;
@@ -878,7 +877,9 @@ bdb1_put(int argc, VALUE *argv, VALUE obj)
     int ret, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     if (rb_scan_args(argc, argv, "21", &a, &b, &c) == 3)
         flags = NUM2INT(c);
@@ -935,7 +936,6 @@ bdb1_get_internal(int argc, VALUE *argv, VALUE obj, VA
     VALUE b, c;
     bdb1_DB *dbst;
     DBT key, data;
-    DBT datas;
     int flagss;
     int ret, flags;
     db_recno_t recno;
@@ -994,7 +994,7 @@ bdb1_fetch(int argc, VALUE *argv, VALUE obj)
     if (val == Qundef) {
 	if (rb_block_given_p()) {
 	    if (argc > 1) {
-		rb_raise(rb_eArgError, "wrong # of arguments", argc);
+		rb_raise(rb_eArgError, "wrong # of arguments, %d", argc);
 	    }
 	    return rb_yield(key);
 	}
@@ -1026,8 +1026,8 @@ bdb1_has_both(VALUE obj, VALUE a, VALUE b)
     DBT keys, datas;
     int ret, flags;
     db_recno_t recno;
-    volatile VALUE c = Qnil;
-    volatile VALUE d = Qnil;
+    volatile VALUE c;
+    volatile VALUE d;
 
     GetDB(obj, dbst);
     DATA_ZERO(key);
@@ -1071,7 +1071,9 @@ bdb1_del(VALUE obj, VALUE a)
     db_recno_t recno;
     volatile VALUE c = Qnil;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     if (dbst->type == DB_HASH) {
 	rb_warning("delete can give strange result with DB_HASH");
@@ -1090,7 +1092,7 @@ bdb1_empty(VALUE obj)
 {
     bdb1_DB *dbst;
     DBT key, data;
-    int ret, flags;
+    int ret;
     db_recno_t recno;
 
     GetDB(obj, dbst);
@@ -1109,10 +1111,12 @@ bdb1_delete_if(VALUE obj)
 {
     bdb1_DB *dbst;
     DBT key, data, save;
-    int ret, ret1, flags;
+    int ret, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     INIT_RECNO(dbst, key, recno);
     DATA_ZERO(data);
@@ -1134,11 +1138,13 @@ VALUE
 bdb1_clear(VALUE obj)
 {
     bdb1_DB *dbst;
-    DBT key, data, save;
+    DBT key, data;
     int ret, value, flags;
     db_recno_t recno;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     INIT_RECNO(dbst, key, recno);
     DATA_ZERO(data);
@@ -1360,7 +1366,7 @@ bdb1_each_kv(VALUE obj, VALUE a, VALUE result, VALUE f
     int ret, flags;
     db_recno_t recno;
     VALUE k;
-    volatile VALUE b = Qnil;
+    volatile VALUE b;
 
     GetDB(obj, dbst);
     b = test_recno(obj, &key, &recno, a);
@@ -1536,8 +1542,10 @@ bdb1_sync(VALUE obj)
 {
     bdb1_DB *dbst;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4)
 	rb_raise(rb_eSecurityError, "Insecure: can't sync the database");
+#endif
     GetDB(obj, dbst);
     bdb1_test_error(dbst->dbp->sync(dbst->dbp, 0));
     return Qtrue;
@@ -1740,7 +1748,7 @@ Init_bdb1(void)
     rb_undef_method(bdb1_cHash, "reverse_each_pair");
     rb_undef_method(bdb1_cHash, "reverse_each");
     bdb1_cUnknown = rb_define_class_under(bdb1_mDb, "Unknown", bdb1_cCommon);
-    bdb1_errstr = rb_tainted_str_new(0, 0);
+    bdb1_errstr = rb_str_new(0, 0);
     rb_global_variable(&bdb1_errstr);
     bdb1_init_delegator();
     bdb1_init_recnum();

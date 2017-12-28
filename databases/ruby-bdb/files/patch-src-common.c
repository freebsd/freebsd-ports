--- src/common.c.orig	2011-04-06 19:35:39.000000000 +0000
+++ src/common.c	2015-01-22 17:10:32.000000000 +0000
@@ -1229,7 +1229,7 @@
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE v, f = argv[argc - 1];
 
-	if ((v = rb_hash_aref(f, rb_str_new2("txn"))) != RHASH(f)->ifnone) {
+	if ((v = rb_hash_aref(f, rb_str_new2("txn"))) != rb_hash_ifnone(f)) {
 	    if (!rb_obj_is_kind_of(v, bdb_cTxn)) {
 		rb_raise(bdb_eFatal, "argument of txn must be a transaction");
 	    }
@@ -1241,7 +1241,7 @@
 	    dbst->options |= envst->options & BDB_NO_THREAD;
 	    dbst->marshal = txnst->marshal;
 	}
-	else if ((v = rb_hash_aref(f, rb_str_new2("env"))) != RHASH(f)->ifnone) {
+	else if ((v = rb_hash_aref(f, rb_str_new2("env"))) != rb_hash_ifnone(f)) {
 	    if (!rb_obj_is_kind_of(v, bdb_cEnv)) {
 		rb_raise(bdb_eFatal, "argument of env must be an environnement");
 	    }
@@ -1254,11 +1254,11 @@
 #if HAVE_CONST_DB_ENCRYPT 
 	if (envst && (envst->options & BDB_ENV_ENCRYPT)) {
 	    VALUE tmp = rb_str_new2("set_flags");
-	    if ((v = rb_hash_aref(f, rb_intern("set_flags"))) != RHASH(f)->ifnone) {
+	    if ((v = rb_hash_aref(f, rb_intern("set_flags"))) != rb_hash_ifnone(f)) {
 		rb_hash_aset(f, rb_intern("set_flags"), 
 			     INT2NUM(NUM2INT(v) | DB_ENCRYPT));
 	    }
-	    else if ((v = rb_hash_aref(f, tmp)) != RHASH(f)->ifnone) {
+	    else if ((v = rb_hash_aref(f, tmp)) != rb_hash_ifnone(f)) {
 		rb_hash_aset(f, tmp, INT2NUM(NUM2INT(v) | DB_ENCRYPT));
 	    }
 	    else {
@@ -1570,10 +1570,10 @@
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
@@ -1581,17 +1581,17 @@
 
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
@@ -1635,29 +1635,29 @@
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
@@ -3004,8 +3004,8 @@
 
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE g, f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_aref(f, rb_intern("flags"))) != rb_hash_ifnone(f) ||
+	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != rb_hash_ifnone(f)) {
 	    flags = NUM2INT(g);
 	}
 	argc--;
@@ -3323,8 +3323,8 @@
     flags = 0;
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE g, f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_aref(f, rb_intern("flags"))) != rb_hash_ifnone(f) ||
+	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != rb_hash_ifnone(f)) {
 	    flags = NUM2INT(g);
 	}
 	argc--;
@@ -3348,8 +3348,8 @@
     flags = 0;
     if (TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_aref(f, rb_intern("flags"))) != rb_hash_ifnone(f) ||
+	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != rb_hash_ifnone(f)) {
 	    flags = NUM2INT(g);
 	}
 	argc--;

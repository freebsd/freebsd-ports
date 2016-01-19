--- ext/bdb1/bdb1.c.orig	2016-01-18 21:34:35 UTC
+++ ext/bdb1/bdb1.c
@@ -752,15 +752,15 @@ bdb1_s_alloc(VALUE obj)
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

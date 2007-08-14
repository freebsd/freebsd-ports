--- src/bdb.c.orig	Sun Jul 29 23:33:18 2007
+++ src/bdb.c	Tue Aug 14 22:33:01 2007
@@ -512,7 +512,11 @@
 #ifdef DB_REP_ISPERM
     rb_define_const(bdb_mDb, "REP_ISPERM", INT2FIX(DB_REP_ISPERM));
     rb_define_const(bdb_mDb, "REP_NOTPERM", INT2FIX(DB_REP_NOTPERM));
+#endif
+#ifdef DB_REP_IGNORE
     rb_define_const(bdb_mDb, "REP_IGNORE", INT2FIX(DB_REP_IGNORE));
+#endif
+#ifdef DB_REP_JOIN_FAILURE
     rb_define_const(bdb_mDb, "REP_JOIN_FAILURE", INT2FIX(DB_REP_JOIN_FAILURE));
 #endif
     rb_define_const(bdb_mDb, "EID_BROADCAST", INT2FIX(DB_EID_BROADCAST));

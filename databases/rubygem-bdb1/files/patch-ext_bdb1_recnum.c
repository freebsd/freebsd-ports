--- ext/bdb1/recnum.c.orig	2022-05-09 10:22:04 UTC
+++ ext/bdb1/recnum.c
@@ -17,7 +17,7 @@ bdb1_recnum_init(int argc, VALUE *argv, VALUE obj)
 	argc++;
     }
     rb_hash_aset(argv[argc - 1], array, INT2FIX(0));
-    if (rb_hash_aref(argv[argc - 1], sarray) != RHASH(argv[argc - 1])->ifnone) {
+    if (rb_hash_lookup2(argv[argc - 1], sarray, Qundef) != Qundef) {
 	rb_hash_aset(argv[argc - 1], sarray, INT2FIX(0));
     }
     return bdb1_init(argc, argv, obj);
@@ -134,7 +134,9 @@ bdb1_intern_shift_pop(VALUE obj, int depart, int len)
     db_recno_t recno;
     VALUE res;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     rb_secure(4);
+#endif
     GetDB(obj, dbst);
     INIT_RECNO(dbst, key, recno);
     DATA_ZERO(data);

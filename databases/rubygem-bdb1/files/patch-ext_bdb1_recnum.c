--- ext/bdb1/recnum.c.orig
+++ ext/bdb1/recnum.c
@@ -17,7 +17,7 @@
 	argc++;
     }
     rb_hash_aset(argv[argc - 1], array, INT2FIX(0));
-    if (rb_hash_aref(argv[argc - 1], sarray) != RHASH(argv[argc - 1])->ifnone) {
+    if (rb_hash_aref(argv[argc - 1], sarray) != rb_hash_ifnone(argv[argc - 1])) {
 	rb_hash_aset(argv[argc - 1], sarray, INT2FIX(0));
     }
     rb_hash_aset(argv[argc - 1], rb_str_new2("set_flags"), INT2FIX(DB_RENUMBER));

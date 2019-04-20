--- src/recnum.c.orig	2011-04-06 19:35:39 UTC
+++ src/recnum.c
@@ -17,7 +17,7 @@ bdb_recnum_init(int argc, VALUE *argv, V
 	argc++;
     }
     rb_hash_aset(argv[argc - 1], array, INT2FIX(0));
-    if (rb_hash_aref(argv[argc - 1], sarray) != RHASH(argv[argc - 1])->ifnone) {
+    if (rb_hash_lookup(argv[argc - 1], sarray) != Qnil) {
 	rb_hash_aset(argv[argc - 1], sarray, INT2FIX(0));
     }
     rb_hash_aset(argv[argc - 1], rb_str_new2("set_flags"), INT2FIX(DB_RENUMBER));
@@ -697,8 +697,8 @@ bdb_sary_clear(int argc, VALUE *argv, VA
 
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_lookup(f, rb_intern("flags"))) != Qnil ||
+	    (g = rb_hash_lookup(f, rb_str_new2("flags"))) != Qnil) {
 	    flags = NUM2INT(g);
 	}
 	argc--;

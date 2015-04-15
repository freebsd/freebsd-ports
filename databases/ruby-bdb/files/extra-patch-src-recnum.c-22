--- src/recnum.c.orig	2011-04-06 19:35:39.000000000 +0000
+++ src/recnum.c	2015-01-22 17:16:32.000000000 +0000
@@ -17,7 +17,7 @@
 	argc++;
     }
     rb_hash_aset(argv[argc - 1], array, INT2FIX(0));
-    if (rb_hash_aref(argv[argc - 1], sarray) != RHASH(argv[argc - 1])->ifnone) {
+    if (rb_hash_aref(argv[argc - 1], sarray) != rb_hash_ifnone(argv[argc - 1])) {
 	rb_hash_aset(argv[argc - 1], sarray, INT2FIX(0));
     }
     rb_hash_aset(argv[argc - 1], rb_str_new2("set_flags"), INT2FIX(DB_RENUMBER));
@@ -697,8 +697,8 @@
 
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE f = argv[argc - 1];
-	if ((g = rb_hash_aref(f, rb_intern("flags"))) != RHASH(f)->ifnone ||
-	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != RHASH(f)->ifnone) {
+	if ((g = rb_hash_aref(f, rb_intern("flags"))) != rb_hash_ifnone(f) ||
+	    (g = rb_hash_aref(f, rb_str_new2("flags"))) != rb_hash_ifnone(f)) {
 	    flags = NUM2INT(g);
 	}
 	argc--;

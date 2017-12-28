--- src/cursor.c.orig	2015-01-22 17:37:51.000000000 +0000
+++ src/cursor.c	2015-01-22 17:38:17.000000000 +0000
@@ -29,8 +29,8 @@
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

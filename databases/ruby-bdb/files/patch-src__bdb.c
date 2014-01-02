--- ./src/bdb.c.orig	2011-04-06 19:35:39.000000000 +0000
+++ ./src/bdb.c	2013-12-18 19:04:39.134238326 +0000
@@ -166,11 +166,10 @@
 	rb_raise(rb_eNameError, "module already defined");
     }
     version = rb_tainted_str_new2(db_version(&major, &minor, &patch));
-    if (major != DB_VERSION_MAJOR || minor != DB_VERSION_MINOR
-	|| patch != DB_VERSION_PATCH) {
-        rb_raise(rb_eNotImpError, "\nBDB needs compatible versions of libdb & db.h\n\tyou have db.h version %d.%d.%d and libdb version %d.%d.%d\n",
-		 DB_VERSION_MAJOR, DB_VERSION_MINOR, DB_VERSION_PATCH,
-		 major, minor, patch);
+    if (major != DB_VERSION_MAJOR || minor != DB_VERSION_MINOR) {
+        rb_raise(rb_eNotImpError, "\nBDB needs compatible versions of libdb & db.h\n\tyou have db.h version %d.%d and libdb version %d.%d\n",
+		 DB_VERSION_MAJOR, DB_VERSION_MINOR,
+		 major, minor);
     }
     bdb_mMarshal = rb_const_get(rb_cObject, rb_intern("Marshal"));
     bdb_id_current_db = rb_intern("__bdb_current_db__");
@@ -189,7 +188,6 @@
     rb_define_const(bdb_mDb, "VERSION", version);
     rb_define_const(bdb_mDb, "VERSION_MAJOR", INT2FIX(major));
     rb_define_const(bdb_mDb, "VERSION_MINOR", INT2FIX(minor));
-    rb_define_const(bdb_mDb, "VERSION_PATCH", INT2FIX(patch));
     rb_define_const(bdb_mDb, "VERSION_NUMBER", INT2NUM(BDB_VERSION));
 #if HAVE_CONST_DB_BTREE
     rb_define_const(bdb_mDb, "BTREE", INT2FIX(DB_BTREE));

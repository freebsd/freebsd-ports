--- ./bdbxml1/bdbxml.cc.orig	2011-04-06 19:35:39.000000000 +0000
+++ ./bdbxml1/bdbxml.cc	2014-01-03 01:47:58.535201285 +0000
@@ -2340,18 +2340,16 @@
 	major = NUM2INT(rb_const_get(xb_mDb, rb_intern("VERSION_MAJOR")));
 	minor = NUM2INT(rb_const_get(xb_mDb, rb_intern("VERSION_MINOR")));
 	patch = NUM2INT(rb_const_get(xb_mDb, rb_intern("VERSION_PATCH")));
-	if (major != DB_VERSION_MAJOR || minor != DB_VERSION_MINOR
-	    || patch != DB_VERSION_PATCH) {
-	    rb_raise(rb_eNotImpError, "\nBDB::XML needs compatible versions of BDB\n\tyou have BDB::XML version %d.%d.%d and BDB version %d.%d.%d\n",
-		     DB_VERSION_MAJOR, DB_VERSION_MINOR, DB_VERSION_PATCH,
-		     major, minor, patch);
+	if (major != DB_VERSION_MAJOR || minor != DB_VERSION_MINOR) {
+	    rb_raise(rb_eNotImpError, "\nBDB::XML needs compatible versions of BDB\n\tyou have BDB::XML version %d.%d and BDB version %d.%d\n",
+		     DB_VERSION_MAJOR, DB_VERSION_MINOR,
+		     major, minor);
 	}
 	version = rb_tainted_str_new2(dbxml_version(&major, &minor, &patch));
-	if (major != DBXML_VERSION_MAJOR || minor != DBXML_VERSION_MINOR
-	    || patch != DBXML_VERSION_PATCH) {
-	    rb_raise(rb_eNotImpError, "\nBDB::XML needs compatible versions of DbXml\n\tyou have DbXml.hpp version %d.%d.%d and libdbxml version %d.%d.%d\n",
-		     DB_VERSION_MAJOR, DB_VERSION_MINOR, DB_VERSION_PATCH,
-		     major, minor, patch);
+	if (major != DBXML_VERSION_MAJOR || minor != DBXML_VERSION_MINOR) {
+	    rb_raise(rb_eNotImpError, "\nBDB::XML needs compatible versions of DbXml\n\tyou have DbXml.hpp version %d.%d and libdbxml version %d.%d\n",
+		     DB_VERSION_MAJOR, DB_VERSION_MINOR,
+		     major, minor);
 	}
 
 	xb_eFatal = rb_const_get(xb_mDb, rb_intern("Fatal"));

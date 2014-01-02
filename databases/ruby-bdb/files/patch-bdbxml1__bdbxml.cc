--- ./bdbxml1/bdbxml.cc.orig	2011-04-06 19:35:39.000000000 +0000
+++ ./bdbxml1/bdbxml.cc	2013-12-18 19:00:54.663254132 +0000
@@ -2316,7 +2316,7 @@
 
     void Init_bdbxml()
     {
-	int major, minor, patch;
+	int major, minor;
 	VALUE version;
 #ifdef BDB_LINK_OBJ
 	extern void Init_bdb();
@@ -2339,19 +2339,16 @@
 	xb_mDb = rb_const_get(rb_cObject, rb_intern("BDB"));
 	major = NUM2INT(rb_const_get(xb_mDb, rb_intern("VERSION_MAJOR")));
 	minor = NUM2INT(rb_const_get(xb_mDb, rb_intern("VERSION_MINOR")));
-	patch = NUM2INT(rb_const_get(xb_mDb, rb_intern("VERSION_PATCH")));
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
-	version = rb_tainted_str_new2(dbxml_version(&major, &minor, &patch));
-	if (major != DBXML_VERSION_MAJOR || minor != DBXML_VERSION_MINOR
-	    || patch != DBXML_VERSION_PATCH) {
-	    rb_raise(rb_eNotImpError, "\nBDB::XML needs compatible versions of DbXml\n\tyou have DbXml.hpp version %d.%d.%d and libdbxml version %d.%d.%d\n",
-		     DB_VERSION_MAJOR, DB_VERSION_MINOR, DB_VERSION_PATCH,
-		     major, minor, patch);
+	version = rb_tainted_str_new2(dbxml_version(&major, &minor));
+	if (major != DBXML_VERSION_MAJOR || minor != DBXML_VERSION_MINOR) {
+	    rb_raise(rb_eNotImpError, "\nBDB::XML needs compatible versions of DbXml\n\tyou have DbXml.hpp version %d.%d and libdbxml version %d.%d\n",
+		     DB_VERSION_MAJOR, DB_VERSION_MINOR,
+		     major, minor);
 	}
 
 	xb_eFatal = rb_const_get(xb_mDb, rb_intern("Fatal"));
@@ -2374,7 +2371,6 @@
 	rb_define_const(xb_mXML, "VERSION", version);
 	rb_define_const(xb_mXML, "VERSION_MAJOR", INT2FIX(major));
 	rb_define_const(xb_mXML, "VERSION_MINOR", INT2FIX(minor));
-	rb_define_const(xb_mXML, "VERSION_PATCH", INT2FIX(patch));
 #ifdef DBXML_CHKSUM_SHA1
 	rb_define_const(xb_mXML, "CHKSUM_SHA1", INT2NUM(DBXML_CHKSUM_SHA1));
 #endif

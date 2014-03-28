--- _mysql.c.orig	2014-03-18 19:07:07.000000000 +0400
+++ _mysql.c	2014-03-18 19:07:40.000000000 +0400
@@ -102,6 +102,10 @@ static int _mysql_server_init_done = 0;
 #define check_server_init(x) if (!_mysql_server_init_done) _mysql_server_init_done = 1
 #endif
 
+#if MYSQL_VERSION_ID >= 50500
+#define HAVE_OPENSSL 1
+#endif
+
 PyObject *
 _mysql_Exception(_mysql_ConnectionObject *c)
 {

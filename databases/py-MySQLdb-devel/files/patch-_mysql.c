Index: MySQLdb/_mysql.c
===================================================================
RCS file: /cvsroot/mysql-python/MySQLdb/_mysql.c,v
retrieving revision 1.49
diff -u -r1.49 _mysql.c
--- _mysql.c	7 Jun 2004 03:44:38 -0000	1.49
+++ _mysql.c	26 Jul 2004 16:58:29 -0000
@@ -1542,7 +1542,13 @@
 	if (!PyArg_ParseTuple(args, "")) return NULL;
 	check_connection(self);
 	Py_BEGIN_ALLOW_THREADS
+
+#if MYSQL_VERSION_ID >= 40103
+   r = mysql_shutdown(&(self->connection),
+                      SHUTDOWN_DEFAULT);
+#else
 	r = mysql_shutdown(&(self->connection));
+#endif
 	Py_END_ALLOW_THREADS
 	if (r) return _mysql_Exception(self);
 	Py_INCREF(Py_None);

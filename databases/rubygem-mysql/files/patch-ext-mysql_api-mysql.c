--- ext/mysql_api/mysql.c.orig	2020-05-29 23:08:40 UTC
+++ ext/mysql_api/mysql.c
@@ -273,7 +273,10 @@ static VALUE real_connect(int argc, VALUE* argv, VALUE
     rb_thread_start_timer();
 #endif
 
+#if MYSQL_VERSION_ID >= 100400
+#else
     myp->handler.reconnect = 0;
+#endif
     myp->connection = Qtrue;
     myp->query_with_result = Qtrue;
     rb_obj_call_init(obj, argc, argv);
@@ -347,7 +350,10 @@ static VALUE real_connect2(int argc, VALUE* argv, VALU
 #ifdef HAVE_RB_THREAD_START_TIMER
     rb_thread_start_timer();
 #endif
+#if MYSQL_VERSION_ID >= 100400
+#else
     m->reconnect = 0;
+#endif
     GetMysqlStruct(obj)->connection = Qtrue;
 
     return obj;
@@ -917,13 +923,21 @@ static VALUE query_with_result_set(VALUE obj, VALUE fl
 /*	reconnect()	*/
 static VALUE reconnect(VALUE obj)
 {
+#if MYSQL_VERSION_ID >= 100400
+    return Qfalse;
+#else
     return GetHandler(obj)->reconnect ? Qtrue : Qfalse;
+#endif
 }
 
 /*	reconnect=(flag)	*/
 static VALUE reconnect_set(VALUE obj, VALUE flag)
 {
+#if MYSQL_VERSION_ID >= 100400
+    return Qfalse;
+#else
     GetHandler(obj)->reconnect = (flag == Qnil || flag == Qfalse) ? 0 : 1;
+#endif
     return flag;
 }
 
@@ -1317,7 +1331,7 @@ static VALUE stmt_bind_result(int argc, VALUE *argv, V
 	}
 	else if (argv[i] == rb_cString)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_STRING;
-	else if (argv[i] == rb_cNumeric || argv[i] == rb_cInteger || argv[i] == rb_cFixnum)
+	else if (argv[i] == rb_cNumeric || argv[i] == rb_cInteger || argv[i] == rb_cInteger)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_LONGLONG;
 	else if (argv[i] == rb_cFloat)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_DOUBLE;

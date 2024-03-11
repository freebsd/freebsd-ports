--- ext/mysql_api/mysql.c.orig	2024-03-11 10:33:12 UTC
+++ ext/mysql_api/mysql.c
@@ -170,7 +170,7 @@ static void mysql_raise(MYSQL* m)
     VALUE e = rb_exc_new2(eMysql, mysql_error(m));
     rb_iv_set(e, "errno", INT2FIX(mysql_errno(m)));
 #if MYSQL_VERSION_ID >= 40101
-    rb_iv_set(e, "sqlstate", rb_tainted_str_new2(mysql_sqlstate(m)));
+    rb_iv_set(e, "sqlstate", rb_str_new_cstr(mysql_sqlstate(m)));
 #endif
     rb_exc_raise(e);
 }
@@ -197,9 +197,9 @@ static VALUE make_field_obj(MYSQL_FIELD* f)
     if (f == NULL)
 	return Qnil;
     obj = rb_obj_alloc(cMysqlField);
-    rb_iv_set(obj, "name", f->name? rb_str_freeze(rb_tainted_str_new2(f->name)): Qnil);
-    rb_iv_set(obj, "table", f->table? rb_str_freeze(rb_tainted_str_new2(f->table)): Qnil);
-    rb_iv_set(obj, "def", f->def? rb_str_freeze(rb_tainted_str_new2(f->def)): Qnil);
+    rb_iv_set(obj, "name", f->name? rb_str_freeze(rb_str_new_cstr(f->name)): Qnil);
+    rb_iv_set(obj, "table", f->table? rb_str_freeze(rb_str_new_cstr(f->table)): Qnil);
+    rb_iv_set(obj, "def", f->def? rb_str_freeze(rb_str_new_cstr(f->def)): Qnil);
     rb_iv_set(obj, "type", INT2NUM(f->type));
     rb_iv_set(obj, "length", INT2NUM(f->length));
     rb_iv_set(obj, "max_length", INT2NUM(f->max_length));
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
@@ -294,7 +297,7 @@ static VALUE escape_string(VALUE klass, VALUE str)
 /*	client_info()	*/
 static VALUE client_info(VALUE klass)
 {
-    return rb_tainted_str_new2(mysql_get_client_info());
+    return rb_str_new_cstr(mysql_get_client_info());
 }
 
 #if MYSQL_VERSION_ID >= 32332
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
@@ -469,7 +475,7 @@ static VALUE change_user(int argc, VALUE* argv, VALUE 
 /*	character_set_name()	*/
 static VALUE character_set_name(VALUE obj)
 {
-    return rb_tainted_str_new2(mysql_character_set_name(GetHandler(obj)));
+    return rb_str_new_cstr(mysql_character_set_name(GetHandler(obj)));
 }
 #endif
 
@@ -534,7 +540,7 @@ static VALUE field_count(VALUE obj)
 /*	host_info()	*/
 static VALUE host_info(VALUE obj)
 {
-    return rb_tainted_str_new2(mysql_get_host_info(GetHandler(obj)));
+    return rb_str_new_cstr(mysql_get_host_info(GetHandler(obj)));
 }
 
 /*	proto_info()	*/
@@ -546,14 +552,14 @@ static VALUE proto_info(VALUE obj)
 /*	server_info()	*/
 static VALUE server_info(VALUE obj)
 {
-    return rb_tainted_str_new2(mysql_get_server_info(GetHandler(obj)));
+    return rb_str_new_cstr(mysql_get_server_info(GetHandler(obj)));
 }
 
 /*	info()		*/
 static VALUE info(VALUE obj)
 {
     const char* p = mysql_info(GetHandler(obj));
-    return p? rb_tainted_str_new2(p): Qnil;
+    return p? rb_str_new_cstr(p): Qnil;
 }
 
 /*	insert_id()	*/
@@ -588,7 +594,7 @@ static VALUE list_dbs(int argc, VALUE* argv, VALUE obj
     n = mysql_num_rows(res);
     ret = rb_ary_new2(n);
     for (i=0; i<n; i++)
-	rb_ary_store(ret, i, rb_tainted_str_new2(mysql_fetch_row(res)[0]));
+	rb_ary_store(ret, i, rb_str_new_cstr(mysql_fetch_row(res)[0]));
     mysql_free_result(res);
     return ret;
 }
@@ -633,7 +639,7 @@ static VALUE list_tables(int argc, VALUE* argv, VALUE 
     n = mysql_num_rows(res);
     ret = rb_ary_new2(n);
     for (i=0; i<n; i++)
-	rb_ary_store(ret, i, rb_tainted_str_new2(mysql_fetch_row(res)[0]));
+	rb_ary_store(ret, i, rb_str_new_cstr(mysql_fetch_row(res)[0]));
     mysql_free_result(res);
     return ret;
 }
@@ -697,7 +703,7 @@ static VALUE my_stat(VALUE obj)
     const char* s = mysql_stat(m);
     if (s == NULL)
 	mysql_raise(m);
-    return rb_tainted_str_new2(s);
+    return rb_str_new_cstr(s);
 }
 
 /*	store_result()	*/
@@ -864,7 +870,7 @@ static VALUE set_server_option(VALUE obj, VALUE option
 static VALUE sqlstate(VALUE obj)
 {
     MYSQL *m = GetHandler(obj);
-    return rb_tainted_str_new2(mysql_sqlstate(m));
+    return rb_str_new_cstr(mysql_sqlstate(m));
 }
 #endif
 
@@ -875,12 +881,12 @@ static VALUE stmt_init(VALUE obj)
     MYSQL *m = GetHandler(obj);
     MYSQL_STMT *s;
     struct mysql_stmt* stmt;
-    my_bool true = 1;
+    my_bool mytrue = 1;
     VALUE st_obj;
 
     if ((s = mysql_stmt_init(m)) == NULL)
 	mysql_raise(m);
-    if (mysql_stmt_attr_set(s, STMT_ATTR_UPDATE_MAX_LENGTH, &true))
+    if (mysql_stmt_attr_set(s, STMT_ATTR_UPDATE_MAX_LENGTH, &mytrue))
 	rb_raise(rb_eArgError, "mysql_stmt_attr_set() failed");
     st_obj = Data_Make_Struct(cMysqlStmt, struct mysql_stmt, 0, free_mysqlstmt, stmt);
     memset(stmt, 0, sizeof(*stmt));
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
 
@@ -1029,7 +1043,7 @@ static VALUE fetch_row(VALUE obj)
 	return Qnil;
     ary = rb_ary_new2(n);
     for (i=0; i<n; i++)
-	rb_ary_store(ary, i, row[i]? rb_tainted_str_new(row[i], lengths[i]): Qnil);
+	rb_ary_store(ary, i, row[i]? rb_str_new(row[i], lengths[i]): Qnil);
     return ary;
 }
 
@@ -1053,7 +1067,7 @@ static VALUE fetch_hash2(VALUE obj, VALUE with_table)
         if (colname == Qnil) {
             colname = rb_ary_new2(n);
             for (i=0; i<n; i++) {
-                VALUE s = rb_tainted_str_new2(fields[i].name);
+                VALUE s = rb_str_new_cstr(fields[i].name);
                 rb_obj_freeze(s);
                 rb_ary_store(colname, i, s);
             }
@@ -1066,7 +1080,7 @@ static VALUE fetch_hash2(VALUE obj, VALUE with_table)
             colname = rb_ary_new2(n);
             for (i=0; i<n; i++) {
                 int len = strlen(fields[i].table)+strlen(fields[i].name)+1;
-                VALUE s = rb_tainted_str_new(NULL, len);
+                VALUE s = rb_str_new(NULL, len);
                 snprintf(RSTRING_PTR(s), len+1, "%s.%s", fields[i].table, fields[i].name);
                 rb_obj_freeze(s);
                 rb_ary_store(colname, i, s);
@@ -1076,7 +1090,7 @@ static VALUE fetch_hash2(VALUE obj, VALUE with_table)
         }
     }
     for (i=0; i<n; i++) {
-        rb_hash_aset(hash, rb_ary_entry(colname, i), row[i]? rb_tainted_str_new(row[i], lengths[i]): Qnil);
+        rb_hash_aset(hash, rb_ary_entry(colname, i), row[i]? rb_str_new(row[i], lengths[i]): Qnil);
     }
     return hash;
 }
@@ -1257,7 +1271,7 @@ static void mysql_stmt_raise(MYSQL_STMT* s)
 {
     VALUE e = rb_exc_new2(eMysql, mysql_stmt_error(s));
     rb_iv_set(e, "errno", INT2FIX(mysql_stmt_errno(s)));
-    rb_iv_set(e, "sqlstate", rb_tainted_str_new2(mysql_stmt_sqlstate(s)));
+    rb_iv_set(e, "sqlstate", rb_str_new_cstr(mysql_stmt_sqlstate(s)));
     rb_exc_raise(e);
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
@@ -1573,7 +1587,7 @@ static VALUE stmt_fetch(VALUE obj)
             case MYSQL_TYPE_NEWDECIMAL:
             case MYSQL_TYPE_BIT:
 #endif
-                v = rb_tainted_str_new(s->result.bind[i].buffer, s->result.length[i]);
+                v = rb_str_new(s->result.bind[i].buffer, s->result.length[i]);
                 break;
             default:
                 rb_raise(rb_eTypeError, "unknown buffer_type: %d", s->result.bind[i].buffer_type);
@@ -1762,7 +1776,7 @@ static VALUE stmt_send_long_data(VALUE obj, VALUE col,
 static VALUE stmt_sqlstate(VALUE obj)
 {
     struct mysql_stmt* s = DATA_PTR(obj);
-    return rb_tainted_str_new2(mysql_stmt_sqlstate(s->stmt));
+    return rb_str_new_cstr(mysql_stmt_sqlstate(s->stmt));
 }
 
 /*-------------------------------
@@ -1884,6 +1898,7 @@ static VALUE error_sqlstate(VALUE obj)
 
 void Init_mysql_api(void)
 {
+#if 0
     int i;
     int dots = 0;
     const char *lib = mysql_get_client_info();
@@ -1898,9 +1913,12 @@ void Init_mysql_api(void)
             return;
         }
     }
+#endif
 
     cMysql = rb_define_class("Mysql", rb_cObject);
+    rb_undef_alloc_func(cMysql);
     cMysqlRes = rb_define_class_under(cMysql, "Result", rb_cObject);
+    rb_undef_alloc_func(cMysqlRes);
     cMysqlField = rb_define_class_under(cMysql, "Field", rb_cObject);
 #if MYSQL_VERSION_ID >= 40102
     cMysqlStmt = rb_define_class_under(cMysql, "Stmt", rb_cObject);

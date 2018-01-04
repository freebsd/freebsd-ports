--- ext/mysql_api/mysql.c.orig	2018-01-03 15:47:52 UTC
+++ ext/mysql_api/mysql.c
@@ -1317,7 +1317,7 @@ static VALUE stmt_bind_result(int argc, 
 	}
 	else if (argv[i] == rb_cString)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_STRING;
-	else if (argv[i] == rb_cNumeric || argv[i] == rb_cInteger || argv[i] == rb_cFixnum)
+	else if (argv[i] == rb_cNumeric || argv[i] == rb_cInteger || argv[i] == rb_cInteger)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_LONGLONG;
 	else if (argv[i] == rb_cFloat)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_DOUBLE;

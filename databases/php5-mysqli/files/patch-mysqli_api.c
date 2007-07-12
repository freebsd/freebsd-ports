--- mysqli_api.c.orig	Thu Jul 12 09:52:10 2007
+++ mysqli_api.c	Thu Jul 12 09:52:24 2007
@@ -141,13 +141,13 @@
 		switch (types[ofs]) {
 			case 'd': /* Double */
 				bind[ofs].buffer_type = MYSQL_TYPE_DOUBLE;
-				bind[ofs].buffer = (gptr)&Z_DVAL_PP(args[i]);
+				bind[ofs].buffer = (void*)&Z_DVAL_PP(args[i]);
 				bind[ofs].is_null = &stmt->param.is_null[ofs];
 				break;
 
 			case 'i': /* Integer */
 				bind[ofs].buffer_type = MYSQL_TYPE_LONG;
-				bind[ofs].buffer = (gptr)&Z_LVAL_PP(args[i]);
+				bind[ofs].buffer = (void*)&Z_LVAL_PP(args[i]);
 				bind[ofs].is_null = &stmt->param.is_null[ofs];
 				break;
 
@@ -600,11 +600,11 @@
 						break;
 					case MYSQL_TYPE_DOUBLE:
 						convert_to_double_ex(&stmt->param.vars[i]);
-						stmt->stmt->params[i].buffer = (gptr)&Z_LVAL_PP(&stmt->param.vars[i]);
+						stmt->stmt->params[i].buffer = (void*)&Z_LVAL_PP(&stmt->param.vars[i]);
 						break;
 					case MYSQL_TYPE_LONG:
 						convert_to_long_ex(&stmt->param.vars[i]);
-						stmt->stmt->params[i].buffer = (gptr)&Z_LVAL_PP(&stmt->param.vars[i]);
+						stmt->stmt->params[i].buffer = (void*)&Z_LVAL_PP(&stmt->param.vars[i]);
 						break;
 					default:
 						break;

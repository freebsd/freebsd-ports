--- src/ls_mysql.c	2007/08/22 18:37:06	1.24
+++ src/ls_mysql.c	2008/02/18 05:14:09	1.28
@@ -362,6 +362,22 @@ static int conn_close (lua_State *L) {
 }
 
 
+static int escape_string (lua_State *L) {
+  size_t size, new_size;
+  conn_data *conn = getconnection (L);
+  const char *from = luaL_checklstring(L, 2, &size);
+  char *to;
+  to = (char*)malloc(sizeof(char) * (2 * size + 1));
+  if(to) {
+    new_size = mysql_real_escape_string(conn->my_conn, to, from, size);
+    lua_pushlstring(L, to, new_size);
+    free(to);
+    return 1;
+  }
+  luaL_error(L, "could not allocate escaped string");
+  return 0;
+}
+
 /*
 ** Execute an SQL statement.
 ** Return a Cursor object if the statement is a query, otherwise
@@ -385,8 +385,8 @@ static int escape_string (lua_State *L) 
 */
 static int conn_execute (lua_State *L) {
 	conn_data *conn = getconnection (L);
-	const char *statement = luaL_checkstring (L, 2);
-	unsigned long st_len = strlen(statement);
+	size_t st_len;
+	const char *statement = luaL_checklstring (L, 2, &st_len);
 	if (mysql_real_query(conn->my_conn, statement, st_len)) 
 		/* error executing query */
 		return luasql_failmessage(L, "Error executing query. MySQL: ", mysql_error(conn->my_conn));
@@ -400,8 +416,8 @@ static int conn_execute (lua_State *L) {
 */
 static int conn_commit (lua_State *L) {
 	conn_data *conn = getconnection (L);
-	mysql_commit(conn->my_conn);
-	return 0;
+	lua_pushboolean(L, !mysql_commit(conn->my_conn));
+	return 1;
 }
 
 
@@ -410,8 +426,8 @@ static int conn_commit (lua_State *L) {
 */
 static int conn_rollback (lua_State *L) {
 	conn_data *conn = getconnection (L);
-	mysql_rollback(conn->my_conn);
-	return 0;
+	lua_pushboolean(L, !mysql_rollback(conn->my_conn));
+	return 1;
 }
 
 
@@ -432,6 +448,15 @@ static int conn_setautocommit (lua_State
 
 
 /*
+** Get Last auto-increment id generated
+*/
+static int conn_getlastautoid (lua_State *L) {
+  conn_data *conn = getconnection(L);
+  lua_pushnumber(L, mysql_insert_id(conn->my_conn));
+  return 1;
+}
+
+/*
 ** Create a new Connection object and push it on top of the stack.
 */
 static int create_connection (lua_State *L, int env, MYSQL *const my_conn) {
@@ -507,10 +532,12 @@ static void create_metatables (lua_State
 	};
     struct luaL_reg connection_methods[] = {
         {"close", conn_close},
+        {"escape", escape_string},
         {"execute", conn_execute},
         {"commit", conn_commit},
         {"rollback", conn_rollback},
         {"setautocommit", conn_setautocommit},
+	{"getlastautoid", conn_getlastautoid},
 		{NULL, NULL},
     };
     struct luaL_reg cursor_methods[] = {

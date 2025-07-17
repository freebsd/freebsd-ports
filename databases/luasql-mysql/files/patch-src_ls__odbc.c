--- src/ls_odbc.c.orig	2025-07-17 01:23:45 UTC
+++ src/ls_odbc.c
@@ -493,6 +493,16 @@ static int cur_fetch (lua_State *L)
 }
 
 /*
+** Cursor object collector function
+*/
+static int cur_gc (lua_State *L) {
+	cur_data *cur = (cur_data *) luaL_checkudata (L, 1, LUASQL_CURSOR_ODBC);
+	if (cur != NULL && !(cur->closed))
+		cur_shut(L, cur);
+	return 0;
+}
+
+/*
 ** Closes a cursor.
 */
 static int cur_close (lua_State *L)

--- src/ls_sqlite3.c	2007/10/16 15:36:08	1.7
+++ src/ls_sqlite3.c	2008/04/24 17:37:45	1.10
@@ -28,27 +28,28 @@
 
 typedef struct
 {
-    short       closed;
+  short       closed;
 } env_data;
 
 
 typedef struct
 {
-	short        closed;
-	int          env;                /* reference to environment */
-	short        auto_commit;        /* 0 for manual commit */
-	unsigned int cur_counter;          
-	sqlite3      *sql_conn;
+  short        closed;
+  int          env;                /* reference to environment */
+  short        auto_commit;        /* 0 for manual commit */
+  unsigned int cur_counter;          
+  sqlite3      *sql_conn;
 } conn_data;
 
 
 typedef struct
 {
-	short       closed;
-	int         conn;               /* reference to connection */
-	int         numcols;            /* number of columns */
-	int         colnames, coltypes; /* reference to column information tables */
-	sqlite3_stmt  *sql_vm;
+  short       closed;
+  int         conn;               /* reference to connection */
+  int         numcols;            /* number of columns */
+  int         colnames, coltypes; /* reference to column information tables */
+  conn_data   *conn_data;         /* reference to connection for cursor */
+  sqlite3_stmt  *sql_vm;
 } cur_data;
 
 LUASQL_API int luaopen_luasql_sqlite3(lua_State *L);
@@ -58,10 +59,10 @@ LUASQL_API int luaopen_luasql_sqlite3(lu
 ** Check for valid environment.
 */
 static env_data *getenvironment(lua_State *L) {
-	env_data *env = (env_data *)luaL_checkudata(L, 1, LUASQL_ENVIRONMENT_SQLITE);
-	luaL_argcheck(L, env != NULL, 1, LUASQL_PREFIX"environment expected");
-	luaL_argcheck(L, !env->closed, 1, LUASQL_PREFIX"environment is closed");
-	return env;
+  env_data *env = (env_data *)luaL_checkudata(L, 1, LUASQL_ENVIRONMENT_SQLITE);
+  luaL_argcheck(L, env != NULL, 1, LUASQL_PREFIX"environment expected");
+  luaL_argcheck(L, !env->closed, 1, LUASQL_PREFIX"environment is closed");
+  return env;
 }
 
 
@@ -69,10 +70,10 @@ static env_data *getenvironment(lua_Stat
 ** Check for valid connection.
 */
 static conn_data *getconnection(lua_State *L) {
-	conn_data *conn = (conn_data *)luaL_checkudata (L, 1, LUASQL_CONNECTION_SQLITE);
-	luaL_argcheck(L, conn != NULL, 1, LUASQL_PREFIX"connection expected");
-	luaL_argcheck(L, !conn->closed, 1, LUASQL_PREFIX"connection is closed");
-	return conn;
+  conn_data *conn = (conn_data *)luaL_checkudata (L, 1, LUASQL_CONNECTION_SQLITE);
+  luaL_argcheck(L, conn != NULL, 1, LUASQL_PREFIX"connection expected");
+  luaL_argcheck(L, !conn->closed, 1, LUASQL_PREFIX"connection is closed");
+  return conn;
 }
 
 
@@ -80,10 +81,10 @@ static conn_data *getconnection(lua_Stat
 ** Check for valid cursor.
 */
 static cur_data *getcursor(lua_State *L) {
-	cur_data *cur = (cur_data *)luaL_checkudata (L, 1, LUASQL_CURSOR_SQLITE);
-	luaL_argcheck(L, cur != NULL, 1, LUASQL_PREFIX"cursor expected");
-	luaL_argcheck(L, !cur->closed, 1, LUASQL_PREFIX"cursor is closed");
-	return cur;
+  cur_data *cur = (cur_data *)luaL_checkudata (L, 1, LUASQL_CURSOR_SQLITE);
+  luaL_argcheck(L, cur != NULL, 1, LUASQL_PREFIX"cursor expected");
+  luaL_argcheck(L, !cur->closed, 1, LUASQL_PREFIX"cursor is closed");
+  return cur;
 }
 
 /*
@@ -91,80 +92,105 @@ static cur_data *getcursor(lua_State *L)
 ** Return nil + errmsg or nil in case of sucess
 */
 static int finalize(lua_State *L, cur_data *cur) {
-    const char *errmsg;
-    if (sqlite3_finalize(cur->sql_vm) != SQLITE_OK)
+  const char *errmsg;
+  if (sqlite3_finalize(cur->sql_vm) != SQLITE_OK)
     {
-        errmsg = sqlite3_errmsg(sqlite3_db_handle(cur->sql_vm));
-        cur->sql_vm = NULL;
-        lua_pushnil(L);
-        lua_pushliteral(L, LUASQL_PREFIX);
-        lua_pushstring(L, errmsg);
-        lua_concat(L, 2);
-        return 2;
+      errmsg = sqlite3_errmsg(cur->conn_data->sql_conn);
+      cur->sql_vm = NULL;
+      lua_pushnil(L);
+      lua_pushliteral(L, LUASQL_PREFIX);
+      lua_pushstring(L, errmsg);
+      lua_concat(L, 2);
+      return 2;
     }
-    cur->sql_vm = NULL;
-    lua_pushnil(L);
-    return 1;
+  cur->sql_vm = NULL;
+  lua_pushnil(L);
+  return 1;
 }
 
 
+static void push_column(lua_State *L, sqlite3_stmt *vm, int column) {
+  switch (sqlite3_column_type(vm, column)) {
+  case SQLITE_INTEGER:
+    lua_pushinteger(L, sqlite3_column_int64(vm, column));
+    break;
+  case SQLITE_FLOAT:
+    lua_pushnumber(L, sqlite3_column_double(vm, column));
+    break;
+  case SQLITE_TEXT:
+    lua_pushlstring(L, sqlite3_column_text(vm, column),
+		    sqlite3_column_bytes(vm, column));
+    break;
+  case SQLITE_BLOB:
+    lua_pushlstring(L, sqlite3_column_blob(vm, column),
+		    sqlite3_column_bytes(vm, column));
+    break;
+  case SQLITE_NULL:
+    lua_pushnil(L);
+    break;
+  default:
+    luaL_error(L, LUASQL_PREFIX"Unrecognized column type");
+    break;
+  }
+}
+
 /*
 ** Get another row of the given cursor.
 */
 static int cur_fetch (lua_State *L) {
-    cur_data *cur = getcursor(L);
-    sqlite3_stmt *vm = cur->sql_vm;
-    int res;
+  cur_data *cur = getcursor(L);
+  sqlite3_stmt *vm = cur->sql_vm;
+  int res;
 
-    if (vm == NULL)
-        return 0;
+  if (vm == NULL)
+    return 0;
 
-    res = sqlite3_step(vm);
+  res = sqlite3_step(vm);
 
-    /* no more results? */
-    if (res == SQLITE_DONE)
-        return finalize(L, cur);
+  /* no more results? */
+  if (res == SQLITE_DONE)
+    return finalize(L, cur);
 
-    if (res != SQLITE_ROW)
-        return finalize(L, cur);
+  if (res != SQLITE_ROW)
+    return finalize(L, cur);
 
-	if (lua_istable (L, 2))
+  if (lua_istable (L, 2))
     {
-		int i;
-		const char *opts = luaL_optstring(L, 3, "n");
+      int i;
+      const char *opts = luaL_optstring(L, 3, "n");
 
-		if (strchr(opts, 'n') != NULL)
+      if (strchr(opts, 'n') != NULL)
         {
-			/* Copy values to numerical indices */
-			for (i = 0; i < cur->numcols;)
+	  /* Copy values to numerical indices */
+	  for (i = 0; i < cur->numcols;)
             {
-	            lua_pushstring(L, (const char *)sqlite3_column_text(vm, i));
-				lua_rawseti(L, 2, ++i);
-			}
+	      push_column(L, vm, i);
+	      lua_rawseti(L, 2, ++i);
+	    }
         }
-		if (strchr(opts, 'a') != NULL)
+      if (strchr(opts, 'a') != NULL)
         {
-			/* Copy values to alphanumerical indices */
-            lua_rawgeti(L, LUA_REGISTRYINDEX, cur->colnames);
+	  /* Copy values to alphanumerical indices */
+	  lua_rawgeti(L, LUA_REGISTRYINDEX, cur->colnames);
 
-			for (i = 0; i < cur->numcols; i++)
+	  for (i = 0; i < cur->numcols; i++)
             {
-				lua_rawgeti(L, -1, i+1);
-				lua_pushstring(L, (const char*)sqlite3_column_text(vm,i));
-				lua_rawset (L, 2);
-			}
+	      lua_rawgeti(L, -1, i+1);
+	      push_column(L, vm, i);
+	      lua_rawset (L, 2);
+	    }
         }
-		lua_pushvalue(L, 2);
-		return 1; /* return table */
-	}
-	else
-    {
-		int i;
-		luaL_checkstack (L, cur->numcols, LUASQL_PREFIX"too many columns");
-		for (i = 0; i < cur->numcols; ++i)
-		  lua_pushstring(L, (const char *)sqlite3_column_text(vm, i));
-		return cur->numcols; /* return #numcols values */
-	}
+      lua_pushvalue(L, 2);
+      return 1; /* return table */
+    }
+  else
+    {
+      int i;
+      luaL_checkstack (L, cur->numcols, LUASQL_PREFIX"too many columns");
+      for (i = 0; i < cur->numcols; ++i)
+	push_column(L, vm, i);
+      return cur->numcols; /* return #numcols values */
+    }
 }
 
 
@@ -174,28 +200,28 @@ static int cur_fetch (lua_State *L) {
 */
 static int cur_close(lua_State *L)
 {
-	conn_data *conn;
-	cur_data *cur = (cur_data *)luaL_checkudata(L, 1, LUASQL_CURSOR_SQLITE);
-	luaL_argcheck(L, cur != NULL, 1, LUASQL_PREFIX"cursor expected");
-	if (cur->closed) {
-		lua_pushboolean(L, 0);
-		return 1;
-	}
-
-	/* Nullify structure fields. */
-	cur->closed = 1;
-	sqlite3_finalize(cur->sql_vm);
-	/* Decrement cursor counter on connection object */
-	lua_rawgeti (L, LUA_REGISTRYINDEX, cur->conn);
-	conn = lua_touserdata (L, -1);
-	conn->cur_counter--;
-
-	luaL_unref(L, LUA_REGISTRYINDEX, cur->conn);
-	luaL_unref(L, LUA_REGISTRYINDEX, cur->colnames);
-	luaL_unref(L, LUA_REGISTRYINDEX, cur->coltypes);
+  conn_data *conn;
+  cur_data *cur = (cur_data *)luaL_checkudata(L, 1, LUASQL_CURSOR_SQLITE);
+  luaL_argcheck(L, cur != NULL, 1, LUASQL_PREFIX"cursor expected");
+  if (cur->closed) {
+    lua_pushboolean(L, 0);
+    return 1;
+  }
 
-	lua_pushboolean(L, 1);
-	return 1;
+  /* Nullify structure fields. */
+  cur->closed = 1;
+  sqlite3_finalize(cur->sql_vm);
+  /* Decrement cursor counter on connection object */
+  lua_rawgeti (L, LUA_REGISTRYINDEX, cur->conn);
+  conn = lua_touserdata (L, -1);
+  conn->cur_counter--;
+
+  luaL_unref(L, LUA_REGISTRYINDEX, cur->conn);
+  luaL_unref(L, LUA_REGISTRYINDEX, cur->colnames);
+  luaL_unref(L, LUA_REGISTRYINDEX, cur->coltypes);
+
+  lua_pushboolean(L, 1);
+  return 1;
 }
 
 
@@ -204,9 +230,9 @@ static int cur_close(lua_State *L)
 */
 static int cur_getcolnames(lua_State *L)
 {
-    cur_data *cur = getcursor(L);
-    lua_rawgeti(L, LUA_REGISTRYINDEX, cur->colnames);
-	return 1;
+  cur_data *cur = getcursor(L);
+  lua_rawgeti(L, LUA_REGISTRYINDEX, cur->colnames);
+  return 1;
 }
 
 
@@ -215,9 +241,9 @@ static int cur_getcolnames(lua_State *L)
 */
 static int cur_getcoltypes(lua_State *L)
 {
-    cur_data *cur = getcursor(L);
-    lua_rawgeti(L, LUA_REGISTRYINDEX, cur->coltypes);
-	return 1;
+  cur_data *cur = getcursor(L);
+  lua_rawgeti(L, LUA_REGISTRYINDEX, cur->coltypes);
+  return 1;
 }
 
 
@@ -225,47 +251,48 @@ static int cur_getcoltypes(lua_State *L)
 ** Create a new Cursor object and push it on top of the stack.
 */
 /* static int create_cursor(lua_State *L, int conn, sqlite3_stmt *sql_vm,
-    int numcols, const char **row, const char **col_info)*/
+   int numcols, const char **row, const char **col_info)*/
 static int create_cursor(lua_State *L, int o, conn_data *conn, 
-		sqlite3_stmt *sql_vm, int numcols)
+			 sqlite3_stmt *sql_vm, int numcols)
 {
-    int i;
-	cur_data *cur = (cur_data*)lua_newuserdata(L, sizeof(cur_data));
-	luasql_setmeta (L, LUASQL_CURSOR_SQLITE);
-
-	/* increment cursor count for the connection creating this cursor */
-	conn->cur_counter++;
-
-	/* fill in structure */
-	cur->closed = 0;
-	cur->conn = LUA_NOREF;
-	cur->numcols = numcols;
-	cur->colnames = LUA_NOREF;
-	cur->coltypes = LUA_NOREF;
-	cur->sql_vm = sql_vm;
-
-    lua_pushvalue(L, o);
-	cur->conn = luaL_ref(L, LUA_REGISTRYINDEX);
-
-    /* create table with column names */
-    lua_newtable(L);
-    for (i = 0; i < numcols;)
+  int i;
+  cur_data *cur = (cur_data*)lua_newuserdata(L, sizeof(cur_data));
+  luasql_setmeta (L, LUASQL_CURSOR_SQLITE);
+
+  /* increment cursor count for the connection creating this cursor */
+  conn->cur_counter++;
+
+  /* fill in structure */
+  cur->closed = 0;
+  cur->conn = LUA_NOREF;
+  cur->numcols = numcols;
+  cur->colnames = LUA_NOREF;
+  cur->coltypes = LUA_NOREF;
+  cur->sql_vm = sql_vm;
+  cur->conn_data = conn;
+
+  lua_pushvalue(L, o);
+  cur->conn = luaL_ref(L, LUA_REGISTRYINDEX);
+
+  /* create table with column names */
+  lua_newtable(L);
+  for (i = 0; i < numcols;)
     {
-        lua_pushstring(L, sqlite3_column_name(sql_vm, i));
-        lua_rawseti(L, -2, ++i);
+      lua_pushstring(L, sqlite3_column_name(sql_vm, i));
+      lua_rawseti(L, -2, ++i);
     }
-    cur->colnames = luaL_ref(L, LUA_REGISTRYINDEX);
-
-    /* create table with column types */
-    lua_newtable(L);
-    for (i = 0; i < numcols;)
+  cur->colnames = luaL_ref(L, LUA_REGISTRYINDEX);
+	
+  /* create table with column types */
+  lua_newtable(L);
+  for (i = 0; i < numcols;)
     {
-        lua_pushstring(L, sqlite3_column_decltype(sql_vm, i));
-        lua_rawseti(L, -2, ++i);
+      lua_pushstring(L, sqlite3_column_decltype(sql_vm, i));
+      lua_rawseti(L, -2, ++i);
     }
-    cur->coltypes = luaL_ref(L, LUA_REGISTRYINDEX);
+  cur->coltypes = luaL_ref(L, LUA_REGISTRYINDEX);
 
-	return 1;
+  return 1;
 }
 
 
@@ -274,39 +301,39 @@ static int create_cursor(lua_State *L, i
 */
 static int conn_close(lua_State *L)
 {
-	conn_data *conn = (conn_data *)luaL_checkudata(L, 1, LUASQL_CONNECTION_SQLITE);
-	luaL_argcheck (L, conn != NULL, 1, LUASQL_PREFIX"connection expected");
-	if (conn->closed) 
-	{
-		lua_pushboolean(L, 0);
-		return 1;
-	}
-
-	if (conn->cur_counter > 0)
-		return luaL_error (L, LUASQL_PREFIX"there are open cursors");
-
-	/* Nullify structure fields. */
-	conn->closed = 1;
-	luaL_unref(L, LUA_REGISTRYINDEX, conn->env);
-	sqlite3_close(conn->sql_conn);
-	lua_pushboolean(L, 1);
-	return 1;
+  conn_data *conn = (conn_data *)luaL_checkudata(L, 1, LUASQL_CONNECTION_SQLITE);
+  luaL_argcheck (L, conn != NULL, 1, LUASQL_PREFIX"connection expected");
+  if (conn->closed) 
+    {
+      lua_pushboolean(L, 0);
+      return 1;
+    }
+
+  if (conn->cur_counter > 0)
+    return luaL_error (L, LUASQL_PREFIX"there are open cursors");
+
+  /* Nullify structure fields. */
+  conn->closed = 1;
+  luaL_unref(L, LUA_REGISTRYINDEX, conn->env);
+  sqlite3_close(conn->sql_conn);
+  lua_pushboolean(L, 1);
+  return 1;
 }
 
 static int conn_escape(lua_State *L)
 {
-	const char *from = luaL_checklstring (L, 2, 0);
-    char *escaped = sqlite3_mprintf("%q", from);
-    if (escaped == NULL) 
+  const char *from = luaL_checklstring (L, 2, 0);
+  char *escaped = sqlite3_mprintf("%q", from);
+  if (escaped == NULL) 
     {
-        lua_pushnil(L);
+      lua_pushnil(L);
     } 
-    else
+  else
     {
-        lua_pushstring(L, escaped);        
-        sqlite3_free(escaped);
+      lua_pushstring(L, escaped);        
+      sqlite3_free(escaped);
     }
-    return 1;
+  return 1;
 }
 
 /*
@@ -316,52 +343,52 @@ static int conn_escape(lua_State *L)
 */
 static int conn_execute(lua_State *L)
 {
-    conn_data *conn = getconnection(L);
-    const char *statement = luaL_checkstring(L, 2);
-    int res;
-    sqlite3_stmt *vm;
-    const char *errmsg;
-    int numcols;
-    const char *tail;
-
-    res = sqlite3_prepare(conn->sql_conn, statement, -1, &vm, &tail);
-    if (res != SQLITE_OK)
-    {
-        errmsg = sqlite3_errmsg(conn->sql_conn);
-        lua_pushnil(L);
-        lua_pushliteral(L, LUASQL_PREFIX);
-        lua_pushstring(L, errmsg);
-        lua_concat(L, 2);
-        return 2;
-    }
-
-    /* process first result to retrive query information and type */
-    res = sqlite3_step(vm);
-    numcols = sqlite3_column_count(vm);
-
-    /* real query? if empty, must have numcols!=0 */
-	if ((res == SQLITE_ROW) || ((res == SQLITE_DONE) && numcols))
-	{
-		sqlite3_reset(vm);
-		return create_cursor(L, 1, conn, vm, numcols);
-	}
-
-    if (res == SQLITE_DONE) /* and numcols==0, INSERT,UPDATE,DELETE statement */
-    {
-        sqlite3_finalize(vm);
-        /* return number of columns changed */
-        lua_pushnumber(L, sqlite3_changes(conn->sql_conn));
-        return 1;
-    }
-
-    /* error */
-    errmsg = sqlite3_errmsg(sqlite3_db_handle(vm));
-    sqlite3_finalize(vm);
-    lua_pushnil(L);
-    lua_pushliteral(L, LUASQL_PREFIX);
-    lua_pushstring(L, errmsg);
-    lua_concat(L, 2);
-    return 2;
+  conn_data *conn = getconnection(L);
+  const char *statement = luaL_checkstring(L, 2);
+  int res;
+  sqlite3_stmt *vm;
+  const char *errmsg;
+  int numcols;
+  const char *tail;
+
+  res = sqlite3_prepare(conn->sql_conn, statement, -1, &vm, &tail);
+  if (res != SQLITE_OK)
+    {
+      errmsg = sqlite3_errmsg(conn->sql_conn);
+      lua_pushnil(L);
+      lua_pushliteral(L, LUASQL_PREFIX);
+      lua_pushstring(L, errmsg);
+      lua_concat(L, 2);
+      return 2;
+    }
+
+  /* process first result to retrive query information and type */
+  res = sqlite3_step(vm);
+  numcols = sqlite3_column_count(vm);
+
+  /* real query? if empty, must have numcols!=0 */
+  if ((res == SQLITE_ROW) || ((res == SQLITE_DONE) && numcols))
+    {
+      sqlite3_reset(vm);
+      return create_cursor(L, 1, conn, vm, numcols);
+    }
+
+  if (res == SQLITE_DONE) /* and numcols==0, INSERT,UPDATE,DELETE statement */
+    {
+      sqlite3_finalize(vm);
+      /* return number of columns changed */
+      lua_pushnumber(L, sqlite3_changes(conn->sql_conn));
+      return 1;
+    }
+
+  /* error */
+  errmsg = sqlite3_errmsg(conn->sql_conn);
+  sqlite3_finalize(vm);
+  lua_pushnil(L);
+  lua_pushliteral(L, LUASQL_PREFIX);
+  lua_pushstring(L, errmsg);
+  lua_concat(L, 2);
+  return 2;
 }
 
 
@@ -370,26 +397,26 @@ static int conn_execute(lua_State *L)
 */
 static int conn_commit(lua_State *L)
 {
-    char *errmsg;
-	conn_data *conn = getconnection(L);
-	int res;
-    const char *sql = "COMMIT";
-
-    if (conn->auto_commit == 0) sql = "COMMIT;BEGIN";
-
-    res = sqlite3_exec(conn->sql_conn, sql, NULL, NULL, &errmsg);
-
-    if (res != SQLITE_OK)
-    {
-		lua_pushnil(L);
-        lua_pushliteral(L, LUASQL_PREFIX);
-        lua_pushstring(L, errmsg);
-        sqlite3_free(errmsg);
-        lua_concat(L, 2);
-        return 2;
+  char *errmsg;
+  conn_data *conn = getconnection(L);
+  int res;
+  const char *sql = "COMMIT";
+
+  if (conn->auto_commit == 0) sql = "COMMIT;BEGIN";
+
+  res = sqlite3_exec(conn->sql_conn, sql, NULL, NULL, &errmsg);
+
+  if (res != SQLITE_OK)
+    {
+      lua_pushnil(L);
+      lua_pushliteral(L, LUASQL_PREFIX);
+      lua_pushstring(L, errmsg);
+      sqlite3_free(errmsg);
+      lua_concat(L, 2);
+      return 2;
     }
-    lua_pushboolean(L, 1);
-	return 1;
+  lua_pushboolean(L, 1);
+  return 1;
 }
 
 
@@ -398,25 +425,25 @@ static int conn_commit(lua_State *L)
 */
 static int conn_rollback(lua_State *L)
 {
-    char *errmsg;
-	conn_data *conn = getconnection(L);
-	int res;
-    const char *sql = "ROLLBACK";
-
-    if (conn->auto_commit == 0) sql = "ROLLBACK;BEGIN";
-
-    res = sqlite3_exec(conn->sql_conn, sql, NULL, NULL, &errmsg);
-    if (res != SQLITE_OK)
-    {
-		lua_pushnil(L);
-        lua_pushliteral(L, LUASQL_PREFIX);
-        lua_pushstring(L, errmsg);
-        sqlite3_free(errmsg);
-        lua_concat(L, 2);
-        return 2;
+  char *errmsg;
+  conn_data *conn = getconnection(L);
+  int res;
+  const char *sql = "ROLLBACK";
+
+  if (conn->auto_commit == 0) sql = "ROLLBACK;BEGIN";
+
+  res = sqlite3_exec(conn->sql_conn, sql, NULL, NULL, &errmsg);
+  if (res != SQLITE_OK)
+    {
+      lua_pushnil(L);
+      lua_pushliteral(L, LUASQL_PREFIX);
+      lua_pushstring(L, errmsg);
+      sqlite3_free(errmsg);
+      lua_concat(L, 2);
+      return 2;
     }
-    lua_pushboolean(L, 1);
-	return 1;
+  lua_pushboolean(L, 1);
+  return 1;
 }
 
 static int conn_getlastautoid(lua_State *L)
@@ -434,30 +461,30 @@ static int conn_getlastautoid(lua_State 
 */
 static int conn_setautocommit(lua_State *L)
 {
-	conn_data *conn = getconnection(L);
-	if (lua_toboolean(L, 2))
+  conn_data *conn = getconnection(L);
+  if (lua_toboolean(L, 2))
+    {
+      conn->auto_commit = 1;
+      /* undo active transaction - ignore errors */
+      sqlite3_exec(conn->sql_conn, "ROLLBACK", NULL, NULL, NULL);
+    }
+  else
     {
-		conn->auto_commit = 1;
-        /* undo active transaction - ignore errors */
-        sqlite3_exec(conn->sql_conn, "ROLLBACK", NULL, NULL, NULL);
-	}
-	else
-    {
-        char *errmsg;
-        int res;
-		conn->auto_commit = 0;
-        res = sqlite3_exec(conn->sql_conn, "BEGIN", NULL, NULL, &errmsg);
-        if (res != SQLITE_OK)
+      char *errmsg;
+      int res;
+      conn->auto_commit = 0;
+      res = sqlite3_exec(conn->sql_conn, "BEGIN", NULL, NULL, &errmsg);
+      if (res != SQLITE_OK)
         {
-            lua_pushliteral(L, LUASQL_PREFIX);
-            lua_pushstring(L, errmsg);
-            sqlite3_free(errmsg);
-            lua_concat(L, 2);
-            lua_error(L);
+	  lua_pushliteral(L, LUASQL_PREFIX);
+	  lua_pushstring(L, errmsg);
+	  sqlite3_free(errmsg);
+	  lua_concat(L, 2);
+	  lua_error(L);
         }
-	}
-	lua_pushboolean(L, 1);
-	return 1;
+    }
+  lua_pushboolean(L, 1);
+  return 1;
 }
 
 
@@ -466,18 +493,18 @@ static int conn_setautocommit(lua_State 
 */
 static int create_connection(lua_State *L, int env, sqlite3 *sql_conn)
 {
-	conn_data *conn = (conn_data*)lua_newuserdata(L, sizeof(conn_data));
-	luasql_setmeta(L, LUASQL_CONNECTION_SQLITE);
+  conn_data *conn = (conn_data*)lua_newuserdata(L, sizeof(conn_data));
+  luasql_setmeta(L, LUASQL_CONNECTION_SQLITE);
 
-	/* fill in structure */
-	conn->closed = 0;
-	conn->env = LUA_NOREF;
-	conn->auto_commit = 1;
-	conn->sql_conn = sql_conn;
-	conn->cur_counter = 0;
-	lua_pushvalue (L, env);
-	conn->env = luaL_ref (L, LUA_REGISTRYINDEX);
-	return 1;
+  /* fill in structure */
+  conn->closed = 0;
+  conn->env = LUA_NOREF;
+  conn->auto_commit = 1;
+  conn->sql_conn = sql_conn;
+  conn->cur_counter = 0;
+  lua_pushvalue (L, env);
+  conn->env = luaL_ref (L, LUA_REGISTRYINDEX);
+  return 1;
 }
 
 
@@ -486,24 +513,24 @@ static int create_connection(lua_State *
 */
 static int env_connect(lua_State *L)
 {
-    const char *sourcename;
-    sqlite3 *conn;
-    const char *errmsg;
-    int res;
-    getenvironment(L);  /* validate environment */
-    sourcename = luaL_checkstring(L, 2);
-    res = sqlite3_open(sourcename, &conn);
-    if (res != SQLITE_OK)
-    {
-        errmsg = sqlite3_errmsg(conn);
-        lua_pushnil(L);
-        lua_pushliteral(L, LUASQL_PREFIX);
-        lua_pushstring(L, errmsg);
-        lua_concat(L, 2);
-	sqlite3_close(conn);
-        return 2;
+  const char *sourcename;
+  sqlite3 *conn;
+  const char *errmsg;
+  int res;
+  getenvironment(L);  /* validate environment */
+  sourcename = luaL_checkstring(L, 2);
+  res = sqlite3_open(sourcename, &conn);
+  if (res != SQLITE_OK)
+    {
+      errmsg = sqlite3_errmsg(conn);
+      lua_pushnil(L);
+      lua_pushliteral(L, LUASQL_PREFIX);
+      lua_pushstring(L, errmsg);
+      lua_concat(L, 2);
+      sqlite3_close(conn);
+      return 2;
     }
-    return create_connection(L, 1, conn);
+  return create_connection(L, 1, conn);
 }
 
 
@@ -512,16 +539,16 @@ static int env_connect(lua_State *L)
 */
 static int env_close (lua_State *L)
 {
-	env_data *env = (env_data *)luaL_checkudata(L, 1, LUASQL_ENVIRONMENT_SQLITE);
-	luaL_argcheck(L, env != NULL, 1, LUASQL_PREFIX"environment expected");
-	if (env->closed) {
-		lua_pushboolean(L, 0);
-		return 1;
-	}
-
-	env->closed = 1;
-	lua_pushboolean(L, 1);
-	return 1;
+  env_data *env = (env_data *)luaL_checkudata(L, 1, LUASQL_ENVIRONMENT_SQLITE);
+  luaL_argcheck(L, env != NULL, 1, LUASQL_PREFIX"environment expected");
+  if (env->closed) {
+    lua_pushboolean(L, 0);
+    return 1;
+  }
+
+  env->closed = 1;
+  lua_pushboolean(L, 1);
+  return 1;
 }
 
 
@@ -531,32 +558,32 @@ static int env_close (lua_State *L)
 */
 static void create_metatables (lua_State *L)
 {
-    struct luaL_reg environment_methods[] = {
-        {"close", env_close},
-        {"connect", env_connect},
-		{NULL, NULL},
-	};
-    struct luaL_reg connection_methods[] = {
-        {"close", conn_close},
-        {"escape", conn_escape},
-        {"execute", conn_execute},
-        {"commit", conn_commit},
-        {"rollback", conn_rollback},
-        {"setautocommit", conn_setautocommit},
-	    {"getlastautoid", conn_getlastautoid},
-		{NULL, NULL},
-    };
-    struct luaL_reg cursor_methods[] = {
-        {"close", cur_close},
-        {"getcolnames", cur_getcolnames},
-        {"getcoltypes", cur_getcoltypes},
-        {"fetch", cur_fetch},
-		{NULL, NULL},
-    };
-	luasql_createmeta(L, LUASQL_ENVIRONMENT_SQLITE, environment_methods);
-	luasql_createmeta(L, LUASQL_CONNECTION_SQLITE, connection_methods);
-	luasql_createmeta(L, LUASQL_CURSOR_SQLITE, cursor_methods);
-	lua_pop (L, 3);
+  struct luaL_reg environment_methods[] = {
+    {"close", env_close},
+    {"connect", env_connect},
+    {NULL, NULL},
+  };
+  struct luaL_reg connection_methods[] = {
+    {"close", conn_close},
+    {"escape", conn_escape},
+    {"execute", conn_execute},
+    {"commit", conn_commit},
+    {"rollback", conn_rollback},
+    {"setautocommit", conn_setautocommit},
+    {"getlastautoid", conn_getlastautoid},
+    {NULL, NULL},
+  };
+  struct luaL_reg cursor_methods[] = {
+    {"close", cur_close},
+    {"getcolnames", cur_getcolnames},
+    {"getcoltypes", cur_getcoltypes},
+    {"fetch", cur_fetch},
+    {NULL, NULL},
+  };
+  luasql_createmeta(L, LUASQL_ENVIRONMENT_SQLITE, environment_methods);
+  luasql_createmeta(L, LUASQL_CONNECTION_SQLITE, connection_methods);
+  luasql_createmeta(L, LUASQL_CURSOR_SQLITE, cursor_methods);
+  lua_pop (L, 3);
 }
 
 /*
@@ -564,12 +591,12 @@ static void create_metatables (lua_State
 */
 static int create_environment (lua_State *L)
 {
-	env_data *env = (env_data *)lua_newuserdata(L, sizeof(env_data));
-	luasql_setmeta(L, LUASQL_ENVIRONMENT_SQLITE);
+  env_data *env = (env_data *)lua_newuserdata(L, sizeof(env_data));
+  luasql_setmeta(L, LUASQL_ENVIRONMENT_SQLITE);
 
-	/* fill in structure */
-	env->closed = 0;
-	return 1;
+  /* fill in structure */
+  env->closed = 0;
+  return 1;
 }
 
 
@@ -579,12 +606,12 @@ static int create_environment (lua_State
 */
 LUASQL_API int luaopen_luasql_sqlite3(lua_State *L)
 {
-	struct luaL_reg driver[] = {
-		{"sqlite3", create_environment},
-		{NULL, NULL},
-	};
-	create_metatables (L);
-	luaL_openlib (L, LUASQL_TABLENAME, driver, 0);
-	luasql_set_info (L);
-	return 1;
+  struct luaL_reg driver[] = {
+    {"sqlite3", create_environment},
+    {NULL, NULL},
+  };
+  create_metatables (L);
+  luaL_openlib (L, LUASQL_TABLENAME, driver, 0);
+  luasql_set_info (L);
+  return 1;
 }

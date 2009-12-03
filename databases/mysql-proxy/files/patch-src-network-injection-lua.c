--- src/network-injection-lua.c.orig	2009-06-30 22:47:39.000000000 +0600
+++ src/network-injection-lua.c	2009-11-17 09:39:32.000000000 +0500
@@ -33,17 +33,18 @@
 #define TIME_DIFF_US(t2, t1) \
 ((t2.tv_sec - t1.tv_sec) * 1000000.0 + (t2.tv_usec - t1.tv_usec))
 
+typedef enum {
+	PROXY_QUEUE_ADD_PREPEND,
+	PROXY_QUEUE_ADD_APPEND
+} proxy_queue_add_t;
 
 /**
- * proxy.queries:append(id, packet[, { options }])
+ * handle _append() and _prepend() 
  *
- *   id:      opaque numeric id (numeric)
- *   packet:  mysql packet to append (string)  FIXME: support table for multiple packets
- *   options: table of options (table)
- *     backend_ndx:  backend_ndx to send it to (numeric)
- *     resultset_is_needed: expose the result-set into lua (bool)
+ * _append() and _prepend() have the same behaviour, parameters, ... 
+ * just different in position
  */
-static int proxy_queue_append(lua_State *L) {
+static int proxy_queue_add(lua_State *L, proxy_queue_add_t type) {
 	GQueue *q = *(GQueue **)luaL_checkself(L);
 	int resp_type = luaL_checkinteger(L, 2);
 	size_t str_len;
@@ -68,7 +69,12 @@
 		} else if (lua_isboolean(L, -1)) {
 			inj->resultset_is_needed = lua_toboolean(L, -1);
 		} else {
-			luaL_argerror(L, 4, ":append(..., { resultset_is_needed = boolean } ), is %s");
+			switch (type) {
+			case PROXY_QUEUE_ADD_APPEND:
+				return luaL_argerror(L, 4, ":append(..., { resultset_is_needed = boolean } ), is %s");
+			case PROXY_QUEUE_ADD_PREPEND:
+				return luaL_argerror(L, 4, ":prepend(..., { resultset_is_needed = boolean } ), is %s");
+			}
 		}
 
 		lua_pop(L, 1);
@@ -78,25 +84,34 @@
 		luaL_typerror(L, 4, "table");
 		break;
 	}
-    
-	network_injection_queue_append(q, inj);
-    
-	return 0;
+
+	switch (type) {
+	case PROXY_QUEUE_ADD_APPEND:
+		network_injection_queue_append(q, inj);
+		return 0;
+	case PROXY_QUEUE_ADD_PREPEND:
+		network_injection_queue_prepend(q, inj);
+		return 0;
+	}
+
+	g_assert_not_reached();
+}
+
+/**
+ * proxy.queries:append(id, packet[, { options }])
+ *
+ *   id:      opaque numeric id (numeric)
+ *   packet:  mysql packet to append (string)  FIXME: support table for multiple packets
+ *   options: table of options (table)
+ *     backend_ndx:  backend_ndx to send it to (numeric)
+ *     resultset_is_needed: expose the result-set into lua (bool)
+ */
+static int proxy_queue_append(lua_State *L) {
+	return proxy_queue_add(L, PROXY_QUEUE_ADD_APPEND);
 }
 
 static int proxy_queue_prepend(lua_State *L) {
-	/* we expect 2 parameters */
-	GQueue *q = *(GQueue **)luaL_checkself(L);
-	int resp_type = luaL_checkinteger(L, 2);
-	size_t str_len;
-	const char *str = luaL_checklstring(L, 3, &str_len);
-    
-	GString *query = g_string_sized_new(str_len);
-	g_string_append_len(query, str, str_len);
-    
-	network_injection_queue_prepend(q, injection_new(resp_type, query));
-    
-	return 0;
+	return proxy_queue_add(L, PROXY_QUEUE_ADD_PREPEND);
 }
 
 static int proxy_queue_reset(lua_State *L) {

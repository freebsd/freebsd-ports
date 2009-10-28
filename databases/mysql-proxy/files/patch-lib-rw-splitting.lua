--- lib/rw-splitting.lua.orig	2009-06-30 22:47:39.000000000 +0600
+++ lib/rw-splitting.lua	2009-10-20 12:06:21.000000000 +0600
@@ -65,7 +65,7 @@
 
 	if is_debug then
 		print()
-		print("[connect_server] " .. proxy.connection.client.address)
+		print("[connect_server] " .. proxy.connection.client.src.name)
 	end
 
 	local rw_ndx = 0
@@ -143,7 +143,7 @@
 -- auth.packet is the packet
 function read_auth_result( auth )
 	if is_debug then
-		print("[read_auth_result] " .. proxy.connection.client.address)
+		print("[read_auth_result] " .. proxy.connection.client.src.name)
 	end
 	if auth.packet:byte() == proxy.MYSQLD_PACKET_OK then
 		-- auth was fine, disconnect from the server
@@ -175,7 +175,7 @@
 
 	-- looks like we have to forward this statement to a backend
 	if is_debug then
-		print("[read_query] " .. proxy.connection.client.address)
+		print("[read_query] " .. proxy.connection.client.src.name)
 		print("  current backend   = " .. proxy.connection.backend_ndx)
 		print("  client default db = " .. c.default_db)
 		print("  client username   = " .. c.username)
@@ -198,7 +198,7 @@
 		return proxy.PROXY_SEND_RESULT
 	end
 
-	proxy.queries:append(1, packet)
+	proxy.queries:append(1, packet, { resultset_is_needed = true })
 
 	-- read/write splitting 
 	--
@@ -278,14 +278,14 @@
 		print("    server default db: " .. s.default_db)
 		print("    client default db: " .. c.default_db)
 		print("    syncronizing")
-		proxy.queries:prepend(2, string.char(proxy.COM_INIT_DB) .. c.default_db)
+		proxy.queries:prepend(2, string.char(proxy.COM_INIT_DB) .. c.default_db, { resultset_is_needed = true })
 	end
 
 	-- send to master
 	if is_debug then
 		if proxy.connection.backend_ndx > 0 then
 			local b = proxy.global.backends[proxy.connection.backend_ndx]
-			print("  sending to backend : " .. b.address);
+			print("  sending to backend : " .. b.dst.name);
 			print("    is_slave         : " .. tostring(b.type == proxy.BACKEND_TYPE_RO));
 			print("    server default db: " .. s.default_db)
 			print("    server username  : " .. s.username)
@@ -319,7 +319,7 @@
 				proxy.response = {
 					type = proxy.MYSQLD_PACKET_ERR,
 					errmsg = "can't change DB ".. proxy.connection.client.default_db ..
-						" to on slave " .. proxy.global.backends[proxy.connection.backend_ndx].address
+						" to on slave " .. proxy.global.backends[proxy.connection.backend_ndx].dst.name
 				}
 
 				return proxy.PROXY_SEND_RESULT
@@ -352,7 +352,7 @@
 function disconnect_client()
 	local is_debug = proxy.global.config.rwsplit.is_debug
 	if is_debug then
-		print("[disconnect_client] " .. proxy.connection.client.address)
+		print("[disconnect_client] " .. proxy.connection.client.src.name)
 	end
 
 	-- make sure we are disconnection from the connection

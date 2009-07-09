--- lib/reporter.lua.orig	2009-05-05 16:54:45.000000000 +0600
+++ lib/reporter.lua	2009-05-05 16:56:21.000000000 +0600
@@ -0,0 +1,79 @@
+--[[
+
+   Copyright (C) 2009 MySQL AB, 2008 Sun Microsystems, Inc
+   
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; version 2 of the License.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+
+--]]
+
+-- reporter.lua
+
+--[[
+
+    See http://forge.mysql.com/tools/tool.php?id=78
+    (Thanks to Jan Kneschke)
+    See http://www.chriscalender.com/?p=41
+    (Thanks to Chris Calender)
+    See http://datacharmer.blogspot.com/2009/01/mysql-proxy-is-back.html
+    (Thanks Giuseppe Maxia)
+
+--]]
+
+proxy.global.query_counter = proxy.global.query_counter or 0
+
+function proxy.global.initialize_process_table()
+    if proxy.global.process == nil then
+        proxy.global.process = {}
+    end
+    if proxy.global.process[proxy.connection.server.thread_id] == nil then
+        proxy.global.process[proxy.connection.server.thread_id] = {}
+    end
+end
+
+function read_auth_result( auth )
+    local state = auth.packet:byte()
+    if state == proxy.MYSQLD_PACKET_OK then
+        proxy.global.initialize_process_table()
+        table.insert( proxy.global.process[proxy.connection.server.thread_id],
+            { ip = proxy.connection.client.src.name, ts = os.time() } )
+    end
+end
+
+function disconnect_client()
+    local connection_id = proxy.connection.server.thread_id
+    if connection_id then
+        -- client has disconnected, set this to nil
+        proxy.global.process[connection_id] = nil
+    end
+end
+
+
+---
+-- read_query() can return a resultset
+--
+-- You can use read_query() to return a result-set.
+--
+-- @param packet the mysql-packet sent by the client
+--
+-- @return
+--   * nothing to pass on the packet as is,
+--   * proxy.PROXY_SEND_QUERY to send the queries from the proxy.queries queue
+--   * proxy.PROXY_SEND_RESULT to send your own result-set
+--
+function read_query( packet )
+        -- a new query came in in this connection
+        -- using proxy.global.* to make it available to the admin plugin
+        proxy.global.query_counter = proxy.global.query_counter + 1
+
+end

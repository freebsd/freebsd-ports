--- lib/admin.lua.orig	2009-05-05 16:55:08.000000000 +0600
+++ lib/admin.lua	2009-05-05 16:56:11.000000000 +0600
@@ -0,0 +1,205 @@
+--[[ $%BEGINLICENSE%$
+ Copyright (C) 2009 MySQL AB, 2008 Sun Microsystems, Inc
+
+ This program is free software; you can redistribute it and/or modify
+ it under the terms of the GNU General Public License as published by
+ the Free Software Foundation; version 2 of the License.
+
+ This program is distributed in the hope that it will be useful,
+ but WITHOUT ANY WARRANTY; without even the implied warranty of
+ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ GNU General Public License for more details.
+
+ You should have received a copy of the GNU General Public License
+ along with this program; if not, write to the Free Software
+ Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+
+ $%ENDLICENSE%$ --]]
+
+-- admin-1.lua
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
+
+function set_error(errmsg) 
+    proxy.response = {
+        type = proxy.MYSQLD_PACKET_ERR,
+        errmsg = errmsg or "error"
+    }
+end
+
+function read_query(packet)
+    if packet:byte() ~= proxy.COM_QUERY then
+        set_error("[admin] we only handle text-based queries (COM_QUERY)")
+        return proxy.PROXY_SEND_RESULT
+    end
+
+    local query = packet:sub(2)
+    local rows = { }
+    local fields = { }
+
+    -- try to match the string up to the first non-alphanum
+    local f_s, f_e, command = string.find(packet, "^%s*(%w+)", 2)
+    local option
+
+    if f_e then
+            -- if that match, take the next sub-string as option
+            f_s, f_e, option = string.find(packet, "^%s+(%w+)", f_e + 1)
+    end
+
+    -- we got our commands, execute it
+    if command == "show" and option == "querycounter" then
+            ---
+            -- proxy.PROXY_SEND_RESULT requires
+            --
+            -- proxy.response.type to be either
+            -- * proxy.MYSQLD_PACKET_OK or
+            -- * proxy.MYSQLD_PACKET_ERR
+            --
+            -- for proxy.MYSQLD_PACKET_OK you need a resultset
+            -- * fields
+            -- * rows
+            --
+            -- for proxy.MYSQLD_PACKET_ERR
+            -- * errmsg
+            proxy.response.type = proxy.MYSQLD_PACKET_OK
+            proxy.response.resultset = {
+                    fields = {
+                            { type = proxy.MYSQL_TYPE_LONG, name = "query_counter", },
+                    },
+                    rows = {
+                            { proxy.global.query_counter }
+                    }
+            }
+
+            -- we have our result, send it back
+            return proxy.PROXY_SEND_RESULT
+    elseif command == "show" and option == "myerror" then
+            proxy.response.type = proxy.MYSQLD_PACKET_ERR
+            proxy.response.errmsg = "my first error"
+
+            return proxy.PROXY_SEND_RESULT
+            
+    elseif string.sub(packet, 2):lower() == 'select help' then
+            return show_process_help()
+    
+    elseif string.sub(packet, 2):lower() == 'show proxy processlist' then
+            return show_process_table()
+
+    elseif query == "SELECT * FROM backends" then
+        fields = { 
+            { name = "backend_ndx", 
+              type = proxy.MYSQL_TYPE_LONG },
+
+            { name = "address",
+              type = proxy.MYSQL_TYPE_STRING },
+            { name = "state",
+              type = proxy.MYSQL_TYPE_STRING },
+            { name = "type",
+              type = proxy.MYSQL_TYPE_STRING },
+        }
+
+        for i = 1, #proxy.global.backends do
+            local b = proxy.global.backends[i]
+
+            rows[#rows + 1] = {
+                i, b.dst.name, b.state, b.type 
+            }
+        end
+    else
+        set_error()
+        return proxy.PROXY_SEND_RESULT
+    end
+
+    proxy.response = {
+        type = proxy.MYSQLD_PACKET_OK,
+        resultset = {
+            fields = fields,
+            rows = rows
+        }
+    }
+    return proxy.PROXY_SEND_RESULT
+end
+
+
+function make_dataset (header, dataset)
+    proxy.response.type = proxy.MYSQLD_PACKET_OK
+
+    proxy.response.resultset = {
+        fields = {},
+        rows = {}
+    }
+    for i,v in pairs (header) do
+        table.insert(proxy.response.resultset.fields, {type = proxy.MYSQL_TYPE_STRING, name = v})
+    end
+    for i,v in pairs (dataset) do
+        table.insert(proxy.response.resultset.rows, v )
+    end
+    return proxy.PROXY_SEND_RESULT
+end
+
+function show_process_table()
+    local dataset = {}
+    local header = { 'Id', 'IP Address', 'Time' }
+    local rows = {}
+    for t_i, t_v in pairs (proxy.global.process) do
+        for s_i, s_v in pairs ( t_v ) do
+            table.insert(rows, { t_i, s_v.ip, os.date('%c',s_v.ts) })
+        end
+    end
+    return make_dataset(header,rows)
+end
+
+function show_process_help()
+    local dataset = {}
+    local header = { 'command',  'description' }
+    local rows = {
+        {'SELECT HELP',                 'This command.'},
+        {'SHOW PROXY PROCESSLIST',      'Show all connections and their true IP Address.'},
+    }
+    return make_dataset(header,rows)
+end
+
+function dump_process_table()
+    proxy.global.initialize_process_table()
+    print('current contents of process table')
+    for t_i, t_v in pairs (proxy.global.process) do
+        print ('session id: ', t_i)
+        for s_i, s_v in pairs ( t_v ) do
+            print ( '\t', s_i, s_v.ip, s_v.ts )
+        end
+    end
+    print ('---END PROCESS TABLE---')
+end
+
+
+
+
+--[[    Help
+
+we use a simple string-match to split commands are word-boundaries
+
+mysql> show querycounter
+
+is split into
+command = "show"
+option  = "querycounter"
+
+spaces are ignored, the case has to be as is.
+
+mysql> show myerror
+
+returns a error-packet
+
+--]]
+
+

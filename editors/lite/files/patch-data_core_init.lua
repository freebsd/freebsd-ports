--- data/core/init.lua.orig	2021-01-09 16:02:57 UTC
+++ data/core/init.lua
@@ -82,7 +82,7 @@ function core.init()
   CommandView = require "core.commandview"
   Doc = require "core.doc"
 
-  local project_dir = EXEDIR
+  local project_dir = HOMEDIR
   local files = {}
   for i = 2, #ARGS do
     local info = system.get_file_info(ARGS[i]) or {}
@@ -131,16 +131,16 @@ local function delete_temp_files()
 local temp_file_counter = 0
 
 local function delete_temp_files()
-  for _, filename in ipairs(system.list_dir(EXEDIR)) do
+  for _, filename in ipairs(system.list_dir("/tmp")) do
     if filename:find(temp_file_prefix, 1, true) == 1 then
-      os.remove(EXEDIR .. PATHSEP .. filename)
+      os.remove("/tmp" .. PATHSEP .. filename)
     end
   end
 end
 
 function core.temp_filename(ext)
   temp_file_counter = temp_file_counter + 1
-  return EXEDIR .. PATHSEP .. temp_file_prefix
+  return "/tmp" .. PATHSEP .. temp_file_prefix
       .. string.format("%06x", temp_file_counter) .. (ext or "")
 end
 
@@ -174,16 +174,18 @@ function core.load_plugins()
 
 function core.load_plugins()
   local no_errors = true
-  local files = system.list_dir(EXEDIR .. "/data/plugins")
-  for _, filename in ipairs(files) do
-    local modname = "plugins." .. filename:gsub(".lua$", "")
+  local files = system.list_dir(DATADIR .. "/plugins")
+  for _, filename in ipairs(files) do repeat
+    local luafile = filename:match("(.*)%.lua$")
+    if not luafile then break end
+    local modname = "plugins." .. luafile
     local ok = core.try(require, modname)
     if ok then
       core.log_quiet("Loaded plugin %q", modname)
     else
       no_errors = false
     end
-  end
+  until true end
   return no_errors
 end
 
@@ -464,7 +466,7 @@ function core.on_error(err)
 
 function core.on_error(err)
   -- write error to file
-  local fp = io.open(EXEDIR .. "/error.txt", "wb")
+  local fp = io.open(HOMEDIR .. "/lite-error.txt", "wb")
   fp:write("Error: " .. tostring(err) .. "\n")
   fp:write(debug.traceback(nil, 4))
   fp:close()

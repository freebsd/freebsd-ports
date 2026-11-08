--- lua/config/remote_clipboard.lua.orig	2026-09-29 13:53:52 UTC
+++ lua/config/remote_clipboard.lua
@@ -5,30 +5,25 @@ local M = {}
 -- text from the host when no readable clipboard exists, use terminal paste.
 local M = {}
 
-local function proc_lines(pid, file)
-  local ok, lines = pcall(vim.fn.readfile, "/proc/" .. pid .. "/" .. file)
-  return ok and lines or {}
+-- Use Neovim's portable process API instead of reading /proc, which is
+-- Linux-only (FreeBSD does not mount procfs by default).
+local function proc_info(pid)
+  local ok, info = pcall(vim.api.nvim_get_proc, pid)
+  return ok and info or nil
 end
 
-local function proc_ppid(pid)
-  for _, line in ipairs(proc_lines(pid, "status")) do
-    local ppid = line:match("^PPid:%s+(%d+)")
-    if ppid then
-      return tonumber(ppid)
-    end
-  end
-end
-
 local function ancestor_process_named(name)
   local pid = vim.fn.getpid()
 
   for _ = 1, 16 do
-    local ppid = proc_ppid(pid)
+    local info = proc_info(pid)
+    local ppid = info and info.ppid
     if not ppid or ppid <= 1 then
       return false
     end
 
-    local comm = proc_lines(ppid, "comm")[1] or ""
+    local parent = proc_info(ppid)
+    local comm = parent and parent.name or ""
     if comm:find(name, 1, true) then
       return true
     end

--- src/box/lua/load_cfg.lua.orig	2015-05-28 22:07:40 UTC
+++ src/box/lua/load_cfg.lua
@@ -54,7 +54,8 @@ local default_cfg = {
     custom_proc_title   = nil,
     pid_file            = nil,
     background          = false,
-    username            = nil ,
+    username            = nil,
+    groupname           = nil,
     coredump            = false,
 
     -- snapshot_daemon
@@ -101,6 +102,7 @@ local template_cfg = {
     pid_file            = 'string',
     background          = 'boolean',
     username            = 'string',
+    groupname           = 'string',
     coredump            = 'boolean',
     snapshot_period     = 'number',
     snapshot_count      = 'number',

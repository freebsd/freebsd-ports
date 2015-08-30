--- build/premake/wxwidgets.lua.orig	2015-08-29 07:09:15 UTC
+++ build/premake/wxwidgets.lua
@@ -246,7 +246,7 @@ function wx_config_Private(wxRoot, wxDeb
 
     -- use wx-config to figure out build parameters
     function wx_config_for_posix()
-        local configCmd = "wx-config" -- this is the wx-config command line
+        local configCmd = "%%WX_CONFIG%%" -- this is the wx-config command line
         if wxRoot ~= "" then configCmd = path.join(wxRoot, "wx-config") end
 
         local function checkYesNo(value, option)

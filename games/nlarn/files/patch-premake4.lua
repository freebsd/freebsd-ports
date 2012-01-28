--- premake4.lua.orig	2011-11-08 23:01:23.000000000 +0100
+++ premake4.lua	2011-11-08 23:01:44.000000000 +0100
@@ -75,12 +75,11 @@
       -- Add configuration for Lua
       -- Debian and Ubuntu have a specific naming convention for the lua
       -- package; fortunately it can be configured with pkg-config
-      if os.is("linux") and (get_linux_distribution() == "Debian"
-          or get_linux_distribution() == "Ubuntu")
+      if os.is("bsd")
       then
-        includedirs { get_dirs("include", "lua5.1") }
-        links { "lua5.1" }
-        libdirs { get_dirs("lib", "lua5.1") }
+        includedirs { get_dirs("include", "lua-5.1") }
+        links { "lua-5.1" }
+        libdirs { get_dirs("lib", "lua-5.1") }
       else
         includedirs { get_dirs("include", "lua") }
         links { "lua" }

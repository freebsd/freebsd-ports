--- 3rd/luamake/bee.lua/test/test.lua.orig	2025-12-02 15:38:21 UTC
+++ 3rd/luamake/bee.lua/test/test.lua
@@ -53,7 +53,7 @@ do
     if lt.options.touch then
         lt.options.touch = fs.absolute(lt.options.touch):string()
     end
-    local tmpdir = fs.temp_directory_path() / "test_bee"
+    local tmpdir = "%WRKDIR%" .. "/tmp/test_bee"
     fs.create_directories(tmpdir)
     fs.current_path(tmpdir)
 end

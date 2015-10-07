--- build/premake/wxformbuilder.lua.orig	2015-08-29 07:06:33 UTC
+++ build/premake/wxformbuilder.lua
@@ -101,7 +101,7 @@ end
         libdirs             {"../../output/lib/wxformbuilder"}
         targetdir           "../../output/bin"
         targetname          "wxformbuilder"
-        links               {"dl"}
+        links               {}
 
     configuration "windows"
         files               {"../../src/*.rc"}

--- 3rd/bee.lua/compile/common.lua.orig	2022-08-25 08:04:59 UTC
+++ 3rd/bee.lua/compile/common.lua
@@ -37,7 +37,7 @@ local function need(lst)
 end
 
 lm:source_set "source_bee" {
-    includes = ".",
+    includes = {"%%LOCALBASE%%/include", "."},
     sources = "bee/**/*.cpp",
     windows = {
         sources = need "win"
@@ -152,8 +152,9 @@ lm:lua_source "source_bee" {
         sources = {
             "!binding/lua_unicode.cpp",
         },
+        includes = "%%LOCALBASE%%/include",
         links = "inotify",
-        ldflags = "-pthread"
+        ldflags = {"-L%%LOCALBASE%%/lib", "-pthread"}
     },
 }
 
@@ -191,6 +192,6 @@ lm:source_set 'source_lua' {
         flags = "/wd4267"
     },
     gcc = {
-        flags = "-Wno-maybe-uninitialized",
+        flags = "-Wno-uninitialized",
     }
 }

--- Modules/FindLua50.cmake.orig	2008-08-01 18:34:50.000000000 +0300
+++ Modules/FindLua50.cmake	2009-01-22 09:26:29.000000000 +0200
@@ -28,7 +28,7 @@
 )
 
 FIND_LIBRARY(LUA_LIBRARY_lua 
-  NAMES lua50 lua5.0 lua5 lua
+  NAMES lua50 lua5.0 lua-5.0 lua5 lua
   HINTS
   $ENV{LUA_DIR}
   PATH_SUFFIXES lib64 lib

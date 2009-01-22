--- Modules/FindLua51.cmake.orig	2008-08-01 18:34:50.000000000 +0300
+++ Modules/FindLua51.cmake	2009-01-22 09:26:29.000000000 +0200
@@ -28,7 +28,7 @@
 )
 
 FIND_LIBRARY(LUA_LIBRARY 
-  NAMES lua51 lua5.1 lua
+  NAMES lua51 lua5.1 lua-5.1 lua
   HINTS
   $ENV{LUA_DIR}
   PATH_SUFFIXES lib64 lib

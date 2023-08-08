--- cmake/modules/FindLua51.cmake.orig	2016-05-02 18:30:40 UTC
+++ cmake/modules/FindLua51.cmake
@@ -33,7 +33,7 @@ FIND_PATH(LUA_INCLUDE_DIR lua.h
 )
 
 FIND_LIBRARY(LUA_LIBRARY 
-  NAMES lua51 lua5.1 lua
+  NAMES lua51 lua5.1 lua-5.1 lua
   PATHS
   $ENV{LUA_DIR}
   NO_DEFAULT_PATH
@@ -41,7 +41,7 @@ FIND_LIBRARY(LUA_LIBRARY 
 )
 
 FIND_LIBRARY(LUA_LIBRARY
-  NAMES lua51 lua5.1 lua
+  NAMES lua51 lua5.1 lua-5.1 lua
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks

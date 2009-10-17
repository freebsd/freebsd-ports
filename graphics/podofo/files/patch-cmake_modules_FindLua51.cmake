--- cmake/modules/FindLua51.cmake.orig	2009-10-17 13:51:12.000000000 +0400
+++ cmake/modules/FindLua51.cmake	2009-10-17 13:51:39.000000000 +0400
@@ -33,7 +33,7 @@
 )
 
 FIND_LIBRARY(LUA_LIBRARY 
-  NAMES lua51 lua5.1 lua
+  NAMES lua51 lua5.1 lua-5.1 lua
   PATHS
   $ENV{LUA_DIR}
   NO_DEFAULT_PATH
@@ -41,7 +41,7 @@
 )
 
 FIND_LIBRARY(LUA_LIBRARY
-  NAMES lua51 lua5.1 lua
+  NAMES lua51 lua5.1 lua-5.1 lua
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks

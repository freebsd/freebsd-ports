--- src/lua.cc.orig	2023-06-17 12:14:12 UTC
+++ src/lua.cc
@@ -24,9 +24,7 @@
 
 #define _XOPEN_SOURCE
 
-#include <lua.h>
-#include <lauxlib.h>
-#include <lualib.h>
+#include <lua.hpp>
 
 #include <stdio.h>
 #include <glib.h>

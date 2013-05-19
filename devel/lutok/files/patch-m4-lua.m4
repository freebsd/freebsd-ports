--- m4/lua.m4.old	2013-03-25 16:13:07.943129888 -0600
+++ m4/lua.m4	2013-03-25 16:13:20.186640871 -0600
@@ -37,6 +37,10 @@
     PKG_CHECK_MODULES([LUA], [lua5.1 >= 5.1], [lua_found=yes], [true])
 
     if test "${lua_found}" = no; then
+        PKG_CHECK_MODULES([LUA], [lua-5.1 >= 5.1], [lua_found=yes], [true])
+    fi
+
+   if test "${lua_found}" = no; then
         PKG_CHECK_MODULES([LUA], [lua >= 5.1], [lua_found=yes], [true])
     fi
 

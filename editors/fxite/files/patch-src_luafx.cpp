--- src/luafx.cpp.orig	2014-07-24 14:16:55.000000000 +0200
+++ src/luafx.cpp	2014-07-24 14:19:21.000000000 +0200
@@ -173,7 +173,7 @@
   switch (toupper(type[0])) {
     case 'I' : {
       if (!lua_isnil(L,3)) {
-        txt.format(sizeof(lua_Integer)>4?"%ld":"%d", luaL_checkinteger(L,3));
+        txt.format("%ld", luaL_checkinteger(L,3));
       }
       opt=INPUTDIALOG_INTEGER;
       break;

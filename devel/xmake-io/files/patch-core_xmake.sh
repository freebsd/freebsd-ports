--- core/xmake.sh.orig	2025-02-04 16:48:40 UTC
+++ core/xmake.sh
@@ -92,8 +92,8 @@ option_find_lua() {
     local cflags=""
     option "lua"
         # detect lua5.4 on debian
-        cflags=`pkg-config --cflags lua5.4 2>/dev/null`
-        ldflags=`pkg-config --libs lua5.4 2>/dev/null`
+        cflags=`pkg-config --cflags lua-5.4 2>/dev/null`
+        ldflags=`pkg-config --libs lua-5.4 2>/dev/null`
         # detect it on fedora
         if test_z "${cflags}"; then
             cflags=`pkg-config --cflags lua 2>/dev/null`

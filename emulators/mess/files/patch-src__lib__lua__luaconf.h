--- src/lib/lua/luaconf.h.orig
+++ src/lib/lua/luaconf.h
@@ -514,7 +514,7 @@
 #define LUA_NANTRICK
 
 /* pentium 64 bits? */
-#elif defined(__x86_64)                     /* }{ */
+#elif defined(__amd64__) || defined(__x86_64__) || defined(__x86_64) /* }{ */
 
 #define LUA_IEEE754TRICK
 #define LUA_IEEEENDIAN      0

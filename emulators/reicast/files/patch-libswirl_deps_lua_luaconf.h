--- libswirl/deps/lua/luaconf.h.orig	2020-10-18 11:22:48 UTC
+++ libswirl/deps/lua/luaconf.h
@@ -64,6 +64,11 @@
 #define LUA_USE_READLINE	/* needs some extra libraries */
 #endif
 
+#if defined(LUA_USE_FREEBSD)
+#define LUA_USE_POSIX
+#define LUA_USE_DLOPEN		/* FreeBSD does not need -ldl */
+#define LUA_USE_READLINE	/* needs an extra library: -lreadline */
+#endif
 
 #if defined(LUA_USE_MACOSX)
 #define LUA_USE_POSIX

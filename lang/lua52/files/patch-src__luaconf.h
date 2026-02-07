--- src/luaconf.h.old
+++ src/luaconf.h
@@ -519,10 +519,15 @@
 #define LUA_IEEE754TRICK
 #define LUA_IEEEENDIAN		0
 
-#elif defined(__POWERPC__) || defined(__ppc__)			/* }{ */
+#elif defined(__powerpc__)
 
 #define LUA_IEEE754TRICK
+
+#ifdef __LITTLE_ENDIAN__
+#define LUA_IEEEENDIAN		0
+#else
 #define LUA_IEEEENDIAN		1
+#endif
 
 #else								/* }{ */
 

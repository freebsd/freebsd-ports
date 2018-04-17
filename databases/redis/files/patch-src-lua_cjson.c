--- deps/lua/src/lua_cjson.c.orig	2016-12-04 20:49:41.925218000 -0500
+++ deps/lua/src/lua_cjson.c	2016-12-04 20:49:59.728885000 -0500
@@ -46,7 +46,9 @@
 #include "strbuf.h"
 #include "fpconv.h"
 
+#if defined(__sun)
 #include "../../../src/solarisfixes.h"
+#endif
 
 #ifndef CJSON_MODNAME
 #define CJSON_MODNAME   "cjson"

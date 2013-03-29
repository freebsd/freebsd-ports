--- src/mongo/scripting/engine_spidermonkey.h.orig	2013-03-15 19:59:55.000000000 +0100
+++ src/mongo/scripting/engine_spidermonkey.h	2013-03-22 17:54:19.000000000 +0100
@@ -29,7 +29,7 @@
 #define JS_PUBLIC_DATA(t)   t
 #endif
 
-#include <third_party/js-1.7/jsapi.h>
+#include <jsapi.h>
 
 // END inc hacking
 

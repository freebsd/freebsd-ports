--- proxies/graph_proxy.h.orig	2023-12-18 22:32:12 UTC
+++ proxies/graph_proxy.h
@@ -28,6 +28,7 @@
 #define GRAPH_PROXY_H__61D1ED56_E33B_4F50_B45B_F520979E8AA7__INCLUDED
 
 #include "common.h"
+#include <unistd.h>
 
 typedef struct graph_proxy_tag { int unused; } * graph_proxy_handle;
 

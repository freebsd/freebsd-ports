
$FreeBSD$

--- src/plugin_xmms/http.c.orig
+++ src/plugin_xmms/http.c
@@ -44,10 +44,6 @@
 #include "FLAC/format.h"
 #include "plugin.h"
 
-#ifndef HAVE_SOCKLEN_T
-typedef unsigned int socklen_t;
-#endif
-
 #define min(x,y) ((x)<(y)?(x):(y))
 #define min3(x,y,z) (min(x,y)<(z)?min(x,y):(z))
 #define min4(x,y,z,w) (min3(x,y,z)<(w)?min3(x,y,z):(w))

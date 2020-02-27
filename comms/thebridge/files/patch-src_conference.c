--- src/conference.c.orig	2012-12-09 19:21:01 UTC
+++ src/conference.c
@@ -784,7 +784,7 @@
 #include "ilink.h"
 #include "sf.h"
 #include "hostfile.h"
-#include "zlib.h"
+#include <zlib.h>
 #include "tbd.h"
 
 #if defined _WIN32GUI || defined _X11GUI

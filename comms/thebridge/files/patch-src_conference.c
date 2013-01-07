--- src/conference.c.orig	2013-01-03 21:44:25.000000000 -0500
+++ src/conference.c	2013-01-03 21:44:51.000000000 -0500
@@ -784,7 +784,7 @@
 #include "ilink.h"
 #include "sf.h"
 #include "hostfile.h"
-#include "zlib.h"
+#include <zlib.h>
 #include "tbd.h"
 
 #if defined _WIN32GUI || defined _X11GUI

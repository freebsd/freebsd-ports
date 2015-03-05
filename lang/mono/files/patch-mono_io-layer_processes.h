--- mono/io-layer/processes.h.orig	2014-12-03 06:25:48.000000000 -0500
+++ mono/io-layer/processes.h	2015-02-18 17:04:35.383320102 -0500
@@ -14,6 +14,7 @@
 #include <unistd.h>
 #endif
 #include <glib.h>
+#include <sys/types.h>
 
 #include <mono/io-layer/handles.h>
 #include <mono/io-layer/access.h>

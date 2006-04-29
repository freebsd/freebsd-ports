--- krita/core/tiles/kis_tilemanager.cc.orig	Sat Apr  8 04:58:21 2006
+++ krita/core/tiles/kis_tilemanager.cc	Sat Apr  8 04:58:41 2006
@@ -18,8 +18,8 @@
 
 #include <kdebug.h>
 
-#include <sys/mman.h>
 #include <sys/types.h>
+#include <sys/mman.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <string.h>

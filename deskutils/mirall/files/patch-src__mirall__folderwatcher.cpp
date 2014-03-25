--- ./src/mirall/folderwatcher.cpp.orig	2014-03-10 12:22:06.000000000 +0100
+++ ./src/mirall/folderwatcher.cpp	2014-03-24 14:18:20.000000000 +0100
@@ -29,7 +29,7 @@
 #include "mirall/folderwatcher_win.h"
 #elif defined(Q_OS_MAC)
 #include "mirall/folderwatcher_mac.h"
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include "mirall/folderwatcher_linux.h"
 #endif
 

commit 8ec88f9e65842f94415297f2e9aa6b1e124b7b13
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    Avoid Linuxisms
    
    1. sighandler_t is a GNU extension - use FreeBSD extension sig_t
       instead, where applicable
    2. include sys/stat.h for S_IRXWU - on Linux it's implicit (via file.h,
       I think), but not everywhere

diff --git src/qmaptool/setup/CAppSetupLinux.cpp src/qmaptool/setup/CAppSetupLinux.cpp
index 10d2030a8..5d1edc506 100644
--- src/qmaptool/setup/CAppSetupLinux.cpp
+++ src/qmaptool/setup/CAppSetupLinux.cpp
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include <QMessageBox>
 #include <QWindow>
@@ -33,6 +34,10 @@
 #include "setup/CAppSetupLinux.h"
 #include "version.h"
 
+#if defined(Q_OS_FREEBSD)
+typedef sig_t sighandler_t;
+#endif
+
 void CAppSetupLinux::initQMapTool() {
   // setup gdal
   prepareGdal("", "", "");

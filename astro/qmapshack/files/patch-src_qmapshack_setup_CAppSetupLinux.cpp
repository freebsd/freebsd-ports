commit bf430000d89b6eb1c56c33b1f77725e0c5cf15af
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    Avoid Linuxisms
    
    1. sighandler_t is a GNU extension - use FreeBSD extension sig_t
       instead, where applicable
    2. include sys/stat.h for S_IRXWU - on Linux it's implicit (via file.h,
       I think), but not everywhere

diff --git src/qmapshack/setup/CAppSetupLinux.cpp src/qmapshack/setup/CAppSetupLinux.cpp
index 513217030..a3975ca2f 100644
--- src/qmapshack/setup/CAppSetupLinux.cpp
+++ src/qmapshack/setup/CAppSetupLinux.cpp
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
 void CAppSetupLinux::initQMapShack() {
   // setup gdal
   prepareGdal("", "", "");

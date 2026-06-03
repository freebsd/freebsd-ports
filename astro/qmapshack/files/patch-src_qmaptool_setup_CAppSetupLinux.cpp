commit f9ad12bb5d1ccb40c048732400d07cb56521840b
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    Avoid Linuxisms
    
    1. sighandler_t is a GNU extension - use FreeBSD extension sig_t
       instead, where applicable
    2. include sys/stat.h for S_IRXWU - on Linux it's implicit (via file.h,
       I think), but not everywhere

diff --git src/qmaptool/setup/CAppSetupLinux.cpp src/qmaptool/setup/CAppSetupLinux.cpp
index d3e353fa..ca36a2f3 100644
--- src/qmaptool/setup/CAppSetupLinux.cpp
+++ src/qmaptool/setup/CAppSetupLinux.cpp
@@ -30,10 +30,15 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include "config.h"
 #include "version.h"
 
+#if defined(Q_OS_FREEBSD)
+typedef sig_t sighandler_t;
+#endif
+
 void CAppSetupLinux::initQMapTool() {
   // setup gdal
   prepareGdal("", "", "");

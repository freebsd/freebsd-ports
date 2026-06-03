commit b14348175018950fedb676b1e56e433d813af9bb
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    Avoid Linuxisms
    
    1. sighandler_t is a GNU extension - use FreeBSD extension sig_t
       instead, where applicable
    2. include sys/stat.h for S_IRXWU - on Linux it's implicit (via file.h,
       I think), but not everywhere

diff --git src/qmapshack/setup/CAppSetupLinux.cpp src/qmapshack/setup/CAppSetupLinux.cpp
index 4c468417..4053532f 100644
--- src/qmapshack/setup/CAppSetupLinux.cpp
+++ src/qmapshack/setup/CAppSetupLinux.cpp
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
 void CAppSetupLinux::initQMapShack() {
   // setup gdal
   prepareGdal("", "", "");

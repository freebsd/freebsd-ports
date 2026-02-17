commit a23da70dfce1212ef8399cca261a095bb472ea61
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    sighandler_t is a GNU extension
    
    use the correspondig FreeBSD extension sig_t

diff --git src/qmaptool/setup/CAppSetupLinux.cpp src/qmaptool/setup/CAppSetupLinux.cpp
index 19ebccfa..74563081 100644
--- src/qmaptool/setup/CAppSetupLinux.cpp
+++ src/qmaptool/setup/CAppSetupLinux.cpp
@@ -29,6 +29,10 @@
 #include "config.h"
 #include "version.h"
 
+#if defined(Q_OS_FREEBSD)
+typedef sig_t sighandler_t;
+#endif
+
 void CAppSetupLinux::initQMapTool() {
   // setup gdal
   prepareGdal("", "", "");

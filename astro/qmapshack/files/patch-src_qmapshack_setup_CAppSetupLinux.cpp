commit d1fe132b222794ca1587785a62e3d4e2485918ca
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    sighandler_t is a GNU extension
    
    use the corresponding FreeBSD extension sig_t

diff --git src/qmapshack/setup/CAppSetupLinux.cpp src/qmapshack/setup/CAppSetupLinux.cpp
index 028a55f5..cd856e36 100644
--- src/qmapshack/setup/CAppSetupLinux.cpp
+++ src/qmapshack/setup/CAppSetupLinux.cpp
@@ -29,6 +29,10 @@
 #include "config.h"
 #include "version.h"
 
+#if defined(Q_OS_FREEBSD)
+typedef sig_t sighandler_t;
+#endif
+
 void CAppSetupLinux::initQMapShack() {
   // setup gdal
   prepareGdal("", "", "");

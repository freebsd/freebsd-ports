--- src/gis/CGisListWks.cpp.orig	2016-06-04 19:56:53 UTC
+++ src/gis/CGisListWks.cpp
@@ -18,7 +18,7 @@
 
 #include "CMainWindow.h"
 #include "canvas/CCanvas.h"
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include "device/CDeviceWatcherLinux.h"
 #endif
 #ifdef Q_OS_WIN
@@ -196,7 +196,7 @@ CGisListWks::CGisListWks(QWidget *parent
         QTimer::singleShot(saveEvery * 60000, this, SLOT(slotSaveWorkspace()));
     }
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     deviceWatcher = new CDeviceWatcherLinux(this);
     connect(deviceWatcher, &CDeviceWatcherLinux::sigChanged, this, &CGisListWks::sigChanged);
 #endif

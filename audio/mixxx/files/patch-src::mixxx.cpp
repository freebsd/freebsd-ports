--- src/mixxx.cpp.orig	Fri Jun 25 20:52:15 2004
+++ src/mixxx.cpp	Fri Jun 25 21:17:32 2004
@@ -29,6 +29,7 @@
 #include <qlabel.h>
 #include <qdir.h>
 #include <qptrlist.h>
+#include <qtimer.h>
 
 #include "wknob.h"
 #include "wslider.h"
@@ -85,6 +86,11 @@
 
 #include "playerproxy.h"
 
+void MixxxApp::Timeout()
+{
+  // nop
+}
+
 MixxxApp::MixxxApp(QApplication *a, QStringList files)
 {
     app = a;
@@ -113,7 +119,7 @@
     // On Windows and Mac it is always (and only) app dir.
     //
     QString qConfigPath;
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     // On Linux, check if the path is stored in the configuration database.
     if (config->getValueString(ConfigKey("[Config]","Path")).length()>0 && QDir(config->getValueString(ConfigKey("[Config]","Path"))).exists())
         qConfigPath = config->getValueString(ConfigKey("[Config]","Path"));
@@ -381,7 +387,12 @@
 #ifndef __WIN__
 	new MixxxSocketServer(m_pTrack);
 #endif
-    
+
+    // Keep the sound alive
+    QTimer *timer = new QTimer(this);
+    connect(timer, SIGNAL(timeout()), SLOT(Timeout()));
+    timer->start(100);
+
     // Call inits to invoke all other construction parts
     initActions();
     initMenuBar();

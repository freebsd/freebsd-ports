src/mainimpl.cpp:82:19: error: cannot initialize a parameter of type 'QStatusBar *' with an rvalue of type 'bool'
    setStatusBar( false );
                  ^~~~~

--- src/mainimpl.cpp.orig	2018-07-28 10:47:16 UTC
+++ src/mainimpl.cpp
@@ -79,7 +79,7 @@ MainImpl::MainImpl(QWidget * parent)
         : QMainWindow(parent)
 {
     setupUi(this);
-    setStatusBar( false );
+    setStatusBar( NULL );
     m_saveBeforeBuild = true;
     m_restoreOnStart = true;
     m_projectManager = 0;

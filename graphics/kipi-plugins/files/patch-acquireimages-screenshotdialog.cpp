--- ./acquireimages/screenshotdialog.cpp.orig	Sat Sep  4 11:33:39 2004
+++ ./acquireimages/screenshotdialog.cpp	Sat Sep  4 11:33:48 2004
@@ -116,7 +116,7 @@
     m_delay->setValue(m_config->readNumEntry("Delay", 1));
 
     delete m_config;
-};
+}
 
 
 //////////////////////////////////// DESTRUCTOR /////////////////////////////////////////////

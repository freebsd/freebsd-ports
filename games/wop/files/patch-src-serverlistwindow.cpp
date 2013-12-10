--- src/serverlistwindow.cpp.orig	2005-07-17 21:27:31.000000000 +0400
+++ src/serverlistwindow.cpp	2013-05-30 22:08:15.521112163 +0400
@@ -94,7 +94,6 @@
 }
 
 ServerListWindow::~ServerListWindow() {
-	delete m_header;
 }
 
 void ServerListWindow::clearEntries() {

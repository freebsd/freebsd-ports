--- src/serverlistwindow.cpp.orig	2005-07-17 17:27:31 UTC
+++ src/serverlistwindow.cpp
@@ -94,7 +94,6 @@ ServerListWindow::ServerListWindow( Uint
 }
 
 ServerListWindow::~ServerListWindow() {
-	delete m_header;
 }
 
 void ServerListWindow::clearEntries() {

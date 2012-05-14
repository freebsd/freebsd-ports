--- src/mainframe.cpp.orig	2012-01-26 22:31:52.000000000 +0800
+++ src/mainframe.cpp	2012-05-01 11:03:06.000000000 +0800
@@ -171,7 +171,9 @@
 	m_FavoritesMenu = NULL;
 	m_IsFlashing = false;
 	m_Mode = NORMAL_MODE;
+#ifdef USE_DOCKLET
 	m_TrayIcon = NULL;
+#endif
 
 	if (desktop != NULL && strcmp("Unity", desktop) == 0) {
 		m_Unity = true;

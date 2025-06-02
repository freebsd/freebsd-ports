--- src/gui/MainWindow.cpp.orig	2023-06-17 16:07:46 UTC
+++ src/gui/MainWindow.cpp
@@ -33,7 +33,6 @@
 #include <QMenuBar>
 #include <QMessageBox>
 #include <QShortcut>
-#include <QLibrary>
 #include <QSplitter>
 #include <QUrl>
 #include <QWhatsThis>
@@ -65,23 +64,6 @@
 
 #include "lmmsversion.h"
 
-#if !defined(LMMS_BUILD_WIN32) && !defined(LMMS_BUILD_APPLE) && !defined(LMMS_BUILD_HAIKU) && QT_VERSION >= 0x050000
-//Work around an issue on KDE5 as per https://bugs.kde.org/show_bug.cgi?id=337491#c21
-void disableAutoKeyAccelerators(QWidget* mainWindow)
-{
-	using DisablerFunc = void(*)(QWidget*);
-	QLibrary kf5WidgetsAddon("KF5WidgetsAddons", 5);
-	DisablerFunc setNoAccelerators = 
-			reinterpret_cast<DisablerFunc>(kf5WidgetsAddon.resolve("_ZN19KAcceleratorManager10setNoAccelEP7QWidget"));
-	if(setNoAccelerators)
-	{
-		setNoAccelerators(mainWindow);
-	}
-	kf5WidgetsAddon.unload();
-}
-#endif
-
-
 MainWindow::MainWindow() :
 	m_workspace( NULL ),
 	m_templatesMenu( NULL ),
@@ -92,9 +74,6 @@
 	m_metronomeToggle( 0 ),
 	m_session( Normal )
 {
-#if !defined(LMMS_BUILD_WIN32) && !defined(LMMS_BUILD_APPLE) && !defined(LMMS_BUILD_HAIKU) && QT_VERSION >= 0x050000
-	disableAutoKeyAccelerators(this);
-#endif
 	setAttribute( Qt::WA_DeleteOnClose );
 
 	QWidget * main_widget = new QWidget( this );

--- qelectrotech.pro.orig	2013-10-20 15:35:18.572968653 +0000
+++ qelectrotech.pro	2013-10-20 15:36:46.700968030 +0000
@@ -19,7 +19,7 @@
 	QET_DESKTOP_PATH           = 'share/applications/'
 	QET_ICONS_PATH             = 'share/icons/hicolor/'
 	QET_MAN_PATH               = 'man/'
-	QET_APPDATA_PATH           = 'share/appdata'
+#	QET_APPDATA_PATH           = 'share/appdata'
 }
 win32 {
 	# Chemins Windows
@@ -123,8 +123,8 @@
 desktop.path       = $$join(INSTALL_PREFIX,,,$${QET_DESKTOP_PATH})
 desktop.files      = misc/qelectrotech.desktop
 
-appdata.path       = $$join(INSTALL_PREFIX,,,$${QET_APPDATA_PATH})
-appdata.files      = misc/qelectrotech.appdata.xml
+#appdata.path       = $$join(INSTALL_PREFIX,,,$${QET_APPDATA_PATH})
+#appdata.files      = misc/qelectrotech.appdata.xml
 
 icons.path         = $$join(INSTALL_PREFIX,,,$${QET_ICONS_PATH})
 icons.files        = ico/oxygen-icons/16x16   \
@@ -166,7 +166,7 @@
 
 # Compilers-specific options
 unix {
-	QMAKE_COPY_DIR = 'cp -f -r --preserve=timestamps'
+	QMAKE_COPY_DIR = 'cp -frp'
 	*-g++* {
 		system(g++ -v --help 2>&1 | grep -q fipa-sra) {
 			QMAKE_CXXFLAGS += -fno-ipa-sra

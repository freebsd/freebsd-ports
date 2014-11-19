--- BASIC256.pro.orig	2014-11-05 17:03:39 UTC
+++ BASIC256.pro
@@ -13,13 +13,6 @@ CONFIG						+=	 qt debug_and_release
 OBJECTS_DIR					=	tmp/obj
 MOC_DIR						=	tmp/moc
 
-QT						+=	webkit
-QT						+=	gui
-QT						+=	sql
-QT						+=	widgets
-QT						+=	printsupport
-QT						+=	serialport
-
 RESOURCES					+=	resources/resource.qrc
 RC_FILE						=	resources/basic256.rc
 TRANSLATIONS				=	Translations/basic256_en.ts \
@@ -86,7 +79,7 @@ unix:!macx {
 
 	## TTS Option 2 - use the espeak library
 	DEFINES					+=	ESPEAK
-	INCLUDEPATH				+=	/usr/include/espeak
+	INCLUDEPATH				+=	$$LOCALBASE/include/espeak
 	LIBS					+=	-lespeak
 
 	LIBS					+=	-lm
@@ -101,8 +94,10 @@ unix:!macx {
 
 	# Sound - QT Mobility Multimedia AudioOut
 	DEFINES					+=	SOUND_QMOBILITY
-	QT						+=	multimedia
-	INCLUDEPATH				+=	QtMultimediaKit
+	INCLUDEPATH                             +=      $$LOCALBASE/include/qt5/QtMultimedia
+	INCLUDEPATH                             +=      $$LOCALBASE/include/qt5/QtSerialPort
+ 	INCLUDEPATH				+=	QtMobility
+	LIBS                                    +=      -L$$LOCALBASE/lib -lQt5Gui -lQt5Core -lQt5Widgets -lQt5Sql -lQt5Multimedia -lQt5PrintSupport -lQt5SerialPort
 	INCLUDEPATH				+=	QtMobility
 
 
@@ -110,19 +105,19 @@ unix:!macx {
 	# rules for make install
 	########
 	exampleFiles.files		=	./Examples
-	exampleFiles.path		=	/usr/share/basic256
+	exampleFiles.path		=	$$PREFIX/share/basic256
 	INSTALLS				+=	exampleFiles
 
 	helpHTMLFiles.files		=	./wikihelp/help
-	helpHTMLFiles.path		=	/usr/share/basic256
+	helpHTMLFiles.path		=	$$PREFIX/share/basic256
 	INSTALLS				+=	helpHTMLFiles
 
 	transFiles.files		=	./Translations/*.qm
-	transFiles.path			=	/usr/share/basic256
+	transFiles.path			=	$$PREFIX/share/basic256
 	INSTALLS				+=	transFiles
 
 	# main program executable
-	target.path				=	/usr/bin
+	target.path				=	$$PREFIX/bin
 	INSTALLS				+=	target
 
 }

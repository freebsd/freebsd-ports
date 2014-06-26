--- BASIC256.pro.orig	2014-06-20 21:01:15.000000000 +0200
+++ BASIC256.pro	2014-06-20 21:03:24.000000000 +0200
@@ -1,8 +1,4 @@
 
-lessThan(QT_MAJOR_VERSION, 5) {
-  message( FATAL_ERROR "BASIC-256 requires QT 5 or better." )
-}
-
 
 TEMPLATE					=	app
 TARGET						=	basic256
@@ -13,11 +9,6 @@
 OBJECTS_DIR					=	tmp/obj
 MOC_DIR						=	tmp/moc
 
-QT						+=	webkit
-QT						+=	gui
-QT						+=	sql
-QT						+=	widgets
-QT						+=	printsupport
 
 RESOURCES					+=	resources/resource.qrc
 RC_FILE						=	resources/basic256.rc
@@ -84,7 +75,7 @@
 
 	## TTS Option 2 - use the espeak library
 	DEFINES					+=	ESPEAK
-	INCLUDEPATH				+=	/usr/include/espeak
+	INCLUDEPATH				+=	$$LOCALBASE/include/espeak
 	LIBS					+=	-lespeak
 
 	LIBS					+=	-lm
@@ -99,28 +90,28 @@
 
 	# Sound - QT Mobility Multimedia AudioOut
 	DEFINES					+=	SOUND_QMOBILITY
-	QT						+=	multimedia
-	INCLUDEPATH				+=	QtMultimediaKit
+	INCLUDEPATH				+=	$$LOCALBASE/include/qt5/QtMultimedia
 	INCLUDEPATH				+=	QtMobility
+	LIBS					+=	-L$$LOCALBASE/lib -lQt5Gui -lQt5Core -lQt5Widgets -lQt5Sql -lQt5Multimedia -lQt5PrintSupport
 
 
 	########
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

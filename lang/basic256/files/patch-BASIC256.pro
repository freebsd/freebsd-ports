--- BASIC256.pro.orig	2020-05-07 12:32:08 UTC
+++ BASIC256.pro
@@ -15,13 +15,6 @@ CONFIG							+=	 console
 OBJECTS_DIR						=	tmp/obj
 MOC_DIR							=	tmp/moc
 
-#QT								+=	webkitwidgets
-#QT								+=	webkit
-QT								+=	gui
-QT								+=	sql
-QT								+=	widgets
-QT								+=	printsupport
-QT								+=	serialport
 
 RESOURCES						+=	resources/resource.qrc
 TRANSLATIONS					=	Translations/basic256_en.ts \
@@ -90,15 +83,21 @@ unix:!macx {
 
 	## TTS Option 2 - use the espeak library
 	DEFINES						+=	ESPEAK
-	INCLUDEPATH					+=	/usr/include/espeak
+	INCLUDEPATH					+=	$$LOCALBASE/include/espeak
 	LIBS						+=	-lespeak
 	LIBS						+=	-lm
 
 	########
 	# Sound class - How Sound statement works
 	########
-	QT							+=	multimedia
-	INCLUDEPATH					+=	QtMultimediaKit
+	INCLUDEPATH                             +=      $$LOCALBASE/include/qt5/QtMultimedia
+	INCLUDEPATH                             +=	$$LOCALBASE/include/qt5/QtNetwork
+	INCLUDEPATH                             +=	$$LOCALBASE/include/qt5/QtPrintSupport
+	INCLUDEPATH                             +=      $$LOCALBASE/include/qt5/QtSerialPort
+	INCLUDEPATH                             +=	$$LOCALBASE/include/qt5/QtSql
+	INCLUDEPATH                             +=	$$LOCALBASE/include/qt5/QtWidgets
+	INCLUDEPATH				+=	QtMobility
+	LIBS                                    +=      -L$$LOCALBASE/lib -L$$LOCALBASE/lib/qt5 -lQt5Gui -lQt5Core -lQt5Widgets -lQt5Sql -lQt5Multimedia -lQt5PrintSupport -lQt5SerialPort
 	INCLUDEPATH					+=	QtMobility
 
 
@@ -106,19 +105,19 @@ unix:!macx {
 	# rules for make install
 	########
 	exampleFiles.files			=	./Examples
-	exampleFiles.path			=	/usr/share/basic256
+	exampleFiles.path			=	$$PREFIX/share/basic256
 	INSTALLS					+=	exampleFiles
 
 	helpHTMLFiles.files			=	./wikihelp/help
-	helpHTMLFiles.path			=	/usr/share/basic256
+	helpHTMLFiles.path			=	$$PREFIX/share/basic256
 	INSTALLS					+=	helpHTMLFiles
 
 	transFiles.files			=	./Translations/*.qm
-	transFiles.path				=	/usr/share/basic256
+	transFiles.path				=	$$PREFIX/share/basic256
 	INSTALLS					+=	transFiles
 
 	# main program executable
-	target.path					=	/usr/bin
+	target.path					=	$$PREFIX/bin
 	INSTALLS					+=	target
 
 }

--- BASIC256.pro.orig	2013-11-13 18:26:47.000000000 +0100
+++ BASIC256.pro	2013-11-13 18:36:29.000000000 +0100
@@ -82,7 +82,7 @@
 
 	## TTS Option 2 - use the espeak library
 	DEFINES					+=	ESPEAK
-	INCLUDEPATH				+=	/usr/include/espeak
+	INCLUDEPATH				+=	%%LOCALBASE%%/include/espeak
 	LIBS					+=	-lespeak
 
 	LIBS					+=	-lm
@@ -113,19 +113,19 @@
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
-	target.path				=	/usr/local/bin
+	target.path				=	$$PREFIX/bin
 	INSTALLS				+=	target
 
 }

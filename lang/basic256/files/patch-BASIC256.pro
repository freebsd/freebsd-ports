--- BASIC256.pro.orig	2013-02-11 23:43:57.000000000 +0100
+++ BASIC256.pro	2013-02-11 23:47:27.000000000 +0100
@@ -101,19 +101,19 @@
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

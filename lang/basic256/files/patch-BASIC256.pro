--- BASIC256.pro.orig	2011-08-26 19:37:38.000000000 +0200
+++ BASIC256.pro	2011-09-03 13:07:27.000000000 +0200
@@ -62,72 +62,72 @@
 	## rules for make install
 	examplesDiceFiles.files = ./Examples/dice/*.kbs \
 				./Examples/dice/*.wav
-	examplesDiceFiles.path = /usr/share/basic256/Examples/dice
+	examplesDiceFiles.path = $$PREFIX/share/basic256/Examples/dice
 	INSTALLS += examplesDiceFiles
 	examplesImgloadFiles.files = ./Examples/imgload/*.kbs \
 				./Examples/imgload/*.png \
 				./Examples/imgload/*.bmp
-	examplesImgloadFiles.path = /usr/share/basic256/Examples/imgload
+	examplesImgloadFiles.path = $$PREFIX/share/basic256/Examples/imgload
 	INSTALLS += examplesImgloadFiles
 	examplesNetworkingFiles.files = ./Examples/networking/*.kbs
-	examplesNetworkingFiles.path = /usr/share/basic256/Examples/networking
+	examplesNetworkingFiles.path = $$PREFIX/share/basic256/Examples/networking
 	INSTALLS += examplesNetworkingFiles
 	examplesSpritesFiles.files = ./Examples/sprites/*.kbs \
 				./Examples/sprites/*.wav \
 				./Examples/sprites/*.png \
 				./Examples/sprites/*.bmp
-	examplesSpritesFiles.path = /usr/share/basic256/Examples/sprites
+	examplesSpritesFiles.path = $$PREFIX/share/basic256/Examples/sprites
 	INSTALLS += examplesSpritesFiles
 	examplesTestingFiles.files = ./Examples/testing/*.kbs
-	examplesTestingFiles.path = /usr/share/basic256/Examples/testing
+	examplesTestingFiles.path = $$PREFIX/share/basic256/Examples/testing
 	INSTALLS += examplesTestingFiles
 	examplesFiles.files = ./Examples/*.kbs
-	examplesFiles.path = /usr/share/basic256/Examples
+	examplesFiles.path = $$PREFIX/share/basic256/Examples
 	INSTALLS += examplesFiles
 	transFiles.files = ./Translations/*.qm
-	transFiles.path = /usr/share/basic256
+	transFiles.path = $$PREFIX/share/basic256
 	INSTALLS += transFiles
 	# EN - english help files
 	helpENFiles.files = ../doc/help/en/*.html \
 		./help/en/*.css \
 		./help/en/*.png \
 		./help/en/*.jpg
-	helpENFiles.path = /usr/share/basic256/help/en
+	helpENFiles.path = $$PREFIX/share/basic256/help/en
 	INSTALLS += helpENFiles
 	# DE - german help files
 	helpDEFiles.files = ../doc/help/de/*.html \
 		./help/de/*.css \
 		./help/de/*.png \
 		./help/de/*.jpg
-	helpDEFiles.path = /usr/share/basic256/help/de
+	helpDEFiles.path = $$PREFIX/share/basic256/help/de
 	INSTALLS += helpDEFiles
 	# ES - spanish help files
 	helpESFiles.files = ../doc/help/es/*.html \
 		./help/es/*.css \
 		./help/es/*.png \
 		./help/es/*.jpg
-	helpESFiles.path = /usr/share/basic256/help/es
+	helpESFiles.path = $$PREFIX/share/basic256/help/es
 	INSTALLS += helpESFiles
 	# FR - french help files
 	helpFRFiles.files = ../doc/help/fr/*.html \
 		./help/fr/*.css \
 		./help/fr/*.png \
 		./help/fr/*.jpg
-	helpFRFiles.path = /usr/share/basic256/help/fr
+	helpFRFiles.path = $$PREFIX/share/basic256/help/fr
 	INSTALLS += helpFRFiles
 	# RU - russian help files
 	helpRUFiles.files = ../doc/help/ru/*.html \
 		./help/ru/*.css \
 		./help/ru/*.png \
 		./help/ru/*.jpg
-	helpRUFiles.path = /usr/share/basic256/help/ru
+	helpRUFiles.path = $$PREFIX/share/basic256/help/ru
 	INSTALLS += helpRUFiles
 	# all language translation files
 	transFiles.files = ./Translations/*.qm
-	transFiles.path = /usr/share/basic256
+	transFiles.path = $$PREFIX/share/basic256
 	INSTALLS += transFiles
 	# main program executable
-	target.path = /usr/local/bin
+	target.path = $$PREFIX/bin
 	INSTALLS += target
 
 }

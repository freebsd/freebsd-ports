--- BASIC256.pro.orig	2013-01-07 19:49:52.000000000 +0100
+++ BASIC256.pro	2013-01-07 19:59:34.000000000 +0100
@@ -84,33 +84,33 @@
 	#DEFINES 		+= SOUND_DSP
 
         # Sound - Option 1 - SDL Mixer
-	#DEFINES 		+= SOUND_SDL
-	#LIBS			+= -lSDL
-	#LIBS			+= -lSDL_mixer
+	DEFINES 		+= SOUND_SDL
+	LIBS			+= -lSDL
+	LIBS			+= -lSDL_mixer
 
 	# Sound - Option 2 - QT Mobility Multimedia AudioOut
-	DEFINES 		+= SOUND_QMOBILITY
-	QT			+= mobility
-	CONFIG			+= mobility
-	MOBILITY		+= multimedia
+	#DEFINES 		+= SOUND_QMOBILITY
+	#QT			+= mobility
+	#CONFIG			+= mobility
+	#MOBILITY		+= multimedia
 
         ########
 	# rules for make install
         ########
 	exampleFiles.files = ./Examples
-	exampleFiles.path = /usr/share/basic256
+	exampleFiles.path = $$PREFIX/share/basic256
 	INSTALLS += exampleFiles
 
 	helpHTMLFiles.files = ./wikihelp/help
-	helpHTMLFiles.path = /usr/share/basic256
+	helpHTMLFiles.path = $$PREFIX/share/basic256
 	INSTALLS += helpHTMLFiles
 
 	transFiles.files = ./Translations/*.qm
-	transFiles.path = /usr/share/basic256
+	transFiles.path = $$PREFIX/share/basic256
 	INSTALLS += transFiles
 
 	# main program executable
-	target.path = /usr/local/bin
+	target.path = $$PREFIX/bin
 	INSTALLS += target
 
 }

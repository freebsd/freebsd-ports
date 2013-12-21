--- application/application.pro.orig	2011-01-22 03:25:20.000000000 +0100
+++ application/application.pro	2011-02-10 21:37:18.000000000 +0100
@@ -4,20 +4,16 @@
     src \
     ui
 
-linux-g++ {
+unix {
 	INCLUDEPATH += . \
 	    src \
-	    src/include \
-	    /usr/include \
-	    /usr/include/hunspell \
-	    /usr/include/libxml++-2.6 \
-	    /usr/include/glibmm-2.4 \
-	    /usr/lib/glibmm-2.4/include \
-	    /usr/include/glib-2.0 \
-	    /usr/lib/glib-2.0/include \
-	    /usr/lib/libxml++-2.6/include \
-	    /usr/include/SDL
-	
+	    src/include
+	PKGCONFIG += \
+	    glib-2.0 \
+	    hunspell \
+	    libcurl \
+	    libxml++-2.6 \
+	    SDL_mixer
 }
 
 macx {
@@ -85,40 +81,33 @@
     src/asciireporter.cpp
 RESOURCES += resource/textroom.qrc \
 	resource/images/icons-app.qrc 
-linux-g++ {
+unix {
     CONFIG += release \
+        link_pkgconfig \
         build_all
     INSTALLS += data \
         dict \
         target \
         desktop \
-        uninstaller \
         mime \
 	words \
         icon
-    LIBS = -lSDL_mixer \
-	-lSDL \
-        -lhunspell \
-	-lglibmm-2.4 \
-	-lcurl \
-	-lxml++-2.6 \
+    LIBS = \
 	$$TOPDIR/lib/libflo.a
-    data.path = /usr/share/sounds
+    data.path = $$PREFIX/share/sounds
     data.files = resource/sounds/*
-    target.path = /usr/bin
-    words.path = /usr/share/textroom
+    target.path = $$PREFIX/bin
+    words.path = $$PREFIX/share/textroom
     words.files = resource/words.txt
-    desktop.path = /usr/share/applications
+    desktop.path = $$PREFIX/share/applications
     desktop.files = resource/desktop/textroom.desktop
-    doc-icon.path = /usr/share/textroom
+    doc-icon.path = $$PREFIX/share/textroom
     doc-icon.files = resource/images/textroom-doc.png
-    mime.path = /usr/share/textroom
+    mime.path = $$PREFIX/share/textroom
     mime.files = resource/desktop/textroom-txr-mime.xml
-    uninstaller.path = /usr/bin
-    uninstaller.files = resource/desktop/textroom-uninstall
-    dict.path = /usr/share/hunspell
+    dict.path = $$PREFIX/share/hunspell
     dict.files = resource/dict/*
-    icon.path = /usr/share/pixmaps
+    icon.path = $$PREFIX/share/pixmaps
     icon.files = resource/images/textroom.png
 }
 

--- application/application.pro.orig	2011-01-22 03:25:20.000000000 +0100
+++ application/application.pro	2011-02-10 21:37:18.000000000 +0100
@@ -4,19 +4,20 @@
     src \
     ui
 
-linux-g++ {
+freebsd-g++ {
 	INCLUDEPATH += . \
 	    src \
 	    src/include \
-	    /usr/include \
-	    /usr/include/hunspell \
-	    /usr/include/libxml++-2.6 \
-	    /usr/include/glibmm-2.4 \
-	    /usr/lib/glibmm-2.4/include \
-	    /usr/include/glib-2.0 \
-	    /usr/lib/glib-2.0/include \
-	    /usr/lib/libxml++-2.6/include \
-	    /usr/include/SDL
+	    $$LOCALBASE/include \
+	    $$LOCALBASE/include/hunspell \
+	    $$LOCALBASE/include/libxml++-2.6 \
+	    $$LOCALBASE/include//libxml++-2.6/include \
+	    $$LOCALBASE/include/glibmm-2.4 \
+	    $$LOCALBASE/lib/glibmm-2.4/include \
+	    $$LOCALBASE/include/glib-2.0 \
+	    $$LOCALBASE/lib/glib-2.0/include \
+	    $$LOCALBASE/lib/libxml++-2.6/include \
+	    $$LOCALBASE/include/SDL
 	
 }
 
@@ -85,7 +86,7 @@
     src/asciireporter.cpp
 RESOURCES += resource/textroom.qrc \
 	resource/images/icons-app.qrc 
-linux-g++ {
+freebsd-g++ {
     CONFIG += release \
         build_all
     INSTALLS += data \
@@ -98,27 +99,27 @@
         icon
     LIBS = -lSDL_mixer \
 	-lSDL \
-        -lhunspell \
+	-lhunspell-1.3 \
 	-lglibmm-2.4 \
 	-lcurl \
 	-lxml++-2.6 \
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
+    uninstaller.path = $$PREFIX/bin
     uninstaller.files = resource/desktop/textroom-uninstall
-    dict.path = /usr/share/hunspell
+    dict.path = $$PREFIX/share/hunspell
     dict.files = resource/dict/*
-    icon.path = /usr/share/pixmaps
+    icon.path = $$PREFIX/share/pixmaps
     icon.files = resource/images/textroom.png
 }
 

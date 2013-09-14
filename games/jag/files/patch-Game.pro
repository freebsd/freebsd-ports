Uses X11 functions, but doesnt link with libX11
--- Game.pro.orig	2013-09-14 02:35:13.963226272 +0400
+++ Game.pro	2013-09-14 02:36:05.820226581 +0400
@@ -24,7 +24,8 @@
 }
 LIBS += -lSDLmain \
     -lSDL \
-    -lSDL_mixer
+    -lSDL_mixer \
+    -lX11
 TEMPLATE = app
 SOURCES += main.cpp \
     gamewidget.cpp \

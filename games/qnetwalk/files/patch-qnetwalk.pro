--- qnetwalk.pro.orig	2013-11-19 20:16:32.939772682 +0400
+++ qnetwalk.pro	2013-11-19 20:17:29.555796500 +0400
@@ -1,7 +1,7 @@
 
 TEMPLATE	= app
 CONFIG	       += qt warn_on
-LIBS           += -lSDL_mixer
+LIBS           += -lSDL_mixer -lSDL
 
 HEADERS		= cell.h	\
 		  mainwindow.h  \

--- amarokFS-xml.pro.orig	Mon Mar 19 08:17:58 2007
+++ amarokFS-xml.pro	Wed Jun 20 17:23:39 2007
@@ -3,13 +3,9 @@
 
 CONFIG		+= qt warn_on release
 
-INCLUDEPATH += /usr/include/kde
-INCLUDEPATH += /usr/local/include/kde
-INCLUDEPATH += /usr/include
-INCLUDEPATH += /opt/kde3/include 
-INCLUDEPATH += /opt/kde/include
-INCLUDEPATH += /usr/kde/3.5/include
-		
+INCLUDEPATH += /usr/include/
+INCLUDEPATH += ${LOCALBASE}/include/
+INCLUDEPATH += ${LOCALBASE}/include/X11
 				
 HEADERS	= amfs-xml.h \
 	cb.h \
@@ -25,36 +21,27 @@
 	label-pixmap.cpp
 
 LIBS += -lkdecore
-LIBS += -L/opt/kde3/lib
-LIBS += -L/usr/local/kde3/lib
-LIBS += -L/usr/lib/qt3
-LIBS += -L/opt/kde/lib
-LIBS += -L/usr/kde/3.5/lib
+LIBS += -L${LOCALBASE}/lib
+LIBS += -L${LOCALBASE}/lib/X11
 LIBS += -lkio
 		
-images.path = /usr/share/amarokFS/images
+images.path = ${PREFIX}/share/amarokFS/images
 images.files = images/*
 
-defaultTheme.path = /usr/share/amarokFS
+defaultTheme.path = ${PREFIX}/share/amarokFS
 defaultTheme.files = theme.xml
 		
-target.path = /usr/local/bin
+target.path = ${PREFIX}/bin
 		
 icon.files = amarokFS.png
-icon.path = /usr/share/icons/
+icon.path = ${PREFIX}/share/icons/hicolor/128x128/apps/
 		
 desktop.files = amarokFS.desktop
-desktop.path = /usr/share/applications/
+desktop.path = ${PREFIX}/share/applications/
 		
-docs.files = README
-docs.files += theme-howto.txt
-docs.path = /usr/share/doc/amarokFS
-
-
 INSTALLS += target
 INSTALLS += images
 INSTALLS += desktop
 INSTALLS += icon
 INSTALLS += defaultTheme
-INSTALLS += docs
 		

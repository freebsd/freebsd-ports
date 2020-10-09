--- mpz.pro.orig	2020-10-08 17:36:49 UTC
+++ mpz.pro
@@ -2,17 +2,15 @@ TEMPLATE = subdirs
 CONFIG += ordered
 
 SUBDIRS = \
-  libs/taglib \
-  libs/yaml-cpp \
   libs/qtwaitingspinner \
   libs/qhotkey \
   app
 
 # make install
-desktop.path = /usr/share/applications/
+desktop.path = $$PREFIX/share/applications/
 desktop.files += mpz.desktop
 
-icon.path = /usr/share/icons/hicolor/512x512/apps/
+icon.path = $$PREFIX/share/icons/hicolor/512x512/apps/
 icon.files += app/resources/icons/mpz.png
 
 INSTALLS += desktop icon

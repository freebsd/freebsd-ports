--- mpz.pro.orig	2020-10-22 11:15:32 UTC
+++ mpz.pro
@@ -2,39 +2,37 @@ TEMPLATE = subdirs
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
 
-icon512.path = /usr/share/icons/hicolor/512x512/apps/
+icon512.path = $$PREFIX/share/icons/hicolor/512x512/apps/
 icon512.files += app/resources/icons/512x512/mpz.png
-icon256.path = /usr/share/icons/hicolor/256x256/apps/
+icon256.path = $$PREFIX/share/icons/hicolor/256x256/apps/
 icon256.files += app/resources/icons/256x256/mpz.png
-icon192.path = /usr/share/icons/hicolor/192x192/apps/
+icon192.path = $$PREFIX/share/icons/hicolor/192x192/apps/
 icon192.files += app/resources/icons/192x192/mpz.png
-icon128.path = /usr/share/icons/hicolor/128x128/apps/
+icon128.path = $$PREFIX/share/icons/hicolor/128x128/apps/
 icon128.files += app/resources/icons/128x128/mpz.png
-icon96.path = /usr/share/icons/hicolor/96x96/apps/
+icon96.path = $$PREFIX/share/icons/hicolor/96x96/apps/
 icon96.files += app/resources/icons/96x96/mpz.png
-icon72.path = /usr/share/icons/hicolor/72x72/apps/
+icon72.path = $$PREFIX/share/icons/hicolor/72x72/apps/
 icon72.files += app/resources/icons/72x72/mpz.png
-icon64.path = /usr/share/icons/hicolor/64x64/apps/
+icon64.path = $$PREFIX/share/icons/hicolor/64x64/apps/
 icon64.files += app/resources/icons/64x64/mpz.png
-icon48.path = /usr/share/icons/hicolor/48x48/apps/
+icon48.path = $$PREFIX/share/icons/hicolor/48x48/apps/
 icon48.files += app/resources/icons/48x48/mpz.png
-icon32.path = /usr/share/icons/hicolor/32x32/apps/
+icon32.path = $$PREFIX/share/icons/hicolor/32x32/apps/
 icon32.files += app/resources/icons/32x32/mpz.png
-icon24.path = /usr/share/icons/hicolor/24x24/apps/
+icon24.path = $$PREFIX/share/icons/hicolor/24x24/apps/
 icon24.files += app/resources/icons/24x24/mpz.png
-icon22.path = /usr/share/icons/hicolor/22x22/apps/
+icon22.path = $$PREFIX/share/icons/hicolor/22x22/apps/
 icon22.files += app/resources/icons/22x22/mpz.png
-icon16.path = /usr/share/icons/hicolor/16x16/apps/
+icon16.path = $$PREFIX/share/icons/hicolor/16x16/apps/
 icon16.files += app/resources/icons/16x16/mpz.png
 
 INSTALLS += desktop icon512 icon256 icon192 icon128 icon96 icon72 icon64 icon48 icon32 icon24 icon22 icon16

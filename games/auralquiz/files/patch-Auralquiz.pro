--- Auralquiz.pro.orig	2017-05-11 10:46:54 UTC
+++ Auralquiz.pro
@@ -89,19 +89,19 @@ TRANSLATIONS += translations/auralquiz_e
 LIBS += -ltag # to use TagLib
 
 ## This is here so the makefile has a 'make install' target
-target.path = /usr/games/
+target.path = %%PREFIX%%/bin/
 
 desktop_file.files = auralquiz.desktop
-desktop_file.path = /usr/share/applications/
+desktop_file.path = %%PREFIX%%/share/applications/
 
 man_file.files = manual/auralquiz.6
-man_file.path = /usr/share/man/man6/
+man_file.path = %%PREFIX%%/share/man/man6/
 
 #icon32_png.files = icon/32x32/auralquiz.png
-#icon32_png.path = /usr/share/icons/hicolor/32x32/apps/
+#icon32_png.path = %%PREFIX%%/share/icons/hicolor/32x32/apps/
 
 icon64_png.files = icon/64x64/auralquiz.png
-icon64_png.path = /usr/share/icons/hicolor/64x64/apps/
+icon64_png.path = %%PREFIX%%/share/icons/hicolor/64x64/apps/
 
 INSTALLS += target \
             desktop_file \

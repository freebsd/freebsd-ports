--- app/app.pro.orig	2022-05-28 06:35:00 UTC
+++ app/app.pro
@@ -205,7 +205,7 @@ RESOURCES += \
   ../resources.qrc
 
 # make install
-target.path = /usr/bin/
+target.path = $$PREFIX/bin/
 INSTALLS += target
 
 TRANSLATIONS += \

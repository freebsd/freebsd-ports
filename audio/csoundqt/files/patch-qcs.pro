--- qcs.pro.orig	2020-01-13 20:37:47 UTC
+++ qcs.pro
@@ -245,7 +245,7 @@ unix:!macx {
 	#appImage.commands = cd $$OUT_PWD/$$DESTDIR/; ln -sf $$TARGET csoundqt
     appImage.commands += export VERSION=0.9.7-beta; export QML_SOURCES_PATHS=$$PWD/src/QML;
     #TODO: kas dekstop failis vaja seada käivitatav $$TARGETiks või siis bianry oleks csounqt. praegu nimetan käsitisi ümber AppDir/usr/bin juures
-    appImage.commands += linuxdeploy --appdir AppDir --executable=$$TARGET  --desktop-file=$$PWD/csoundqt.desktop  -i $$PWD/images/csoundqt.svg  --plugin=qt #  --output appimage
+    #appImage.commands += linuxdeploy --appdir AppDir --executable=$$TARGET  --desktop-file=$$PWD/csoundqt.desktop  -i $$PWD/images/csoundqt.svg  --plugin=qt #  --output appimage
     # move and remove what necessary here:
     #  appImage.commands += linuxdeploy --appdir AppDir  --output appimage
 	#INSTALLS += appImage

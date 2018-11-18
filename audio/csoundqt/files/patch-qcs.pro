--- qcs.pro.orig	2018-11-18 08:13:18 UTC
+++ qcs.pro
@@ -187,13 +187,13 @@ unix:!macx {
 	desktop.path=$$SHARE_DIR/applications
 	desktop.files=CsoundQt.desktop
 
-	icon.path=$$SHARE_DIR/icons # not sure in fact, if /usr/share/icons is enough or better to put into hicolor...
+	icon.path=$$SHARE_DIR/icons/hicolor/scalable/apps/ # not sure in fact, if /usr/share/icons is enough or better to put into hicolor...
 	icon.files=images/qtcs.svg
 
 	mimetypes.path=$$INSTALL_DIR # in some reason path must be set to create install target in Makefile
 	mimetypes.commands = cd $$PWD/mime-types/; ./add_csound_mimetypes.sh $(INSTALL_ROOT)/$$INSTALL_DIR
 
-	examples.path = $$SHARE_DIR/qutecsound/
+	examples.path = $$SHARE_DIR/CsoundQt/
 	examples.files = src/Examples
 
 	INSTALLS += target desktop icon mimetypes examples

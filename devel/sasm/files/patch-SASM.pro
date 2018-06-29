--- SASM.pro.orig	2018-06-28 23:51:49 UTC
+++ SASM.pro
@@ -25,13 +25,13 @@ data.files += Linux/share/sasm/*
 data.path = $$DATADIR/sasm/
 shortcutfiles.files += Linux/share/applications/sasm.desktop
 shortcutfiles.path = $$DATADIR/applications/
-docfiles.files += Linux/share/doc/sasm/changelog.gz
-docfiles.files += Linux/share/doc/sasm/copyright
-docfiles.path = $$DATADIR/doc/sasm/
+#docfiles.files += Linux/share/doc/sasm/changelog.gz
+#docfiles.files += Linux/share/doc/sasm/copyright
+#docfiles.path = $$DATADIR/doc/sasm/
 INSTALLS += binfile
 INSTALLS += data
 INSTALLS += shortcutfiles
-INSTALLS += docfiles
+#INSTALLS += docfiles
 
 include(singleapplication/qtsingleapplication.pri)
 

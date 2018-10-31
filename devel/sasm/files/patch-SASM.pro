--- SASM.pro.orig	2018-10-31 01:24:21 UTC
+++ SASM.pro
@@ -39,15 +39,15 @@ unix:!linux {
     data.path = $$DATADIR/sasm/
     shortcutfiles.files += BSD/share/applications/sasm.desktop
     shortcutfiles.path = $$DATADIR/applications/
-    docfiles.files += BSD/share/doc/sasm/changelog.gz
-    docfiles.files += BSD/share/doc/sasm/copyright
-    docfiles.path = $$DATADIR/doc/sasm/
+#    docfiles.files += BSD/share/doc/sasm/changelog.gz
+#    docfiles.files += BSD/share/doc/sasm/copyright
+#    docfiles.path = $$DATADIR/doc/sasm/
 }
 
 INSTALLS += binfile
 INSTALLS += data
 INSTALLS += shortcutfiles
-INSTALLS += docfiles
+#INSTALLS += docfiles
 
 include(singleapplication/qtsingleapplication.pri)
 

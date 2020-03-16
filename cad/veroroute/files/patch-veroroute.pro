--- veroroute.pro.orig	2020-03-16 00:59:58 UTC
+++ veroroute.pro
@@ -118,7 +118,7 @@ unix {
     target.path = $${PREFIX}/bin/
     target.files = ../veroroute
 
-    manpage.path = $${PREFIX}/share/man/man1
+    manpage.path = $${PREFIX}/man/man1
     manpage.files = ../veroroute.1
 
     desktopentry.path = $${PREFIX}/share/applications

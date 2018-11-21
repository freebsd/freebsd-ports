--- app/app.pro.orig	2018-11-21 09:01:18 UTC
+++ app/app.pro
@@ -135,7 +135,7 @@ win32 {
     RC_FILE = data/pencil2d.rc
 }
 
-linux {
+freebsd {
     target.path = $${PREFIX}/bin
 
     bashcompletion.files = data/pencil2d

--- www/P4CGI.pm.orig	Wed Dec 13 08:30:28 2000
+++ www/P4CGI.pm	Sun Sep  2 04:17:42 2001
@@ -13,7 +13,7 @@
 
 sub ConfigFileName()
 {
-    return "./P4DB.conf" ; # Change here to rename configuration file
+    return "../P4DB.conf" ; # Change here to rename configuration file
 }
 
 use CGI ;

--- digikam/kioslave/digikamdates.cpp.orig	Tue Apr 11 13:53:08 2006
+++ digikam/kioslave/digikamdates.cpp	Tue Apr 11 13:53:54 2006
@@ -186,7 +186,7 @@
                          .arg(moStr2)
                          .arg(yr,4)
                          .arg(moStr1,2),
-                         &values, false);
+                         &values);
 
             Q_LLONG     imageid;
             QString     name;

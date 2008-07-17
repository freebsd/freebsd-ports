--- digikam/kioslave/digikamdates.cpp.orig	2008-07-16 21:05:55.000000000 +0200
+++ digikam/kioslave/digikamdates.cpp	2008-07-17 08:28:24.000000000 +0200
@@ -199,7 +199,7 @@
                          .arg(moEndStr, 2)
                          .arg(yrStart, 4)
                          .arg(moStartStr, 2),
-                         &values, false);
+                         &values);
 
             Q_LLONG     imageid;
             QString     name;

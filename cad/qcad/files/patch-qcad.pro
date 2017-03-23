--- qcad.pro.orig	2017-03-21 17:03:39.136811000 +0000
+++ qcad.pro	2017-03-21 16:00:21.618687000 +0000
@@ -13,7 +13,7 @@
     }
 }
-else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v qcadmobile")
-}
+#else {
+#    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v qcadmobile")
+#}
 
 !r_mobile {

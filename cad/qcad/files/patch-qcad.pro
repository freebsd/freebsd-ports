--- qcad.pro.orig	2017-06-03 16:46:16.887320000 +0200
+++ qcad.pro	2017-06-03 16:46:29.469101000 +0200
@@ -13,7 +13,7 @@
     }
 }
-else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$ | grep -v qcadmobile")
-}
+#else {
+#    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$ | grep -v qcadmobile")
+#}
 
 !r_mobile {

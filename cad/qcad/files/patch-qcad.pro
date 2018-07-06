--- qcad.pro.orig	2018-06-19 20:32:20 UTC
+++ qcad.pro
@@ -12,9 +12,9 @@ win32 {
         SUBDIRS += ..\\$$dir
     }
 }
-else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$ | grep -v qcadmobile")
-}
+#else {
+#    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$ | grep -v qcadmobile")
+#}
 
 !r_mobile {
     exists(support) {

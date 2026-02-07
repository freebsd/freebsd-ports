--- qcad.pro.orig	2019-05-04 22:28:42 UTC
+++ qcad.pro
@@ -11,9 +11,9 @@ win32 {
         SUBDIRS += ..\\$$dir
     }
 }
-else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$")
-}
+#else {
+#    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$")
+#}
 
 !r_mobile {
     exists(support) {

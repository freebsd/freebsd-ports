--- src/lib.pri.orig	2021-08-27 07:30:53 UTC
+++ src/lib.pri
@@ -14,7 +14,7 @@ win32 {
 
 } else {
 
-  target.path = $$PREFIX
+  target.path = $$shell_path($(INSTALLROOT)$$PREFIX/lib/klayout)
   INSTALLS += target
 
 }

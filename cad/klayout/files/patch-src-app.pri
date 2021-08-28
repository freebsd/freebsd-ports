--- src/app.pri.orig	2021-08-27 07:30:18 UTC
+++ src/app.pri
@@ -1,5 +1,5 @@
 
 TEMPLATE = app
 
-target.path = $$PREFIX
+target.path = $$shell_path($(INSTALLROOT)$$PREFIX/bin)
 INSTALLS += target

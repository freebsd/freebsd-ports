--- texstudio.pro.orig	2014-12-10 21:27:10 UTC
+++ texstudio.pro
@@ -531,6 +531,10 @@ unix {
     -lz
 }
 
+freebsd-* {
+    LIBS += -lexecinfo
+}
+
 # ################################
 # Poppler PDF Preview, will only be used if NO_POPPLER_PREVIEW is not set
 isEmpty(NO_POPPLER_PREVIEW) {

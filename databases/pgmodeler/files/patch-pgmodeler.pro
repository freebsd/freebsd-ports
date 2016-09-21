--- pgmodeler.pro.orig	2015-07-30 16:48:48 UTC
+++ pgmodeler.pro
@@ -20,12 +20,13 @@ SUBDIRS = libutils \
           libpgmodeler_ui
 
 # Include the tests and plugins subprojects only on debug mode
-CONFIG(debug, debug|release): SUBDIRS += tests plugins
+#CONFIG(debug, debug|release): SUBDIRS += tests plugins
 
 # Including executables subprojects (libraries only)
 SUBDIRS += crashhandler \
            main-cli \
-           main
+           main \
+	   plugins
 
 # Deployment settings
 samples.files = samples/*

--- QGLViewer.pro	2006-12-12 17:55:29.000000000 -0200
+++ b	2009-04-04 13:52:14.000000000 -0300
@@ -79,9 +79,9 @@
 
   # Adds a -P option so that "make install" as root creates files owned by root and links are preserved.
   # This is not a standard option, and it may have to be removed on old Unix flavors.
-  !hpux {
-    QMAKE_COPY_FILE = $${QMAKE_COPY_FILE} -P
-  }
+  #!hpux {
+  #  QMAKE_COPY_FILE = $${QMAKE_COPY_FILE} -P
+  #}
 
   # Make much smaller libraries by removing debugging informations
   QMAKE_CFLAGS_RELEASE -= -g
@@ -92,20 +92,20 @@
   include.files = $${HEADERS} qglviewer.cw
 
   # install documentation html
-  documentation.path = $${DOC_DIR}/QGLViewer
-  documentation.files = ../doc/*.html ../doc/*.css
+  #documentation.path = $${DOC_DIR}/QGLViewer
+  #documentation.files = ../doc/*.html ../doc/*.css
 
   # install documentation images
-  docImages.path = $${DOC_DIR}/QGLViewer/images
-  docImages.files = ../doc/images/*
+  #docImages.path = $${DOC_DIR}/QGLViewer/images
+  #docImages.files = ../doc/images/*
 
   # install documentation examples
   #docExamples.path = $${DOC_DIR}/QGLViewer/examples
   #docExamples.files = ../examples/*../examples/*/*
 
   # install documentation refManual
-  docRefManual.path = $${DOC_DIR}/QGLViewer/refManual
-  docRefManual.files = ../doc/refManual/*
+  #docRefManual.path = $${DOC_DIR}/QGLViewer/refManual
+  #docRefManual.files = ../doc/refManual/*
 
   # install static library
   staticlib.extra = make staticlib

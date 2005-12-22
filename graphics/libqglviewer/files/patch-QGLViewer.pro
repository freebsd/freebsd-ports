--- QGLViewer.pro.orig	Thu Dec 22 17:32:51 2005
+++ QGLViewer.pro	Thu Dec 22 17:33:00 2005
@@ -79,9 +79,9 @@
 
   # Adds a -P option so that "make install" as root creates files owned by root and links are preserved.
   # This is not a standard option, and it may have to be removed on old Unix flavors.
-  !hpux {
-    QMAKE_COPY_FILE = $${QMAKE_COPY_FILE} -P
-  }
+#  !hpux {
+#    QMAKE_COPY_FILE = $${QMAKE_COPY_FILE} -P
+#  }
 
   # Make much smaller libraries by removing debugging informations
   QMAKE_CFLAGS_RELEASE -= -g

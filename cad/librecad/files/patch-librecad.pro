--- ./librecad.pro.orig	2011-12-14 18:07:34.000000000 +0000
+++ ./librecad.pro	2012-01-03 10:28:08.504074615 +0000
@@ -45,7 +45,6 @@
         RC_FILE = res/main/librecad.icns
         DESTDIR = unix
         
-        QMAKE_POST_LINK = scripts/postprocess-unix.sh
     }
 }
 win32 { 

--- src/src.pro.orig	2010-10-25 20:58:53.000000000 +0900
+++ src/src.pro	2011-01-04 22:44:01.000000000 +0900
@@ -56,8 +56,8 @@
     message("dynamic qt")
 }
 unix{
-  LIBS += -lfreetype -ldl -lz
-  INCLUDEPATH += /usr/include/freetype2
+  LIBS += -lfreetype -lz
+  INCLUDEPATH += ${PREFIX}/include/freetype2
   DEFINES += LINUX
  NOPRINTING = 4.3.0 4.3.1 4.3.2 4.3.3 4.3.4 4.4.0 4.4.1 4.4.2 4.4.3 4.4.4 4.4.5 4.5.0 4.5.1
  contains( NOPRINTING, $$QT_VERSION ){
@@ -668,4 +668,4 @@
 	}
     message("GENISYS version")
 
-}
\ No newline at end of file
+}

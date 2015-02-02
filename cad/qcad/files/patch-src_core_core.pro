--- src/core/core.pro.orig	2015-01-11 21:24:31.997403718 +0100
+++ src/core/core.pro	2015-01-11 21:24:46.507444784 +0100
@@ -272,5 +272,5 @@
 DEFINES += QCADCORE_LIBRARY
 
-LIBS += -lopennurbs -lzlib
+LIBS += -lopenNURBS -lz
 
 win32 {

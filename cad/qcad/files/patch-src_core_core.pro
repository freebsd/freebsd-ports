--- src/core/core.pro.orig	2013-08-06 17:32:09.000000000 +0200
+++ src/core/core.pro	2013-08-08 11:01:42.000000000 +0200
@@ -232,7 +232,7 @@
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY
 
-LIBS += -lzlib -lopennurbs
+LIBS += -lz -lopenNURBS
 
 win32 {
     LIBS += -lRpcrt4 -lAdvapi32

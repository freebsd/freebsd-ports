--- src/core/core.pro.orig	2026-05-06 14:27:07 UTC
+++ src/core/core.pro
@@ -324,7 +324,7 @@ DEFINES += QCADCORE_LIBRARY
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY
 
-LIBS += -lopennurbs -lzlib
+LIBS += -lopenNURBS -lz
 
 win32 {
     LIBS += -lRpcrt4 -lAdvapi32

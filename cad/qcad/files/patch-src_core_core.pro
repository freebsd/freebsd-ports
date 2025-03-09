--- src/core/core.pro.orig	2025-02-10 09:29:49 UTC
+++ src/core/core.pro
@@ -318,7 +318,7 @@ DEFINES += QCADCORE_LIBRARY
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY
 
-LIBS += -lopennurbs -lzlib
+LIBS += -lopenNURBS -lz
 
 win32 {
     LIBS += -lRpcrt4 -lAdvapi32

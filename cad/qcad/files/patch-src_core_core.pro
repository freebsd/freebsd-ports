--- src/core/core.pro.orig	2019-05-01 14:25:33 UTC
+++ src/core/core.pro
@@ -290,7 +290,7 @@ RC_FILE = core.rc
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY
 
-LIBS += -lopennurbs -lzlib
+LIBS += -lopenNURBS -lz
 
 win32 {
     LIBS += -lRpcrt4 -lAdvapi32

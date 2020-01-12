--- src/core/core.pro.orig	2019-12-23 11:24:24 UTC
+++ src/core/core.pro
@@ -295,7 +295,7 @@ RC_FILE = core.rc
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY
 
-LIBS += -lopennurbs -lzlib
+LIBS += -lopenNURBS -lz
 
 win32 {
     LIBS += -lRpcrt4 -lAdvapi32

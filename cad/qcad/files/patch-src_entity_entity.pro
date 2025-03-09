--- src/entity/entity.pro.orig	2025-02-10 09:29:49 UTC
+++ src/entity/entity.pro
@@ -147,7 +147,7 @@ RC_FILE = entity.rc
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
 RC_FILE = entity.rc
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += -l$${RLIBNAME}core -lopenNURBS
 !win32 {
     include( ../../shared_ts.pri )
 }

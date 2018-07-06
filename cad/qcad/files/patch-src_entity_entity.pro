--- src/entity/entity.pro.orig	2018-06-19 20:32:20 UTC
+++ src/entity/entity.pro
@@ -132,7 +132,7 @@ TARGET = $${NAME}
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
 RC_FILE = entity.rc
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += -l$${RLIBNAME}core -lopenNURBS
 !win32 {
     include( ../../shared_ts.pri )
 }

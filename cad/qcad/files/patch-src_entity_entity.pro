--- src/entity/entity.pro.orig	2026-08-29 15:56:10 UTC
+++ src/entity/entity.pro
@@ -142,4 +142,4 @@ RC_FILE = entity.rc
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
 RC_FILE = entity.rc
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += -l$${RLIBNAME}core --lopenNURBS

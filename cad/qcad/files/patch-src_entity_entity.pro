--- src/entity/entity.pro.orig	2013-08-06 17:32:09.000000000 +0200
+++ src/entity/entity.pro	2013-08-08 11:29:12.000000000 +0200
@@ -91,7 +91,7 @@
 TARGET = $${NAME}
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
-LIBS += -lqcadcore -lopennurbs
+LIBS += -lqcadcore -lopenNURBS
 !win32 {
     include( ../../shared_ts.pri )
 }

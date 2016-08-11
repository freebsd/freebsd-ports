--- src/entity/entity.pro.orig	2016-06-08 19:38:26.408322000 +0000
+++ src/entity/entity.pro	2016-06-08 19:39:06.335114000 +0000
@@ -116,5 +116,5 @@
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += -l$${RLIBNAME}core -lopenNURBS
 !win32 {
     include( ../../shared_ts.pri )

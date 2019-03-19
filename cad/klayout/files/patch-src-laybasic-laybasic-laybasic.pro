--- src/laybasic/laybasic/laybasic.pro.orig	2019-02-23 17:34:47 UTC
+++ src/laybasic/laybasic/laybasic.pro
@@ -6,6 +6,8 @@ include($$PWD/../../lib.pri)
 
 DEFINES += MAKE_LAYBASIC_LIBRARY
 
+QT += widgets gui
+
 FORMS = \
   AlignCellOptionsDialog.ui \
   BookmarkManagementForm.ui \
@@ -273,7 +275,7 @@ HEADERS = \
   laybasicConfig.h \
   layBackgroundAwareTreeStyle.h
 
-INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC
+INCLUDEPATH += . $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC
 LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db -lklayout_rdb
 

--- ugene.pro.orig	2016-03-31 12:21:56 UTC
+++ ugene.pro
@@ -20,7 +20,6 @@ use_bundled_zlib() {
 }
 
 SUBDIRS += \
-          src/libs_3rdparty/breakpad \
           src/libs_3rdparty/qscore \
           src/libs_3rdparty/sqlite3 \
           src/libs_3rdparty/gtest \
@@ -144,15 +143,8 @@ UGENE_TRANSL_QM_TARGET_DIR = $$OUT_PWD/s
 win32 : UGENE_DEV_NULL = nul
 unix : UGENE_DEV_NULL = /dev/null
 
-UGENE_LRELEASE =
-UGENE_LUPDATE = 
-system(lrelease-qt5 -version > $$UGENE_DEV_NULL 2> $$UGENE_DEV_NULL) {
-    UGENE_LRELEASE = lrelease-qt5
-    UGENE_LUPDATE = lupdate-qt5
-} else : system(lrelease -version > $$UGENE_DEV_NULL 2> $$UGENE_DEV_NULL) {
-    UGENE_LRELEASE = lrelease
-    UGENE_LUPDATE = lupdate
-}
+UGENE_LRELEASE = $$LRELEASE
+UGENE_LUPDATE = $$LUPDATE
 
 #foreach 'language'
 for( i, UGENE_TRANSL_IDX ) {

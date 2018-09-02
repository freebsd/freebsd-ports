--- ugene.pro.orig	2018-08-16 13:58:51 UTC
+++ ugene.pro
@@ -20,7 +20,6 @@ use_bundled_zlib() {
 }
 
 SUBDIRS += \
-          src/libs_3rdparty/breakpad \
           src/libs_3rdparty/qscore \
           src/libs_3rdparty/sqlite3 \
           src/libs_3rdparty/samtools \
@@ -141,16 +140,8 @@ UGENE_TRANSL_QM_TARGET_DIR = $$OUT_PWD/src/_debug $$OU
 win32 : UGENE_DEV_NULL = nul
 unix : UGENE_DEV_NULL = /dev/null
 
-UGENE_LRELEASE =
-UGENE_LUPDATE =
-message(Using QT from $$[QT_INSTALL_BINS])
-system($$[QT_INSTALL_BINS]/lrelease-qt5 -version > $$UGENE_DEV_NULL 2> $$UGENE_DEV_NULL) {
-    UGENE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease-qt5
-    UGENE_LUPDATE = $$[QT_INSTALL_BINS]/lupdate-qt5
-} else : system($$[QT_INSTALL_BINS]/lrelease -version > $$UGENE_DEV_NULL 2> $$UGENE_DEV_NULL) {
-    UGENE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
-    UGENE_LUPDATE = $$[QT_INSTALL_BINS]/lupdate
-}
+UGENE_LRELEASE = $$LRELEASE
+UGENE_LUPDATE = $$LUPDATE
 
 #foreach 'language'
 for( i, UGENE_TRANSL_IDX ) {

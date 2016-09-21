--- main-cli/main-cli.pro.orig	2015-07-30 16:48:48 UTC
+++ main-cli/main-cli.pro
@@ -23,7 +23,7 @@ SOURCES += src/main.cpp \
 
 HEADERS += src/pgmodelercli.h
 
-unix|windows: LIBS += -L$$OUT_PWD/../libpgmodeler_ui/ -lpgmodeler_ui \
+unix|windows: LIBS += $$QMAKE_LIBS_EXECINFO -L$$OUT_PWD/../libpgmodeler_ui/ -lpgmodeler_ui \
                     -L$$OUT_PWD/../libobjrenderer/ -lobjrenderer \
                     -L$$OUT_PWD/../libpgconnector/ -lpgconnector \
                     -L$$OUT_PWD/../libpgmodeler/ -lpgmodeler \

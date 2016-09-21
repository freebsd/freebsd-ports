--- main/main.pro.orig	2015-07-30 16:48:48 UTC
+++ main/main.pro
@@ -21,7 +21,7 @@ HEADERS += src/application.h
 SOURCES += src/main.cpp \
            src/application.cpp
 
-unix|windows: LIBS += -L$$OUT_PWD/../libpgmodeler_ui/ -lpgmodeler_ui \
+unix|windows: LIBS += $$QMAKE_LIBS_EXECINFO -L$$OUT_PWD/../libpgmodeler_ui/ -lpgmodeler_ui \
                     -L$$OUT_PWD/../libobjrenderer/ -lobjrenderer \
                     -L$$OUT_PWD/../libpgconnector/ -lpgconnector \
                     -L$$OUT_PWD/../libpgmodeler/ -lpgmodeler \

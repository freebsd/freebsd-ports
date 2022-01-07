--- app/app.pro.orig	2021-12-26 14:16:12 UTC
+++ app/app.pro
@@ -137,12 +137,8 @@ macx {
       ./src/qt/spelling/dictionary_provider_voikko.cpp
 
 } else:unix {
-    # pkgconfig-based configuration does not work @ Ubuntu distribution build
-    #  CONFIG += link_pkgconfig
-    #  PKGCONFIG += hunspell
-    # hardcoded paths are unfortunately more robust:
-    INCLUDEPATH += /usr/include/hunspell
-    LIBS += -lhunspell
+    CONFIG += link_pkgconfig
+    PKGCONFIG += hunspell
 
     HEADERS += \
       ./src/qt/spelling/dictionary_provider_hunspell.h \

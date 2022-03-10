--- app/app.pro.orig	2022-01-09 17:09:45 UTC
+++ app/app.pro
@@ -160,13 +160,8 @@ macx {
       ./src/qt/spelling/dictionary_provider_voikko.cpp
 
 } else:unix {
-    # pkgconfig-based configuration does not work @ Ubuntu
-    #  CONFIG += link_pkgconfig
-    #  PKGCONFIG += hunspell
-
-    # hardcoded paths are (unfortunately) more robust:
-    INCLUDEPATH += /usr/include/hunspell
-    LIBS += -lhunspell
+    CONFIG += link_pkgconfig
+    PKGCONFIG += hunspell
 
     HEADERS += \
       ./src/qt/spelling/dictionary_provider_hunspell.h \

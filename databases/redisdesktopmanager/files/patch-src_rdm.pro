--- src/rdm.pro.orig	2020-08-10 20:02:36 UTC
+++ src/rdm.pro
@@ -30,7 +30,6 @@ SOURCES += \
     $$files($$PWD/modules/console/*.cpp) \
     $$files($$PWD/modules/value-editor/*model.cpp) \
     $$files($$PWD/modules/value-editor/embedded*.cpp) \
-    $$files($$PWD/modules/updater/*.cpp) \
     $$files($$PWD/modules/bulk-operations/*.cpp) \
     $$files($$PWD/modules/bulk-operations/operations/*.cpp) \
     $$files($$PWD/modules/common/*.cpp) \
@@ -50,7 +49,6 @@ HEADERS  += \
     $$files($$PWD/modules/value-editor/*factory.h) \
     $$files($$PWD/modules/value-editor/*model.h) \
     $$files($$PWD/modules/value-editor/embedded*.h) \
-    $$files($$PWD/modules/updater/*.h) \
     $$files($$PWD/modules/*.h) \
     $$files($$PWD/modules/bulk-operations/*.h) \
     $$files($$PWD/modules/bulk-operations/operations/*.h) \
@@ -102,8 +100,8 @@ unix:!macx { # ubuntu & debian
 
     QMAKE_CXXFLAGS += -Wno-sign-compare    
 
-    release: DESTDIR = $$PWD/../bin/linux/release
-    debug:   DESTDIR = $$PWD/../bin/linux/debug
+    release: DESTDIR = $$PWD/../bin/freebsd/release
+    debug:   DESTDIR = $$PWD/../bin/freebsd/debug
 
     #deployment
     LINUX_INSTALL_PATH = /opt/redis-desktop-manager

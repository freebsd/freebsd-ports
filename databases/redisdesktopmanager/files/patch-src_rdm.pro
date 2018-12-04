--- src/rdm.pro.orig	2018-11-27 08:26:54 UTC
+++ src/rdm.pro
@@ -25,8 +25,6 @@ SOURCES += \
     $$PWD/modules/connections-tree/items/*.cpp \
     $$PWD/modules/console/*.cpp \
     $$PWD/modules/value-editor/*.cpp \
-    $$PWD/modules/crashhandler/*.cpp \
-    $$PWD/modules/updater/*.cpp \
     $$PWD/modules/bulk-operations/*.cpp \
     $$PWD/modules/common/*.cpp \
     $$PWD/modules/server-stats/*.cpp \
@@ -41,8 +39,6 @@ HEADERS  += \
     $$PWD/modules/connections-tree/items/*.h \
     $$PWD/modules/console/*.h \
     $$PWD/modules/value-editor/*.h \
-    $$PWD/modules/crashhandler/*.h \
-    $$PWD/modules/updater/*.h \
     $$PWD/modules/*.h \
     $$PWD/modules/bulk-operations/*.h \
     $$PWD/modules/common/*.h \
@@ -96,8 +92,8 @@ unix:!macx { # ubuntu & debian
 
     QMAKE_CXXFLAGS += -Wno-sign-compare    
 
-    release: DESTDIR = $$PWD/../bin/linux/release
-    debug:   DESTDIR = $$PWD/../bin/linux/debug
+    release: DESTDIR = $$PWD/../bin/freebsd/release
+    debug:   DESTDIR = $$PWD/../bin/freebsd/debug
 
     #deployment
     LINUX_INSTALL_PATH = /opt/redis-desktop-manager

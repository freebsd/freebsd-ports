--- src/rdm.pro.orig	2018-04-13 11:23:13 UTC
+++ src/rdm.pro
@@ -26,8 +26,6 @@ SOURCES += \
     $$PWD/modules/connections-tree/items/*.cpp \
     $$PWD/modules/console/*.cpp \
     $$PWD/modules/value-editor/*.cpp \
-    $$PWD/modules/crashhandler/*.cpp \
-    $$PWD/modules/updater/*.cpp \
     $$PWD/modules/bulk-operations/*.cpp \
     $$PWD/modules/common/*.cpp \
     $$PWD/modules/server-stats/*.cpp \
@@ -42,8 +40,6 @@ HEADERS  += \
     $$PWD/modules/connections-tree/items/*.h \
     $$PWD/modules/console/*.h \
     $$PWD/modules/value-editor/*.h \
-    $$PWD/modules/crashhandler/*.h \
-    $$PWD/modules/updater/*.h \
     $$PWD/modules/*.h \
     $$PWD/modules/bulk-operations/*.h \
     $$PWD/modules/common/*.h \
@@ -97,8 +93,8 @@ unix:!macx { # ubuntu & debian
 
     QMAKE_CXXFLAGS += -Wno-sign-compare    
 
-    release: DESTDIR = ./../bin/linux/release
-    debug:   DESTDIR = ./../bin/linux/debug
+    release: DESTDIR = ./../bin/freebsd/release
+    debug:   DESTDIR = ./../bin/freebsd/debug
 
     #deployment
     target.path = /usr/share/redis-desktop-manager/bin

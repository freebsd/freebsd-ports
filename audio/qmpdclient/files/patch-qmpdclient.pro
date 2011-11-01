--- qmpdclient.pro.orig	2011-06-08 13:16:26.000000000 +0400
+++ qmpdclient.pro	2011-09-21 14:18:07.000000000 +0400
@@ -3,7 +3,7 @@
 
 # Most people need not muck about below here
 #!contains(QT_MAJOR_VERSION, 4):error(QMPDClient requires Qt 4)
-CONFIG += qt debug
+CONFIG += qt
 
 # addition ldflags for release build
 QMAKE_LFLAGS_RELEASE += -O2 -g0 -s
@@ -212,16 +212,15 @@
         SOURCES += src/qmpdclient_x11.cpp
         LIBS += -lX11
         # Check for dbus support
-        contains(QT_CONFIG, dbus) {
+        contains(CONFIG, qdbus) {
             message(DBus: enabled)
-            CONFIG += qdbus
             SOURCES += src/notifications_dbus.cpp \
             	src/qdbus_adaptor.cpp
             HEADERS += src/qdbus_adaptor.h
             DEFINES += WITH_DBUS
         }
         else {
-            message(DBus: disabled (Qt is not compiled with dbus support))
+            message(DBus: disabled)
             SOURCES += src/notifications_nodbus.cpp
         }
     }
@@ -253,6 +252,7 @@
 translations.commands = lrelease $$TRANSLATIONS
 translations.files = lang/cs_CZ.qm lang/de_DE.qm lang/es_ES.qm lang/fr_FR.qm lang/it_IT.qm lang/nl_NL.qm lang/nn_NO.qm lang/no_NO.qm lang/pt_BR.qm lang/ru_RU.qm lang/sv_SE.qm lang/tr_TR.qm lang/uk_UA.qm lang/zh_CN.qm lang/zh_TW.qm
 translations.path = $$PREFIX/share/QMPDClient/translations
+translations.CONFIG += no_check_exist
 
 INSTALLS += translations
 

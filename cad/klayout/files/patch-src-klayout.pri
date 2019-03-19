--- src/klayout.pri.orig	2019-02-23 17:34:47 UTC
+++ src/klayout.pri
@@ -68,7 +68,8 @@ QMAKE_CXXFLAGS_WARN_ON += \
     -Wno-deprecated-declarations \
     -Wno-reserved-user-defined-literal \
 
-QT += network xml sql 
+QT += network xml sql widgets 
+INCLUDEPATH += .
 
 equals(HAVE_QT5, "1") {
   QT += designer printsupport
@@ -84,7 +85,7 @@ equals(HAVE_QT5, "1") {
 win32 {
   QMAKE_LFLAGS += -Wl,--exclude-all-symbols
 } else {
-  QMAKE_CXXFLAGS += -fvisibility=hidden
+#  QMAKE_CXXFLAGS += -fvisibility=hidden
 }
 
 VERSION_STRING = $$KLAYOUT_VERSION

--- ./lib.pro.orig	2010-06-18 05:01:10.000000000 -0400
+++ ./lib.pro	2010-08-13 05:16:02.000000000 -0400
@@ -1,11 +1,6 @@
 TEMPLATE        = lib
 QT += network
 TARGET                = QtAssistantClient
-isEmpty(QT_MAJOR_VERSION) {
-   VERSION=4.3.0
-} else {
-   VERSION=$${QT_MAJOR_VERSION}.$${QT_MINOR_VERSION}.$${QT_PATCH_VERSION}
-}
 
 CONFIG                += qt warn_on
 mac|win32:CONFIG                += debug_and_release
@@ -16,8 +11,8 @@
                   qassistantclient_global.h
 SOURCES         = qassistantclient.cpp
 
-DESTDIR                = ../../../../lib
-DLLDESTDIR             = ../../../../bin
+DESTDIR                = lib
+DLLDESTDIR             = bin
 
 unix {
         QMAKE_CFLAGS += $$QMAKE_CFLAGS_SHLIB
@@ -62,7 +57,7 @@
 }
 
 qt_install_headers {
-    assistant_headers.files = $$SYNCQT.HEADER_FILES $$SYNCQT.HEADER_CLASSES
+    assistant_headers.files = $$HEADERS
     assistant_headers.path = $$[QT_INSTALL_HEADERS]/QtAssistant
     INSTALLS        += assistant_headers
 }

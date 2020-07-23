--- src/3rdparty/webkit/Source/WebKit/qt/QtWebKit.pro.orig	2018-05-29 06:56:52 UTC
+++ src/3rdparty/webkit/Source/WebKit/qt/QtWebKit.pro
@@ -115,7 +115,7 @@ CONFIG(QTDIR_build) {
 }
 
 moduleFile=$$PWD/qt_webkit_version.pri
-isEmpty(QT_BUILD_TREE):include($$moduleFile)
+include($$moduleFile)
 VERSION = $${QT_WEBKIT_MAJOR_VERSION}.$${QT_WEBKIT_MINOR_VERSION}.$${QT_WEBKIT_PATCH_VERSION}
 
 symbian {

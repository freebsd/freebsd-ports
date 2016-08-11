--- src/gui/qt_libraries.gypi.orig	2016-05-14 21:36:24.268182000 +0900
+++ src/gui/qt_libraries.gypi	2016-05-14 21:36:59.852298000 +0900
@@ -84,7 +84,7 @@
         '$(SDKROOT)/System/Library/Frameworks/Carbon.framework',
       ]
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'conditions': [
         ['qt_dir', {
           'libraries': [

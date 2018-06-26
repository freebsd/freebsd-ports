--- qwt/qwt.pro.orig	2016-08-23 19:39:13 UTC
+++ qwt/qwt.pro
@@ -206,6 +206,8 @@ HEADERS += \
 unix:!symbian {
     maemo5 {
         target.path = /opt/usr/lib
+    freebsd {
+        target.path = /usr/local/lib
     } else {
         target.path = /usr/lib
     }

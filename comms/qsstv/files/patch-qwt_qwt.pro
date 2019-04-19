--- qwt/qwt.pro.orig	2019-03-06 17:04:10 UTC
+++ qwt/qwt.pro
@@ -159,6 +159,8 @@ HEADERS += \
 unix:!symbian {
     maemo5 {
         target.path = /opt/usr/lib
+    freebsd {
+        target.path = /usr/local/lib
     } else {
         target.path = /usr/lib
     }

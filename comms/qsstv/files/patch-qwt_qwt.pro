--- qwt/qwt.pro.orig	2016-04-08 23:08:29 UTC
+++ qwt/qwt.pro
@@ -206,6 +206,8 @@ HEADERS += \
 unix:!symbian {
     maemo5 {
         target.path = /opt/usr/lib
+    freebsd {
+        target.path = %%PREFIX%%/lib
     } else {
         target.path = /usr/lib
     }

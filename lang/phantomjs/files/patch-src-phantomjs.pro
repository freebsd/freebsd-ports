--- src/phantomjs.pro.orig	2016-01-24 18:24:05 UTC
+++ src/phantomjs.pro
@@ -97,3 +97,7 @@ win32-msvc* {
 openbsd* {
     LIBS += -L/usr/X11R6/lib
 }
+
+freebsd* {
+    LIBS += -L/usr/local/lib
+}

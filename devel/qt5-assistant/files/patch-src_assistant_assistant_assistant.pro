Do not use QtWebKit even if it is present to reduce the port's dependencies.
--- src/assistant/assistant/assistant.pro.orig	2025-05-22 08:01:28 UTC
+++ src/assistant/assistant/assistant.pro
@@ -1,8 +1,4 @@
-qtHaveModule(webkitwidgets):!contains(QT_CONFIG, static) {
-    BROWSER = qtwebkit
-} else {
-    BROWSER = qtextbrowser
-}
+BROWSER = qtextbrowser
 
 QT += widgets network help sql
 qtHaveModule(printsupport): QT += printsupport

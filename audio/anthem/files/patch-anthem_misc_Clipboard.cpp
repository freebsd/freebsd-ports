--- anthem/misc/Clipboard.cpp.orig	Thu May 27 22:05:22 2004
+++ anthem/misc/Clipboard.cpp	Thu May 27 22:07:57 2004
@@ -112,7 +112,7 @@
 {
     QClipboard *clipboard = Application::application()->clipboard();
     QString text = clipboard->text();
-    if (text)
+    if (!text.isEmpty())
     {
         if (text.startsWith("Track"))
         {

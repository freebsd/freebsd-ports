--- mapeditor.cpp.orig	Sun Sep 26 22:45:57 2004
+++ mapeditor.cpp	Sun Oct 17 23:49:21 2004
@@ -53,6 +53,8 @@
 #include "icons/flag-flash.xpm"
 #include "icons/flag-lifebelt.xpm"
 
+#include <unistd.h>
+
 extern TextEditor *textEditor;
 extern int statusbarTime;
 extern Main *mainWindow;

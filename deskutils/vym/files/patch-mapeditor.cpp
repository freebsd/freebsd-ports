--- mapeditor.cpp.orig	Wed Jul 13 13:36:14 2005
+++ mapeditor.cpp	Sat Aug  6 17:19:14 2005
@@ -58,6 +58,8 @@
 #include "icons/flag-flash.xpm"
 #include "icons/flag-lifebelt.xpm"
 
+#include <unistd.h>
+
 extern TextEditor *textEditor;
 extern int statusbarTime;
 extern Main *mainWindow;

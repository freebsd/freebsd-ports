--- mainwindow.cpp.orig	Mon Jul 11 21:55:32 2005
+++ mainwindow.cpp	Sat Aug  6 17:20:39 2005
@@ -57,6 +57,8 @@
 #include "settings.h"
 #include "options.h"
 
+#include <unistd.h>
+
 extern TextEditor *textEditor;
 extern Main *mainWindow;
 extern int statusbarTime;
@@ -2322,7 +2324,9 @@
 		docpath="./vym.app/Contents/vym.pdf";
 	#else
 		// default path in SUSE LINUX
-		docpath="/usr/share/doc/packages/vym/doc/vym.pdf";
+//		docpath="/usr/share/doc/packages/vym/doc/vym.pdf";
+		// default path in FreeBSD
+		docpath="/usr/local/share/doc/vym/vym.pdf";
 	#endif
 
 	if (!QFile (docpath).exists() )

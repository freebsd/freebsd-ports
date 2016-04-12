--- src/X11/textarea.C.orig	1998-11-17 08:42:50 UTC
+++ src/X11/textarea.C
@@ -32,7 +32,7 @@
 #include <Xm/ScrollBar.h>
 #include <Xm/Text.h>
 
-#include <iostream.h>
+#include <iostream>
 #include "string.h"
 
 #include "motifutil.H"
@@ -91,7 +91,7 @@ void TextArea::add_line(char *line)
   XmTextSetCursorPosition(widget, XmTextGetLastPosition(widget));
   XmTextShowPosition(widget, XmTextGetLastPosition(widget));
   if (length > 9500) {
-    cout << "textarea warning!" << endl;
+    std::cout << "textarea warning!" << std::endl;
     bbuf[0] = '\0';
   }
 }

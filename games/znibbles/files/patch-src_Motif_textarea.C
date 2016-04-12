--- src/Motif/textarea.C.orig	1998-11-17 08:40:25 UTC
+++ src/Motif/textarea.C
@@ -33,7 +33,7 @@
 #include <Xm/ScrollBar.h>
 #include <Xm/Text.h>
 
-#include <iostream.h>
+#include <iostream>
 #include "string.h"
 
 #include "motifutil.H"
@@ -92,7 +92,7 @@ void TextArea::add_line(char *line)
   XmTextSetCursorPosition(widget, XmTextGetLastPosition(widget));
   XmTextShowPosition(widget, XmTextGetLastPosition(widget));
   if (length > 9500) {
-    cout << "textarea warning!" << endl;
+    std::cout << "textarea warning!" << std::endl;
     bbuf[0] = '\0';
   }
 }

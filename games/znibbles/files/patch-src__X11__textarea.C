--- src/X11/textarea.C.orig	Sat Oct 26 01:07:26 2002
+++ src/X11/textarea.C	Sat Oct 26 01:07:28 2002
@@ -32,7 +32,7 @@
 #include <Xm/ScrollBar.h>
 #include <Xm/Text.h>
 
-#include <iostream.h>
+#include <iostream>
 #include "string.h"
 
 #include "motifutil.H"
@@ -91,7 +91,7 @@
   XmTextSetCursorPosition(widget, XmTextGetLastPosition(widget));
   XmTextShowPosition(widget, XmTextGetLastPosition(widget));
   if (length > 9500) {
-    cout << "textarea warning!" << endl;
+    std::cout << "textarea warning!" << std::endl;
     bbuf[0] = '\0';
   }
 }

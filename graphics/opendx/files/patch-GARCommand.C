--- src/uipp/prompter/GARCommand.C.orig	Sat Nov 30 02:48:50 2002
+++ src/uipp/prompter/GARCommand.C	Sat Nov 30 02:46:44 2002
@@ -18,6 +18,7 @@
 #elif defined(HAVE_STRSTREA_H)
 #include <strstrea.h>
 #endif
+#include <strstream>
 
 #include "NoUndoCommand.h"
 #include "GARApplication.h"
@@ -50,9 +51,9 @@
     char	  *fname;
     unsigned long mode;
     int dirty;
-    strstream tmpstr;
+    std::strstream tmpstr;
 #ifdef aviion
-    strstream tmpstr2;
+    std::strstream tmpstr2;
 #endif
 
     switch (this->option)

--- apps/demos/noodle/Interface.c++~	Sat Jun  1 11:22:20 2002
+++ apps/demos/noodle/Interface.c++	Sun Aug  3 14:50:36 2003
@@ -67,6 +67,12 @@
 #include "NoodleTextureGizmo.h"
 #include "NoodleSurfaceGizmo.h"
 
+#ifdef __FreeBSD__
+#define PDF_READER "xpdf"
+#else
+#define PDF_READER "acroread"
+#endif
+ 
 #define SCREEN(w) XScreenNumberOfScreen(XtScreen(w))
 
 extern SoNode *createProfileGraph( Widget, GeneralizedCylinder *);
@@ -406,16 +412,16 @@
     }
 
     char command[100];
-    sprintf(command, "which acroread > /dev/null");
+    sprintf(command, "which " PDF_READER " > /dev/null");
 
     int err = system(command);
     if (err) {
-        system("xmessage 'You must install acroread"
+         system("xmessage 'You must install " PDF_READER
                " for this function to work' > /dev/null");
         return;
     }
 
-    sprintf(command, "acroread " IVPREFIX "/demos/Inventor/noodle.about &");
+    sprintf(command, PDF_READER " " IVPREFIX "/demos/Inventor/noodle.about &");
     system(command);
 }
 

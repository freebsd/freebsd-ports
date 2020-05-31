--- x11menu.c.orig	2013-12-07 16:26:12 UTC
+++ x11menu.c
@@ -29,11 +29,20 @@
 #endif
 
 #if ATHENA_WIDGETS
+#ifdef HAVE_LIB_XAW3D
+#include <X11/Xaw3d/Form.h>
+#include <X11/Xaw3d/SimpleMenu.h>
+#include <X11/Xaw3d/MenuButton.h>
+#include <X11/Xaw3d/SmeLine.h>
+#include <X11/Xaw3d/SmeBSB.h>
+#endif
+#ifdef HAVE_LIB_XAW
 #include <X11/Xaw/Form.h>
 #include <X11/Xaw/SimpleMenu.h>
 #include <X11/Xaw/MenuButton.h>
 #include <X11/Xaw/SmeLine.h>
 #include <X11/Xaw/SmeBSB.h>
+#endif
 #endif
 
 #define Nval(name,value) name, (XtArgVal)(value)

--- x11vile.h.orig	2013-04-14 19:09:08 UTC
+++ x11vile.h
@@ -282,10 +282,18 @@
 
 #if OPT_MENUS
 #if ATHENA_WIDGETS
+#ifdef HAVE_LIB_XAW3D
+#include <X11/Xaw3d/SimpleMenu.h>
+#include <X11/Xaw3d/Box.h>
+#include <X11/Xaw3d/Form.h>
+#include <X11/Xaw3d/Paned.h>
+#endif
+#ifdef HAVE_LIB_XAW
 #include <X11/Xaw/SimpleMenu.h>
 #include <X11/Xaw/Box.h>
 #include <X11/Xaw/Form.h>
 #include <X11/Xaw/Paned.h>
+#endif
 #endif
 #if MOTIF_WIDGETS
 #include <Xm/RowColumn.h>

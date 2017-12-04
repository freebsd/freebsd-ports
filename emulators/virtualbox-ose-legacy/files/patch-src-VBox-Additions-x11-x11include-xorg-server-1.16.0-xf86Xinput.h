--- src/VBox/Additions/x11/x11include/xorg-server-1.16.0/xf86Xinput.h.orig	2014-11-21 10:18:44.000000000 -0500
+++ src/VBox/Additions/x11/x11include/xorg-server-1.16.0/xf86Xinput.h	2014-12-18 16:26:57.000000000 -0500
@@ -51,6 +51,7 @@
 #ifndef _xf86Xinput_h
 #define _xf86Xinput_h
 
+#include "xf86.h"
 #include "xf86str.h"
 #include "inputstr.h"
 #include <X11/extensions/XI.h>
@@ -85,7 +86,7 @@
 
 /* This is to input devices what the ScrnInfoRec is to screens. */
 
-typedef struct _InputInfoRec {
+struct _InputInfoRec {
     struct _InputInfoRec *next;
     char *name;
     char *driver;
@@ -110,7 +111,7 @@
     void *module;
     XF86OptionPtr options;
     InputAttributes *attrs;
-} *InputInfoPtr;
+};
 
 /* xf86Globals.c */
 extern InputInfoPtr xf86InputDevs;

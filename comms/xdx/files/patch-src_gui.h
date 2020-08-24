--- src/gui.h.orig	2006-02-26 19:41:12 UTC
+++ src/gui.h
@@ -49,7 +49,7 @@ typedef struct guitype {
   gchar *high8tagname;
 } guitype;
 
-guitype *gui;
+extern guitype *gui;
 
 guitype *new_gui(void);
 void create_mainwindow (void);

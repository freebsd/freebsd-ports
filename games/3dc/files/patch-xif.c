--- xif.c.orig	2021-05-12 08:22:05 UTC
+++ xif.c
@@ -171,7 +171,7 @@ InitMainWindow( GfxInfo *gfx )
       /* undo, */ resign,
       musterTitle
       /* muster */;
-  int bg;
+  long bg;
 
   form = XtVaCreateManagedWidget("form", formWidgetClass, gfx->mainWindow,
                                  NULL);

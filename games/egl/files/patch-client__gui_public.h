--- client/gui_public.h.orig	Mon Jul 24 21:18:44 2006
+++ client/gui_public.h	Mon Jul 24 21:23:08 2006
@@ -39,7 +39,7 @@
 // gui_events.c
 //
 void		GUI_NamedGlobalEvent (char *name);
-void		GUI_NamedGUIEvent (struct gui_s *gui, char *name);
+void		GUI_NamedGUIEvent ();
 
 //
 // gui_init.c

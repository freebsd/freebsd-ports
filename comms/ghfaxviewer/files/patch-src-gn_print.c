--- src/gn_print.c.orig	Sun May  6 14:15:14 2001
+++ src/gn_print.c	Thu Dec  9 00:24:02 2004
@@ -272,6 +272,7 @@
       print_or_preview (print_dlg, viewer_data, button);
       break;
     case GNOME_PRINT_CANCEL:
+      ;
     }
 
   if (destroy_dlg)

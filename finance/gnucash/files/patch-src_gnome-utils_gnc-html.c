--- src/gnome-utils/gnc-html.c.orig	Tue Feb 20 23:18:48 2007
+++ src/gnome-utils/gnc-html.c	Tue Feb 20 23:18:38 2007
@@ -1325,7 +1325,7 @@
     return;
   }
 
-  gtk_html_print(GTK_HTML(html->html), ps->context);
+  gtk_html_print_page(GTK_HTML(html->html), ps->context);
   gnc_print_session_done(ps);
 }
 

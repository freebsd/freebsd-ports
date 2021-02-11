--- src/filter.c.orig	2005-08-14 11:01:59 UTC
+++ src/filter.c
@@ -144,6 +144,7 @@ static unsigned filter_current_time = 1;
 
 unsigned server_filter_dialog_current_filter = 0;
 
+unsigned current_server_filter;
 
 static  GtkWidget *filter_option_menu;
 static  GtkWidget *filter_retries_spinner;

--- src/filter.c.orig	2014-11-02 00:43:18 UTC
+++ src/filter.c
@@ -142,6 +142,7 @@ static unsigned filter_current_time = 1;
 
 unsigned server_filter_dialog_current_filter = 0;
 
+unsigned current_server_filter;
 
 static  GtkWidget *filter_option_menu;
 static  GtkWidget *filter_retries_spinner;

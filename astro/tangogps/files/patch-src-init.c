--- src/init.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/init.c	Fri Jul 23 22:13:21 2010 -0700
@@ -97,7 +97,7 @@
 	gpointer data = NULL;	
 	
 	GError	*err = NULL;
-	const gchar *nick, *pass, *me_msg, *hrm_bt_addr;
+	const gchar *nick, *pass, *me_msg;
 	GtkWidget *widget;
 	gchar buffer[128];
 	gboolean gconf_fftimer_running;
@@ -116,7 +116,6 @@
 	nick			= gconf_client_get_string(global_gconfclient, GCONF"/nick",&err);
 	pass			= gconf_client_get_string(global_gconfclient, GCONF"/pass",&err);
 	me_msg			= gconf_client_get_string(global_gconfclient, GCONF"/me_msg",&err);
-	hrm_bt_addr		= gconf_client_get_string(global_gconfclient, GCONF"/hrm_bt_addr",&err);
 	
 	global_speed_unit	= gconf_client_get_int(global_gconfclient, GCONF"/speed_unit",&err);
 	global_alt_unit		= gconf_client_get_int(global_gconfclient, GCONF"/alt_unit",&err);
@@ -163,9 +162,6 @@
 	widget  = lookup_widget(window1, "entry29");
 	if(me_msg)
 		gtk_entry_set_text( GTK_ENTRY(widget), me_msg );
-	widget  = lookup_widget(window1, "entry33");
-	if(hrm_bt_addr)
-		gtk_entry_set_text( GTK_ENTRY(widget), hrm_bt_addr );
 
 	
 	widget = lookup_widget(window1, "vscale1");
@@ -182,9 +178,6 @@
 	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), global_auto_download);
 
 	
-	hrm_on = gconf_client_get_bool(global_gconfclient, GCONF"/hrm_on",&err);
-	widget = lookup_widget(window1, "checkbutton18");
-	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), hrm_on);
 	
 	
 	

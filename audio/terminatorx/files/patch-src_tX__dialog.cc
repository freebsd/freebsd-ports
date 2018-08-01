--- src/tX_dialog.cc.orig	2011-01-30 21:01:30 UTC
+++ src/tX_dialog.cc
@@ -252,7 +252,11 @@ GList *get_alsa_device_list() {
 #ifdef USE_OSS
 static GList *oss_devices=NULL;
 
+#ifdef HAVE_SCANDIR_POSIX
 int oss_select_dsp_only(const struct dirent *entry){
+#else
+int oss_select_dsp_only(struct dirent *entry){
+#endif
 	return (strstr(entry->d_name, "dsp")!=0);
 }
 
@@ -562,7 +566,7 @@ void show_about(int nag)
 		gtk_box_pack_start(GTK_BOX(box), iwid, WID_FIX);
 		gtk_box_pack_start(GTK_BOX(box), box2, WID_FIX);
 		
-		label=gtk_label_new(PACKAGE" release "VERSION);
+		label=gtk_label_new(PACKAGE" release " VERSION);
 		gtk_box_pack_start(GTK_BOX(box2), label, WID_DYN);
 		gtk_misc_set_alignment(GTK_MISC(label), 0.1, 0.5);
 		gtk_widget_show(label);
@@ -585,7 +589,7 @@ void show_about(int nag)
 		sep=gtk_hseparator_new();
 		add_about_wid_fix(sep);
 		
-		label=gtk_label_new("This is "PACKAGE" release "VERSION" - Copyright (C) 1999-2011 by Alexander König"
+		label=gtk_label_new("This is " PACKAGE " release " VERSION " - Copyright (C) 1999-2011 by Alexander König"
 		"\nSend comments, patches and scratches to: alex@lisas.de\nterminatorX-homepage: http://www.terminatorX.org");
 
 		gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);

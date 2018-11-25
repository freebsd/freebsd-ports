--- src/tX_dialog.cc.orig	2018-11-07 19:20:20 UTC
+++ src/tX_dialog.cc
@@ -244,13 +244,18 @@ void append_alsa_device_list(GtkComboBox
 	}
 }
 #else
-void append_alsa_device_list(GtkComboBoxText *combo) {
+void append_alsa_device_list(GtkComboBoxText *combo,char *current) {
 }
 #endif
 
 
 #ifdef USE_OSS
+#ifdef HAVE_SCANDIR_POSIX
 int oss_select_dsp_only(const struct dirent *entry){
+#else
+int oss_select_dsp_only(struct dirent *entry){
+#endif
+
 	return (strstr(entry->d_name, "dsp")!=0);
 }
 

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
 

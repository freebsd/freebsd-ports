--- src/tX_dialog.cc.orig	Thu Jun  5 14:08:16 2003
+++ src/tX_dialog.cc	Thu Jun  5 14:08:40 2003
@@ -184,7 +184,7 @@
 #ifdef USE_OSS
 static GList *oss_devices=NULL;
 
-int oss_select_dsp_only(const struct dirent *entry){
+int oss_select_dsp_only(struct dirent *entry){
 	return (strstr(entry->d_name, "dsp")!=0);
 }
 

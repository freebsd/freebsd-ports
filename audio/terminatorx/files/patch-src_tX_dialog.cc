--- src/tX_dialog.cc.orig	2004-02-06 19:28:21.000000000 +0100
+++ src/tX_dialog.cc	2010-08-14 22:00:50.000000000 +0200
@@ -252,7 +252,11 @@
 #ifdef USE_OSS
 static GList *oss_devices=NULL;
 
+#ifdef HAVE_SCANDIR_POSIX
 int oss_select_dsp_only(const struct dirent *entry){
+#else
+int oss_select_dsp_only(struct dirent *entry){
+#endif
 	return (strstr(entry->d_name, "dsp")!=0);
 }
 

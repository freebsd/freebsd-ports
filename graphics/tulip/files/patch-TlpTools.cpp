--- library/tulip/src/TlpTools.cpp.orig	Tue Jul 29 20:59:26 2003
+++ library/tulip/src/TlpTools.cpp	Wed Sep  3 23:46:41 2003
@@ -46,7 +46,7 @@
 }
 //=========================================================
 // accepts only file names ending with ".so"; used by TemplateFactory.cxx for directory filtering
-int __tulip_selectSO(const struct dirent *ent) {
+int __tulip_selectSO(struct dirent *ent) {
   const char *SO = ".so";
   int idx = strlen(ent->d_name) - 3;
   if (idx < 0) return 0;

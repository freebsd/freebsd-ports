--- library/tulip/src/TlpTools.cpp.orig	Wed Apr  2 23:46:09 2003
+++ library/tulip/src/TlpTools.cpp	Mon May 26 14:32:25 2003
@@ -36,7 +36,7 @@
 }
 //=========================================================
 // accepts only file names ending with ".so"
-int __tulip_selectSO(const struct dirent *ent) {
+int __tulip_selectSO(struct dirent *ent) {
   const char *SO = ".so";
   int idx = strlen(ent->d_name) - 3;
   if (idx < 0) return 0;

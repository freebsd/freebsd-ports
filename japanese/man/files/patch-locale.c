--- man/locale.c	2001/08/27 00:01:55
+++ man/locale.c	2001/12/13 03:00:32
@@ -12,7 +12,6 @@
 
 int debug;
 int insecure = 0;
-int findall;
 char *search_lang_path = "ja%en";
 
 typedef struct {
@@ -259,7 +258,7 @@
   return found;
 }
 
-int man_ml(char *name)
+int man_ml(char *name, int findall)
 {
   static man_lang_env_t ***root = NULL;
   man_lang_env_t ***p;

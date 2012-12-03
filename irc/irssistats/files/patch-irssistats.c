--- irssistats.c.orig	2007-11-10 19:40:55.000000000 +0100
+++ irssistats.c	2012-12-03 11:42:45.000000000 +0100
@@ -1561,19 +1561,19 @@
   fclose(fic);
 }
 
-void parse_config(char *configfile)
+void expand(char *path)
 {
-  void expand(char *path)
+  char temp[MAXLINELENGTH];
+  if (*path=='~')
   {
-    char temp[MAXLINELENGTH];
-    if (*path=='~')
-    {
-      snprintf(temp,MAXLINELENGTH-1,"%s%s",getenv("HOME"),path+1);
-      temp[MAXLINELENGTH-1]='\0';
-      strcpy(path,temp);
-    }
+    snprintf(temp,MAXLINELENGTH-1,"%s%s",getenv("HOME"),path+1);
+    temp[MAXLINELENGTH-1]='\0';
+    strcpy(path,temp);
   }
-  
+}
+
+void parse_config(char *configfile)
+{
   FILE *fic;
   char line[MAXLINELENGTH];
   char keyword[MAXLINELENGTH];

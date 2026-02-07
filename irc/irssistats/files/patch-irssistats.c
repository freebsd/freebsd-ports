--- irssistats.c.orig	2007-11-10 18:40:55 UTC
+++ irssistats.c
@@ -1561,19 +1561,19 @@ void gen_xhtml(char *xhtmlfile)
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

--- main.cc.orig	2012-12-22 11:02:06 UTC
+++ main.cc
@@ -96,7 +96,8 @@ int main(int argc, char *argv[]) {
 
   DIR *dir = opendir("locale");
   bindtextdomain("toppler", dir == NULL ? LOCALEDIR : "locale");
-  closedir(dir);
+  if (dir)
+	  closedir(dir);
   textdomain("toppler");
 #endif
 

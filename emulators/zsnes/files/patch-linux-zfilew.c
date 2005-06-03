$FreeBSD$

--- linux/zfilew.c	Fri Jan 14 06:11:19 2005
+++ linux/zfilew.c.new	Thu Jun  2 19:29:43 2005
@@ -474,11 +474,12 @@
 
   if ((homedir = (char *)getenv("HOME")) == 0)
   {
-    homedir = (char *)malloc(ZCFG_DIR_LEN);
-    getcwd(homedir, ZCFG_DIR_LEN);
+    getcwd(zcfgdir, ZCFG_DIR_LEN);
+  }
+  else
+  {
+    strcpy(zcfgdir, homedir);
   }
-  strcpy(zcfgdir, homedir);
-  free(homedir);
   strcat(zcfgdir, ZCFG_DIR);
   tmp = opendir(zcfgdir);
   if (tmp == NULL) 

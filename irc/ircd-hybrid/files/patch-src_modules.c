--- src/modules.c.orig	Wed Jun 22 18:37:48 2005
+++ src/modules.c	Sat Jul 23 14:06:28 2005
@@ -160,11 +160,10 @@
 
   MyFree (base_autoload);
 
-  len = strlen(MODPATH) + 9;
-  /* whatever MODPATH + "autoload/" */
+  len = strlen(AMODPATH);
   
-  base_autoload = MyMalloc(len + 1);
-  snprintf(base_autoload, len, "%sautoload/", MODPATH);
+  base_autoload = MyMalloc(len + 2);
+  snprintf(base_autoload, len, "%s/", AMODPATH);
 }
 
 /* mod_add_path()

--- leif/newpy/NewPY.c	Fri Jul 16 17:38:30 2004
+++ leif/newpy/NewPY.c	Wed Feb 16 20:42:06 2005
@@ -321,7 +321,7 @@
 #ifdef  WIN32
     l->path = "d:\\newpy_obj.jar";  
 #else
-    l->path = "/usr/lib/im/locale/zh_CN/newpy/newpy_obj.jar";  /* path */
+    l->path = (IMDIR "/locale/zh_CN/newpy/newpy_obj.jar");  /* path */
 #endif
 
     l->signature = "";

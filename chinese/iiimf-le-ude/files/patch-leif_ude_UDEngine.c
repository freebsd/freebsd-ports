--- leif/ude/UDEngine.c	Fri Mar 16 00:52:22 2001
+++ leif/ude/UDEngine.c	Wed Feb 16 20:47:14 2005
@@ -302,7 +302,7 @@
     l->name_length = UTFCHARLen(aux_name_panel);
     l->domain = "com.sun.udengine";
     l->scope = "udengine";      
-    l->path = "/usr/lib/im/locale/zh_CN/udengine/udengine_obj.jar";  /* path */
+    l->path = (IMDIR "/locale/zh_CN/udengine/udengine_obj.jar");  /* path */
     l->signature = "";
     l->basepath = NULL;         /* only for CCDEF */
     l->encoding = NULL;         /* only for CCDEF */

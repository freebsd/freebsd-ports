--- leif/ude/UDEngine.c.orig	Fri Mar 16 00:52:22 2001
+++ leif/ude/UDEngine.c	Wed May 18 03:06:05 2005
@@ -94,7 +94,7 @@
 UTFCHAR zhhrn_string[] = {0x7b80, 0x4f53, 0x4e2d, 0x872d, 0x0};
 
 static IMLEName lename = {
-    "udengine", lename_string	/* LE id, HRN */
+    "ude", lename_string	/* LE id, HRN */
 };
 
 static IMLocale locales[] = {
@@ -295,14 +295,14 @@
     objects = (IMObjectDescriptorStruct *) calloc(2, sizeof(IMObjectDescriptorStruct));
     l = objects;
 
-    l->leid = "udengine";       /* engine id */
+    l->leid = "ude";       /* engine id */
     l->type = IM_DOWNLOADINGOBJECT_JARGUI_TYPE; /* object type */
     l->name = (UTFCHAR *) calloc(1, sizeof(UTFCHAR) * (UTFCHARLen(aux_name_panel) + 1));
     UTFCHARCpy(l->name, aux_name_panel);
     l->name_length = UTFCHARLen(aux_name_panel);
     l->domain = "com.sun.udengine";
-    l->scope = "udengine";      
-    l->path = "/usr/lib/im/locale/zh_CN/udengine/udengine_obj.jar";  /* path */
+    l->scope = "ude";      
+    l->path = "%%PREFIX%%" "/lib/iiim/le/ude/ude.so";  /* path */
     l->signature = "";
     l->basepath = NULL;         /* only for CCDEF */
     l->encoding = NULL;         /* only for CCDEF */

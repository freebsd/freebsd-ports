--- src/agl_main.c.orig	2007-12-12 23:45:13.000000000 +0100
+++ src/agl_main.c	2007-12-12 23:47:00.000000000 +0100
@@ -65,7 +65,8 @@
 	if (agl_initparachute() < 0)
 		return -1;
 
-	*phandle = (agl_handle) handle = (agl_container *) agl_malloc(sizeof(agl_container));
+	handle = agl_malloc(sizeof(agl_container));
+	*phandle = (agl_container *)handle;
 	if (*phandle == NULL)
 	{
 		agl_memerr();

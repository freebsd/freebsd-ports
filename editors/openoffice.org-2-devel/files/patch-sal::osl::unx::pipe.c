--- ../sal/osl/unx/pipe.c.orig	Tue May 29 07:38:32 2001
+++ ../sal/osl/unx/pipe.c
@@ -264,7 +264,11 @@
     
 	addr.sun_family = AF_UNIX;
 	strcpy(addr.sun_path, name);
+#if defined(FREEBSD)
+        len = SUN_LEN(&addr);
+#else
 	len = sizeof(addr.sun_family) + strlen(addr.sun_path);
+#endif
 
 	if ( Options & osl_Pipe_CREATE )
 	{			

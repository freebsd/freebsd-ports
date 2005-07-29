--- sal/osl/unx/pipe.c.orig	Mon Feb 18 13:48:55 2002
+++ sal/osl/unx/pipe.c	Wed Apr  3 00:59:15 2002
@@ -264,7 +264,11 @@
     
 	addr.sun_family = AF_UNIX;
 	strncpy(addr.sun_path, name, sizeof(addr.sun_path));
+#if defined(FREEBSD)
+	 len = SUN_LEN(&addr);
+#else
 	len = sizeof(addr);
+#endif
 
 	if ( Options & osl_Pipe_CREATE )
 	{			

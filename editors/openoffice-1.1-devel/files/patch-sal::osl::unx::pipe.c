--- ../sal/osl/unx/pipe.c.orig	Thu Jul 11 16:01:39 2002
+++ ../sal/osl/unx/pipe.c	Fri Oct 18 19:56:38 2002
@@ -264,7 +264,11 @@
     
 	addr.sun_family = AF_UNIX;
 	strncpy(addr.sun_path, name, sizeof(addr.sun_path));
+#if defined(FREEBSD)
+	len = SUN_LEN(&addr);
+#else
 	len = sizeof(addr);
+#endif
 
 	if ( Options & osl_Pipe_CREATE )
 	{			

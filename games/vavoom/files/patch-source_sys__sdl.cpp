--- source/sys_sdl.cpp.orig	2017-06-04 12:56:34.438609000 +0200
+++ source/sys_sdl.cpp	2017-06-04 13:11:31.567597000 +0200
@@ -530,7 +530,7 @@
 	catch (VavoomError &e)
 	{
 		Host_Shutdown();
-		stack_trace();
+//		stack_trace();
 
 		printf("\n%s\n", e.message);
 		dprintf("\n\nERROR: %s\n", e.message);

--- source/sys_sdl.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/sys_sdl.cpp
@@ -530,7 +530,7 @@ int main(int argc,char** argv)
 	catch (VavoomError &e)
 	{
 		Host_Shutdown();
-		stack_trace();
+//		stack_trace();
 
 		printf("\n%s\n", e.message);
 		dprintf("\n\nERROR: %s\n", e.message);

--- ./client/cl_main.c.orig	Wed May 17 22:21:33 2006
+++ ./client/cl_main.c	Wed May 17 22:27:30 2006
@@ -3629,7 +3629,7 @@
 //jec - updates all input events
 
 void CL_RefreshCmd (void);
-#if (defined JOYSTICK) || (defined LINUX)
+#if (defined JOYSTICK) || (defined __unix__)
 extern void IN_Commands (void);
 #endif
 void CL_RefreshInputs (void)
@@ -3637,7 +3637,7 @@
 	// process new key events
 	Sys_SendKeyEvents ();
 
-#if (defined JOYSTICK) || (defined LINUX)
+#if (defined JOYSTICK) || (defined __unix__)
 	// process mice & joystick events
 	IN_Commands ();
 #endif
@@ -4032,7 +4032,7 @@
 	Cbuf_Execute ();
 
 	Con_Init ();	
-#if defined __linux__ || defined __sgi || defined __FreeBSD__
+#if defined __unix__ || defined __sgi
 	S_Init (true);	
 
 	VID_Init ();

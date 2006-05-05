--- ./cl_main.c.orig	Thu May 19 17:56:13 2005
+++ ./cl_main.c	Sun Feb 26 11:23:56 2006
@@ -3657,7 +3657,7 @@
 	Cbuf_Execute ();
 
 	Con_Init ();	
-#if defined __linux__ || defined __sgi
+#if defined __linux__ || defined __sgi || defined __FreeBSD__
 	S_Init (true);	
 
 	VID_Init ();

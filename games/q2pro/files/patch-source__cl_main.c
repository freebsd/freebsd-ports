--- ./source/cl_main.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/cl_main.c	Mon Dec 25 17:07:03 2006
@@ -2637,7 +2637,7 @@
 
     // all archived variables will now be loaded
 
-#if defined __linux__ || defined __sgi
+#if defined __unix__ || defined __sgi
     S_Init();
     CL_InitRefresh();
 #else

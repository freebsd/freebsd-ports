--- ./qcommon/common.c.orig	Wed May 17 22:21:33 2006
+++ ./qcommon/common.c	Wed May 17 22:29:35 2006
@@ -1986,7 +1986,7 @@
 
 #if defined _WIN32
 	z->allocationLocation = _ReturnAddress ();
-#elif defined LINUX
+#elif defined __unix__
 	z->allocationLocation = __builtin_return_address (0);
 #else
 	//FIXME: other OSes/CCs
@@ -2046,7 +2046,7 @@
 
 #if defined _WIN32
 	retAddr = _ReturnAddress ();
-#elif defined LINUX
+#elif defined __unix__
 	retAddr = __builtin_return_address (0);
 #else
 	//FIXME: other OSes/CCs

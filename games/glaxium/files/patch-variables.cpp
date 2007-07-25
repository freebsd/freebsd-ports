--- ./variables.cpp.orig	Fri Oct 18 01:53:00 2002
+++ ./variables.cpp	Sat Jul 21 17:51:10 2007
@@ -453,6 +453,7 @@
 	static char strReturn[1024];
 	strcpy(strReturn, getenv("HOME"));
 	strcat(strReturn, "/.glaxiumrc");
+	return strReturn;
 #endif
 }
 

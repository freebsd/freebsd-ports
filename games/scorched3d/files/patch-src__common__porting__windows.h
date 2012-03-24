--- src/common/porting/windows.h.orig	2008-03-03 03:47:36.000000000 +0900
+++ src/common/porting/windows.h	2012-03-07 18:29:31.000000000 +0900
@@ -9,6 +9,7 @@
 #include <ctype.h>
 #include <common/Defines.h>
 
+#if defined(_WIN32)
 typedef char * 		LPSTR;
 typedef const char *	LPCTSTR;
 typedef unsigned int 	DWORD;
@@ -27,6 +28,7 @@
 typedef int 	LRESULT;
 typedef void *	HDC;
 typedef void *  HGLRC;
+#endif
 
 #define _strnicmp(a,b,c)	strncasecmp(a,b,c)
 #define stricmp(a,b)		strcasecmp(a,b)

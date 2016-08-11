--- src/common/porting/windows.h.orig	2016-06-20 14:16:37 UTC
+++ src/common/porting/windows.h
@@ -9,6 +9,7 @@
 #include <ctype.h>
 #include <common/Defines.h>
 
+#if defined(_WIN32)
 typedef char * 		LPSTR;
 typedef const char *	LPCTSTR;
 typedef unsigned int 	DWORD;
@@ -27,6 +28,7 @@ typedef int 	LPARAM;
 typedef int 	LRESULT;
 typedef void *	HDC;
 typedef void *  HGLRC;
+#endif
 
 #define _strnicmp(a,b,c)	strncasecmp(a,b,c)
 #define stricmp(a,b)		strcasecmp(a,b)

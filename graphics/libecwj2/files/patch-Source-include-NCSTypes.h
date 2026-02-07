--- Source/include/NCSTypes.h.orig	2009-04-05 22:21:15.000000000 +0400
+++ Source/include/NCSTypes.h	2009-04-05 21:14:07.000000000 +0400
@@ -184,7 +184,7 @@
 typedef longlong_t 	INT64;		/* 64 bit signed integer		*/
 typedef u_longlong_t 	UINT64;		/* 64 bit unsigned integer		*/
 
-#elif defined(LINUX)
+#elif defined(LINUX) || defined FREEBSD
 
 #define DWORD UINT32
 typedef struct tagRECT {

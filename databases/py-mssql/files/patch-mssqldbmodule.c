--- mssqldbmodule.c.orig	2014-09-22 16:55:37.023477894 +0200
+++ mssqldbmodule.c	2014-09-22 16:55:28.247483584 +0200
@@ -85,7 +85,6 @@
 #define SQLTEXT        SYBTEXT
 
 #define BYTE           unsigned char
-typedef unsigned char *LPBYTE;
 #endif
 
 #define TYPE_STRING      1

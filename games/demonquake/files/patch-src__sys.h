--- ./src/sys.h.orig	Thu Nov  3 16:20:30 2005
+++ ./src/sys.h	Tue May 16 14:33:39 2006
@@ -65,7 +65,7 @@
 
 char *Sys_GetClipboardData (void);
 //QuDos-
-#ifdef __linux__
+#ifdef __unix__
 //linux *pak loading Tenebrae
 typedef struct
 {

--- ./src/sys.h.orig	Mon Oct 31 20:47:55 2005
+++ ./src/sys.h	Tue May 16 14:59:52 2006
@@ -65,7 +65,7 @@
 
 char *Sys_GetClipboardData (void);
 
-#ifdef __linux__ //QuDos *.pak linux loading from tenebrae
+#ifdef __unix__ //QuDos *.pak linux loading from tenebrae
 typedef struct
 {
   char entry[MAX_OSPATH];         // current entry in the list

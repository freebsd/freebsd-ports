--- ./common.h.orig	Sat Jun 10 12:08:13 2006
+++ ./common.h	Sat Jun 10 12:08:13 2006
@@ -169,6 +169,10 @@
 
 extern	char	com_gamedir[MAX_OSPATH];
 
+#ifdef  USERPREF_DIR
+extern char	com_prefdir[MAX_OSPATH];
+#endif
+
 void COM_WriteFile (char *filename, void *data, int len);
 int COM_OpenFile (const char *filename, int *hndl);
 int COM_FOpenFile (const char *filename, FILE **file);

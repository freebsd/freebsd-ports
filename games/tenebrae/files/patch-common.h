--- common.h.orig	Sun Mar 14 13:19:04 2004
+++ common.h	Sun Mar 14 13:19:50 2004
@@ -169,6 +169,10 @@
 
 extern	char	com_gamedir[MAX_OSPATH];
 
+#ifdef  USERPREF_DIR
+extern char	com_prefdir[MAX_OSPATH];
+#endif
+
 void COM_WriteFile (char *filename, void *data, int len);
 int COM_OpenFile (const char *filename, int *hndl);
 int COM_FOpenFile (const char *filename, FILE **file);

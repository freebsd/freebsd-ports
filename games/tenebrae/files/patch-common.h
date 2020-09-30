--- common.h.orig	2020-09-30 11:25:10 UTC
+++ common.h
@@ -169,6 +169,10 @@ struct cache_user_s;
 
 extern	char	com_gamedir[MAX_OSPATH];
 
+#ifdef  USERPREF_DIR
+extern char	com_prefdir[MAX_OSPATH];
+#endif
+
 void COM_WriteFile (char *filename, void *data, int len);
 int COM_OpenFile (const char *filename, int *hndl);
 int COM_FOpenFile (const char *filename, FILE **file);

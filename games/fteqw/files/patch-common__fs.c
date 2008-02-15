--- common/fs.c.orig	2008-02-15 14:55:07.000000000 -0300
+++ common/fs.c	2008-02-15 14:55:19.000000000 -0300
@@ -2120,8 +2120,10 @@
 	}
 
 	//if we're meant to be writing, best write to it.
-	if (strchr(mode , 'w') || strchr(mode , 'a'))
+	if (strchr(mode , 'w') || strchr(mode , 'a')) {
+		COM_CreatePath(fullname);
 		return VFSOS_Open(fullname, mode);
+	}
 	return NULL;
 }
 
@@ -3144,9 +3146,6 @@
 		*com_homedir = '\0';
 #endif
 
-	if (!COM_CheckParm("-usehome"))
-		*com_homedir = '\0';
-
 	if (COM_CheckParm("-nohome"))
 		*com_homedir = '\0';
 

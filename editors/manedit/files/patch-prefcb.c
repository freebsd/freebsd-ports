
$FreeBSD$

--- prefcb.c	2001/02/09 13:12:30	1.1
+++ prefcb.c	2001/02/09 13:12:46
@@ -698,7 +698,7 @@
 
 	PDialogDeleteAllPrompts();
 	PDialogAddPromptWithBrowse(
-	    NULL, "Path:", "/usr/man",
+	    NULL, "Path:", "/usr/share/man",
 	    (void *)pref,
 	    PrefManPageDirPromptBrowseCB
 	);

--- src/plist.h.orig	2005-11-30 05:52:39 UTC
+++ src/plist.h
@@ -35,7 +35,7 @@ typedef struct
 
 /*-------------------------------- globals ----------------------------------*/
 
-int	plistexist_value, plistexist_dvalue, plistexist_cdvalue,
+EXTERN int	plistexist_value, plistexist_dvalue, plistexist_cdvalue,
 	plistexist_flag, plistexist_wflag, plistexist_dthresh, plistexist_var,
 	plistoff_value, plistoff_dvalue, plistoff_cdvalue,
 	plistoff_flag[MAXFLAG], plistoff_wflag, plistoff_dthresh, plistoff_var,

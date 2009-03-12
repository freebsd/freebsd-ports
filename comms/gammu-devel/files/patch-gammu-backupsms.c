--- gammu/backupsms.c.orig	2009-03-12 10:06:22.000000000 +0300
+++ gammu/backupsms.c	2009-03-12 10:06:38.000000000 +0300
@@ -23,7 +23,7 @@
 	GSM_SMSFolders		folders;
 	bool			BackupFromFolder[GSM_MAX_SMS_FOLDERS];
 	bool			start = true;
-	bool			DeleteAfter, askdelete = true;
+	bool			DeleteAfter = false, askdelete = true;
 	int			j, smsnum = 0;
 
 	if (argc == 4) {

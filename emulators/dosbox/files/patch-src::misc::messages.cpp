--- src/misc/messages.cpp.orig	Tue Jul 30 15:13:10 2002
+++ src/misc/messages.cpp	Tue Sep  3 09:29:12 2002
@@ -101,7 +101,7 @@
 	/* Load the messages from "dosbox.lang file" */
 	first_message=0;
 	char filein[CROSS_LEN];
-	strcpy(filein,dosbox_basedir);
-	strcat(filein,"dosbox.lang");
+	strcpy(filein,"@@PREFIX@@/share/dosbox/dosbox.lang");
+/*	strcat(filein,"dosbox.lang"); */
 	LoadMessageFile(filein);
 }

--- ../setup2/mow/source/loader/loader.c.orig2	Thu Jun  6 11:23:17 2002
+++ ../setup2/mow/source/loader/loader.c	Thu Jun  6 11:24:14 2002
@@ -902,6 +902,7 @@
 
 void KillSetupDir()
 {
+#if 0
     DIR* pDir = opendir( strTmpPath );
     struct dirent* pFile;
 
@@ -915,6 +916,10 @@
 
     chdir( strInitPath );
     rmdir( strTmpPath );
+#else
+	fprintf(stderr, "\nLeaving behind temporary directory: %s\n",
+	strTmpPath);
+#endif
 }
 
 void makeSymLink( char* s )

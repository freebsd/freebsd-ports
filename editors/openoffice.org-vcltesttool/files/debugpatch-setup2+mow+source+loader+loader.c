--- ../setup2/mow/source/loader/loader.c.orig2	Thu Jun  6 11:23:17 2002
+++ ../setup2/mow/source/loader/loader.c	Thu Jun  6 11:24:14 2002
@@ -1055,6 +1055,7 @@
 
 void KillSetupDir()
 {
+#if 0
     DIR* pDir;
     struct dirent* pFile;
 
@@ -1074,6 +1075,10 @@
     closedir( pDir );
     chdir( strInitPath );
     rmdir( strTmpPath );
+#else
+	fprintf(stderr, "\nLeaving behind temporary directory: %s\n",
+	strTmpPath);
+#endif
 }
 
 void makeSymLink( char* s )

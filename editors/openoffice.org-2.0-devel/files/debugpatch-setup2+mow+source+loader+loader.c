--- ../setup2/mow/source/loader/loader.c.orig	Mon Jun  2 08:25:13 2003
+++ ../setup2/mow/source/loader/loader.c	Tue Jun  3 07:58:22 2003
@@ -1069,6 +1069,7 @@
 
 void KillSetupDir()
 {
+#if 0
     DIR* pDir;
     struct dirent* pFile;
 
@@ -1088,6 +1089,10 @@
     closedir( pDir );
     chdir( strInitPath );
     rmdir( strTmpPath );
+#else
+	fprintf(stderr, "\nLeaving behind temporary directory: %s\n",
+	strTmpPath);
+#endif
 }
 
 void makeSymLink( char* s )

--- init.cpp.orig	2008-02-19 19:27:46.000000000 +0100
+++ init.cpp	2008-02-19 19:29:23.000000000 +0100
@@ -36,8 +36,8 @@
 pthread_mutex_t ServerLock;
 
 
-void LoadSpec(char *dirname, char *filename);
-int copyfile(char *ConfDirName, char *FileName);
+void LoadSpec(char *dirname, const char *filename);
+int copyfile(char *ConfDirName, const char *FileName);
 
 
 void DoInitializations()
@@ -115,7 +115,7 @@
 }
 
 
-void LoadSpec(char *dirname, char *filename)
+void LoadSpec(char *dirname, const char *filename)
 {
   FILE *fileptr;
   char entry[80];
@@ -277,7 +277,7 @@
 }
 
 
-int copyfile(char *ConfDirName, char *FileName)
+int copyfile(char *ConfDirName, const char *FileName)
 {
   FILE *oldfd, *newfd;
   char oldFileName[80], newFileName[80];

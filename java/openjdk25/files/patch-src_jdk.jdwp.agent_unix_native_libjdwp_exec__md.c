--- src/jdk.jdwp.agent/unix/native/libjdwp/exec_md.c.orig	2025-06-27 12:18:08 UTC
+++ src/jdk.jdwp.agent/unix/native/libjdwp/exec_md.c
@@ -70,6 +70,9 @@ closeDescriptors(void)
 int
 closeDescriptors(void)
 {
+#if defined(__FreeBSD__)
+    closefrom(STDERR_FILENO + 1);
+#else
     DIR *dp;
     struct dirent *dirp;
     /* leave out standard input/output/error descriptors */
@@ -114,6 +117,7 @@ closeDescriptors(void)
 
     (void)closedir(dp);
 
+#endif
     return 1; // success
 }
 

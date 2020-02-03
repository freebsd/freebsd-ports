--- setup.c.orig	2020-02-01 17:05:20 UTC
+++ setup.c
@@ -43,6 +43,7 @@
   #import <sys/param.h>
 #elif defined(__FreeBSD__)
   #include <sys/param.h>
+  #include <unistd.h>
 #elif defined(__MINT__)
     #include <mint/osbind.h>
     #include <mint/sysbind.h>
@@ -114,12 +115,17 @@ char * Get_program_directory(const char * argv0)
   getcwd(program_dir, MAX_PATH_CHARACTERS);
   strcat(program_dir, "/");
   // Linux: argv[0] unreliable
-  #elif defined(__linux__)
+  #elif defined(__linux__) || defined(__FreeBSD__)
+  #if defined(__linux__)
+  #define SELF_PATH "/proc/self/exe"
+  #elif defined(__FreeBSD__)
+  #define SELF_PATH "/proc/curproc/file"
+  #endif
   if (argv0[0]!='/')
   {
     ssize_t path_len;
     char path[PATH_MAX];
-    path_len = readlink("/proc/self/exe", path, sizeof(path));
+    path_len = readlink(SELF_PATH, path, sizeof(path));
     if (path_len >= 0)
     {
       path[path_len] = '\0';  // add null terminating char
@@ -132,7 +138,7 @@ char * Get_program_directory(const char * argv0)
       size_t len;
 
       program_dir = NULL;
-      GFX2_Log(GFX2_WARNING, "readlink(%s) failed : %s\n", "/proc/self/exe", strerror(errno));
+      GFX2_Log(GFX2_WARNING, "readlink(%s) failed : %s\n", SELF_PATH, strerror(errno));
       current_dir = Get_current_directory(NULL, NULL, 0);
       if (current_dir != NULL)
       {
@@ -157,6 +163,11 @@ char * Get_program_directory(const char * argv0)
   #else
   program_dir = Extract_path(NULL, argv0);
   #endif
+  if (program_dir == NULL)
+  {
+    GFX2_Log(GFX2_WARNING, "Failed to detect program directory, using current directory\n");
+    program_dir = strdup("." PATH_SEPARATOR);
+  }
   return program_dir;
 }
 

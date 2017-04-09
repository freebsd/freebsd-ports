--- src/entry.cc.orig	2015-04-15 08:00:23 UTC
+++ src/entry.cc
@@ -182,7 +182,7 @@ static void SetFileFromOption(char *equa
     if (Globals::OutFile == NULL) {
       fprintf(stderr, "Could not open file %s: ", file_name);
       perror(NULL);
-      exit(1);
+      _exit(1);
     }
   }
 
@@ -207,7 +207,7 @@ static void ParseArguments(char *options
     char path[PATH_MAX];
     if (getcwd(path, PATH_MAX) == NULL) {
       fprintf(stderr, "cwd too long?\n");
-      exit(0);
+      _exit(0);
     }
     size_t pathlen = strlen(path);
     strncat(path, "/", PATH_MAX - (pathlen++));

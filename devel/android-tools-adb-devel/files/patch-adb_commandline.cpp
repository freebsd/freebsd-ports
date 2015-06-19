--- adb/commandline.cpp.orig	2015-06-17 22:20:38 UTC
+++ adb/commandline.cpp
@@ -637,7 +637,7 @@ static int ppp(int argc, const char** ar
 
         // copy args
         ppp_args = (const char **) alloca(sizeof(char *) * argc + 1);
-        ppp_args[0] = "pppd";
+        ppp_args[0] = "ppp";
         for (i = 2 ; i < argc ; i++) {
             //argv[2] and beyond become ppp_args[1] and beyond
             ppp_args[i - 1] = argv[i];
@@ -651,10 +651,10 @@ static int ppp(int argc, const char** ar
         adb_close(STDERR_FILENO);
         adb_close(fd);
 
-        err = execvp("pppd", (char * const *)ppp_args);
+        err = execvp("ppp", (char * const *)ppp_args);
 
         if (err < 0) {
-            perror("execing pppd");
+            perror("execing ppp");
         }
         exit(-1);
     } else {

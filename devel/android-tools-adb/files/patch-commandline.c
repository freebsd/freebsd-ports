--- commandline.c.orig	2014-09-27 22:55:45.000000000 +0800
+++ commandline.c	2014-09-27 22:58:14.000000000 +0800
@@ -591,7 +591,7 @@
 
         // copy args
         ppp_args = (const char **) alloca(sizeof(char *) * argc + 1);
-        ppp_args[0] = "pppd";
+        ppp_args[0] = "ppp";
         for (i = 2 ; i < argc ; i++) {
             //argv[2] and beyond become ppp_args[1] and beyond
             ppp_args[i - 1] = argv[i];
@@ -605,10 +605,10 @@
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

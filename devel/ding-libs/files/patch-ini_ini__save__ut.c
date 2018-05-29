--- ini/ini_save_ut.c.orig	2018-05-29 07:31:23 UTC
+++ ini/ini_save_ut.c
@@ -180,7 +180,7 @@ static int basic_test(void)
                  (srcdir == NULL) ? "." : srcdir,
                  cmp_files[i]);
 
-        snprintf(command, PATH_MAX * 3, "cmp -l -b %s %s", resname, cmpname);
+        snprintf(command, PATH_MAX * 3, "cmp -l %s %s", resname, cmpname);
         error = system(command);
         if ((error) || (WEXITSTATUS(error))) {
             printf("Failed to compare files %d %d.\n",  error,

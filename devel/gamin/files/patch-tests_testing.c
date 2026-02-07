--- tests/testing.c.orig	Thu Oct 27 10:51:03 2005
+++ tests/testing.c	Tue Feb 14 17:46:01 2006
@@ -376,11 +376,11 @@ processCommand(char *line, int no)
         }
         printf("chmod %s to %s\n", arg, arg2);
     } else if (!strcmp(command, "chown")) {
+	struct stat sb;
         if (args != 3) {
             fprintf(stderr, "chown line %d: lacks path and owner\n", no);
             return (-1);
         }
-		struct stat sb;
 		if (!lstat (arg, &sb)) {
 			ret = (S_ISLNK (sb.st_mode)) ?
 				lchown(arg, strtol(arg2, NULL, 10), -1) :
@@ -486,9 +486,9 @@ processCommand(char *line, int no)
             return (-1);
         }
         /*
-         * wait at most 3 secs before declaring failure
+         * wait at most 7 secs before declaring failure
          */
-        while ((delay < 30) && (testState.nb_events < nb_events + count)) {
+        while ((delay < 70) && (testState.nb_events < nb_events + count)) {
             debugLoop(100);
 
 /*	    printf("+"); fflush(stdout); */

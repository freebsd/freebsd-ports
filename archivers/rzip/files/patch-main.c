--- main.c.orig	Thu Feb 12 01:01:08 2004
+++ main.c	Fri Apr  9 18:28:33 2004
@@ -137,10 +137,8 @@
 			   strlen(control->infile) - strlen(control->suffix)) != 0) {
 			fatal("%s: unknown suffix\n", control->infile);
 		}
-		
-		control->outfile = strndup(control->infile, 
-					   strlen(control->infile) - 
-					   strlen(control->suffix));
+		control->outfile = malloc(strlen(control->infile) - strlen(control->suffix) + 1);
+		strncpy(control->outfile, control->infile, strlen(control->infile) - strlen(control->suffix));
 	}
 
 	fd_in = open(control->infile,O_RDONLY);

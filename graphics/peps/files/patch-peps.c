--- peps.c-	Thu Jul  5 05:29:56 2001
+++ peps.c	Mon Jun 16 15:13:13 2003
@@ -62,6 +62,7 @@
  */
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/wait.h>
 
 char gsargs[] = "gs "
 	"-q "
@@ -181,7 +182,8 @@
 }
 
 int main(int argc, char *argv[]) {
-	register int i;
+	register int i; 
+	int status, error;
 	register char *charptr;
 	FILE *gs, *eps;
 
@@ -420,8 +422,14 @@
 		input, input
 		);
 
-	pclose(gs);
+	status = pclose(gs);
 
-	return 0;
+	error = !WIFEXITED(status) || WEXITSTATUS(status);
+
+	if (error && output)
+		(void) remove(output);
+			
+	exit(error);
+		
 }
 

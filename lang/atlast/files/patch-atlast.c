--- atlast.c.orig	Fri May 10 23:18:47 2002
+++ atlast.c	Fri May 10 23:36:28 2002
@@ -3243,14 +3243,17 @@
 	{   static struct {
 		char *sfn;
 		FILE *sfd;
-	    } stdfiles[] = {
-                {"STDIN", stdin},
-                {"STDOUT", stdout},
-                {"STDERR", stderr}
+	    } stdfiles[] = {
+                {"STDIN", NULL},
+                {"STDOUT", NULL},
+                {"STDERR", NULL}
 	    };
 	    int i;
 	    dictword *dw;
 
+	    stdfiles[0].sfd = stdin;
+	    stdfiles[1].sfd = stdout;
+	    stdfiles[2].sfd = stderr;
 	    for (i = 0; i < ELEMENTS(stdfiles); i++) {
 		if ((dw = atl_vardef(stdfiles[i].sfn,
 			2 * sizeof(stackitem))) != NULL) {

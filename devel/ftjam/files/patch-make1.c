--- make1.c.orig	2014-08-07 15:28:04.000000000 +0200
+++ make1.c	2014-08-07 15:28:43.000000000 +0200
@@ -62,6 +62,10 @@
 # include "command.h"
 # include "execcmd.h"
 
+# if defined ( OS_FREEBSD )
+# include <unistd.h> // unlink(2)
+# endif
+
 static void make1a( TARGET *t, TARGET *parent );
 static void make1b( TARGET *t );
 static void make1c( TARGET *t );
@@ -426,7 +430,6 @@
 	    SETTINGS *boundvars;
 	    LIST    *nt, *ns;
 	    ACTIONS *a1;
-	    CMD	    *cmd;
 	    int	    start, chunk, length, maxline;
 
 	    /* Only do rules with commands to execute. */

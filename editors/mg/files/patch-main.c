--- main.c.orig	2023-10-20 07:56:18 UTC
+++ main.c
@@ -16,7 +16,7 @@
 #include <string.h>
 #include <termios.h>
 #include <unistd.h>
-#include <util.h>
+#include <libutil.h>
 
 #include "def.h"
 #include "kbd.h"
@@ -43,6 +43,10 @@ struct mgwin	*wheadp;			/* MGWIN listhead	*/
 struct vhead	 varhead;			/* Variable list head	*/
 char		 pat[NPAT];			/* pattern		*/
 
+#ifndef __dead
+#define __dead __attribute__ ((__noreturn__))
+#endif
+
 static void	 edinit(struct buffer *);
 static void	 pty_init(void);
 static __dead void usage(void);
@@ -71,10 +75,6 @@ main(int argc, char **argv)
 	int	  	 nobackups = 0;
 	struct buffer	*bp = NULL;
 
-	if (pledge("stdio rpath wpath cpath fattr chown getpw tty proc exec",
-	    NULL) == -1)
-		err(1, "pledge");
-
 	while ((o = getopt(argc, argv, "nRb:f:u:")) != -1)
 		switch (o) {
 		case 'b':
@@ -167,9 +167,11 @@ main(int argc, char **argv)
 		ffclose(ffp, NULL);
 	}
 
-	if (batch)
+	if (batch) {
+		vttidy();
 		return (0);
-
+	}
+	
 	/*
 	 * Now ensure any default buffer modes from the startup file are
 	 * given to any files opened when parsing the startup file.

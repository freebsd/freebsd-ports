--- main.c.orig	2023-10-24 10:26:02 UTC
+++ main.c
@@ -16,7 +16,7 @@
 #include <string.h>
 #include <termios.h>
 #include <unistd.h>
-#include <util.h>
+#include <libutil.h>
 
 #include "def.h"
 #include "kbd.h"
@@ -43,6 +43,10 @@ char		 pat[NPAT];			/* pattern		*/
 struct vhead	 varhead;			/* Variable list head	*/
 char		 pat[NPAT];			/* pattern		*/
 
+#ifndef __dead
+#define __dead __attribute__ ((__noreturn__))
+#endif
+
 static void	 edinit(struct buffer *);
 static void	 pty_init(void);
 static __dead void usage(void);
@@ -70,10 +74,6 @@ main(int argc, char **argv)
 	int	 	 o, i, nfiles;
 	int	  	 nobackups = 0;
 	struct buffer	*bp = NULL;
-
-	if (pledge("stdio rpath wpath cpath fattr chown getpw tty proc exec",
-	    NULL) == -1)
-		err(1, "pledge");
 
 	while ((o = getopt(argc, argv, "nRb:f:u:")) != -1)
 		switch (o) {

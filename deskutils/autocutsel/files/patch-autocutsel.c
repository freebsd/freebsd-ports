--- autocutsel.c.orig	Fri Feb 18 23:29:05 2005
+++ autocutsel.c	Fri Feb 18 23:29:17 2005
@@ -503,7 +503,7 @@
 
   if (options.fork) {
     if (getppid () != 1) {
-      setpgrp ();
+      setpgrp (0,0);
       switch (fork ()) {
       case -1:
       fprintf (stderr, "could not fork, exiting\n");

--- source/server.c.orig	Tue Mar 25 06:09:13 2003
+++ source/server.c	Fri Apr 25 04:09:10 2003
@@ -1029,12 +1029,6 @@
      I moved this code from below for smoother source tweak -kre */
   command = av[3] + 1;
   
-  /* Obviously, this code down strips '%'. But what if some valid string
-     contains regular '%' and it should _not_ be stripped, ie. passwd
-     string? So, I'll add search for IDENTIFY string. -kre */
-  if (ircncmp(command, "IDENTIFY", 8))
-    stripformatsymbols(av[3]);
-
   if (RestrictedAccess)
   {
     /*

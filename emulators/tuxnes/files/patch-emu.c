--- emu.c.orig	Thu Apr 12 06:45:47 2001
+++ emu.c	Wed Aug  4 18:34:38 2004
@@ -890,7 +890,7 @@
       len = strlen(palfile) + 1;
       if (! (buffer = malloc(len)))
 	{
-	  perror (__FUNCTION__ ": malloc");
+	  perror ("loadpal 892: malloc");
 	  return;
 	}
       memcpy (buffer, palfile, len);
@@ -912,7 +912,7 @@
       len = strlen(filename) + 1;
       if (! (buffer = malloc(len)))
 	{
-	  perror (__FUNCTION__ ": malloc");
+	  perror ("loadpal 914: malloc");
 	  return;
 	}
       memcpy (buffer, filename, len);
@@ -924,7 +924,7 @@
 	return;
       if (!(palfile = malloc ((len = strlen (filename)) + 11)))
         {
-          perror (__FUNCTION__ ": malloc");
+          perror ("loadpal 933: malloc");
           return;
         }
       strcpy (palfile, filename);
@@ -1602,7 +1602,7 @@
 
     if (! (basefilename = malloc(baseend - basestart + 1)))
       {
-        perror (__FUNCTION__ ": malloc");
+        perror ("main: malloc");
         exit (1);
       }
 

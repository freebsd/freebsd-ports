--- src/main.c.orig	2009-08-24 03:03:26.000000000 +0900
+++ src/main.c	2009-09-28 17:25:00.000000000 +0900
@@ -549,7 +549,7 @@
 	  g_print("opt %c has %s\n", opts, argv[optind]);
       if (opts == 'h')
         {
-          g_print (helptext);
+          g_print ("%s", helptext);
           exit (0);
         }
       else if (opts == 's')
@@ -573,13 +573,13 @@
         {
           g_print (_("\nGNU Denemo version "));
           g_print (VERSION ".\n\n");
-          g_print (copytext);
+          g_print ("%s", copytext);
           exit (0);
         }
     }
 
   g_print (_("\nGNU Denemo, a gtk+ frontend for GNU Lilypond\n"));
-  g_print (copytext);
+  g_print ("%s", copytext);
 
   g_free (helptext);
 

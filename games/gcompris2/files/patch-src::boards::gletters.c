--- src/boards/gletters.c.orig	Sat Sep 25 18:23:03 2004
+++ src/boards/gletters.c	Sat Sep 25 18:34:39 2004
@@ -436,6 +436,7 @@
   char c;
   char lcStr[6],ucStr[6];
   gchar *str;
+  gchar list_of_letters[255];
   char utf8char[6], keyChar[6], mapChar[6];
   int i;
 
@@ -575,7 +576,6 @@
     }
   }
 
-  gchar list_of_letters[255];
   list_of_letters[0] = '\0';
 
   /* We have to loop to concat the letters */

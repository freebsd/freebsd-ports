--- lib/misc.c.orig	Fri Dec  6 03:28:19 2002
+++ lib/misc.c	Fri Apr 25 01:51:48 2003
@@ -881,7 +881,8 @@
       diff += rd;
       tempstr[diff] = '\0'; 
 
-      if (diff > 11 && strcmp (tempstr + diff - 10, "password: ") == 0)
+      if ( (strcmp (tempstr, "Password:") == 0) ||
+           (diff > 11 && strcmp (tempstr + diff - 10, "password: ") == 0) )
         {
           if (wrotepw)
             {

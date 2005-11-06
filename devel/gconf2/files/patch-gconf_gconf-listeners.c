--- gconf/gconf-listeners.c.orig	Sun Nov  6 11:08:58 2005
+++ gconf/gconf-listeners.c	Sun Nov  6 11:09:05 2005
@@ -366,8 +366,8 @@
 
       while (across != NULL)
         {
-          lte = across->data;
           int cmp;
+          lte = across->data;
 
           cmp = strcmp(lte->name, dirnames[i]);
 


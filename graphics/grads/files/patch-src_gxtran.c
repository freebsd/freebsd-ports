--- src/gxtran.c.orig	2014-05-24 15:45:07.000000000 -0700
+++ src/gxtran.c	2014-05-24 15:46:08.000000000 -0700
@@ -97,7 +97,7 @@
   infile = fopen(ifi,"rb");
   if (infile == NULL) {
     printf ("Cannot open input file: %s\n",ifi);
-    return;
+    return 1;
   }
 
   pnt = 0;
@@ -257,7 +257,7 @@
 
     else {
       printf ("Invalid command found %i \n",cmd);
-      return;
+      return 1;
     }
   }
 }

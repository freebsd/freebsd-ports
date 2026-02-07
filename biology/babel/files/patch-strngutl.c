--- ./strngutl.c.orig	1997-01-21 16:52:52.000000000 +0100
+++ ./strngutl.c	2012-08-24 12:16:14.765914164 +0200
@@ -182,8 +182,8 @@
   int ilen;
   char *ptr;
       
-  if (!str) return;
-  if ((ilen = strlen(str)) == 0) return;
+  if (!str) return(NULL);
+  if ((ilen = strlen(str)) == 0) return(NULL);
 
   ptr = (char *) malloc ( (ilen+1) * sizeof(char) );
   strcpy ( ptr, str );

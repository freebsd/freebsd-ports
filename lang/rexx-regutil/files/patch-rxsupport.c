--- rxsupport.c.orig	2003-09-10 21:09:44 UTC
+++ rxsupport.c
@@ -612,7 +612,7 @@ int cha_adddummy(chararray *ca, const ch
     }
 
     ca->array[ca->count].strlength = len;
-    ca->array[ca->count++].strptr = (unsigned char *)str;
+    ca->array[ca->count++].strptr = (char *)str;
 
     return 0;
 }

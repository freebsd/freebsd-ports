--- src/base/baseValue.cpp.orig	Sun Jan 28 14:13:03 2007
+++ src/base/baseValue.cpp	Sun Jan 28 14:14:42 2007
@@ -49,11 +49,11 @@
       base = 10;
 
    // Only convert the first valid chars.
-   char *end = (char*)((int)nptr + strlen(nptr)-1);
+   char *end = (char*)((long)nptr + strlen(nptr)-1);
    for (i=0; i<strlen(nptr); i++)
       if (!isdigit(nptr[i]) && nptr[i] != '+' && nptr[i] != '-')
       {
-         end = (char*)((int)nptr + i -1);
+         end = (char*)((long)nptr + i -1);
          break;	
       }
 
@@ -91,11 +91,11 @@
       base = 10;
 
    //Only convert the first valid chars.
-   char *end = (char*)((int)nptr + strlen(nptr)-1);
+   char *end = (char*)((long)nptr + strlen(nptr)-1);
    for (i=0; i<strlen(nptr); i++)
       if (!isdigit(nptr[i]) && nptr[i] != '+')
       {
-         end = (char*)((int)nptr + i -1);
+         end = (char*)((long)nptr + i -1);
          break;	
       }
             

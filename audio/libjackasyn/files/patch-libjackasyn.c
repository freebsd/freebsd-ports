--- libjackasyn.c	Tue Aug 24 08:29:32 2004
+++ libjackasyn.c	Thu Apr  6 12:09:57 2006
@@ -47,9 +47,9 @@
     fprintf(stderr,"libjackasyn: cannot get application name\n");
     return NULL;
   }
-  n = namefield + strlen("Name: ");
+  n = namefield;
   len=0;
-  while (*(n+len) != '\n' && len < 255) len++;
+  while (*(n+len) != ' ' && len < 255) len++;
   if (len >= 255) {
     fprintf(stderr,"libjackasyn: cannot get process name\n");
     return NULL;
@@ -58,7 +58,7 @@
   pname = malloc(len+2);
   n[len]='\0';
   sprintf(pname,"%s_%d",n,num);
-  
+
   return pname;
 } 

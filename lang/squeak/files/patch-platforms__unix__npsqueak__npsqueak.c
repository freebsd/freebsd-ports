--- platforms/unix/npsqueak/npsqueak.c.orig	Sun Mar 20 05:38:26 2005
+++ platforms/unix/npsqueak/npsqueak.c	Sat Oct  7 19:56:10 2006
@@ -177,13 +177,16 @@
 findFileInPaths(char* result, char *filename, int dirn, char *dirv[PATH_MAX]){
   int i;
   char path[PATH_MAX];
+  char gzipedpath[PATH_MAX];
 
   for(i= 0; i < dirn; i++){
     DPRINT("NP: search \"%s\" in \"%s\" \n",filename,dirv[i]);
 
     strcpy(path, dirv[i]);
     strcat(path, filename); 
-    if (access(path, R_OK) == 0){ 
+    strcpy(gzipedpath, path);
+    strcat(gzipedpath, ".gz");
+    if (access(path, R_OK) == 0 || access(gzipedpath, R_OK) == 0){ 
       DPRINT("NP:  \"%s\" in \"%s\" found\n",filename,dirv[i]);
       return strcpy(result, path);
     }

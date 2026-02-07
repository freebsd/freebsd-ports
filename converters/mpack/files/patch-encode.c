--- encode.c.orig	Mon Jul 21 23:35:31 2003
+++ encode.c	Sun Mar 26 22:54:13 2006
@@ -23,12 +23,15 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 extern char *magic_look(FILE *infile);
 extern char *os_genid(void);
 extern FILE *os_createnewfile(char *fname);
 extern char *md5digest(FILE *infile, long int *len);
+extern void os_perror(char *str);
+extern int to64(FILE *infile, FILE *outfile, long int limit);
 
 #define NUMREFERENCES 4
 
@@ -43,7 +46,7 @@
     char *type;
     FILE *outfile;
     char *cleanfname, *p;
-    char *digest, *appledigest;
+    char *digest, *appledigest = NULL;
     long filesize, l, written;
     int thispart, numparts = 1;
     int wrotefiletype = 0;
@@ -59,10 +62,10 @@
      */
     if (p = strrchr(cleanfname, '.')) cleanfname = p+1;
 #else
-    if (p = strrchr(cleanfname, '/')) cleanfname = p+1;
-    if (p = strrchr(cleanfname, '\\')) cleanfname = p+1;
+    if ((p = strrchr(cleanfname, '/'))) cleanfname = p+1;
+    if ((p = strrchr(cleanfname, '\\'))) cleanfname = p+1;
 #endif
-    if (p = strrchr(cleanfname, ':')) cleanfname = p+1;
+    if ((p = strrchr(cleanfname, ':'))) cleanfname = p+1;
 
     /* Find file type */
     if (typeoverride) {

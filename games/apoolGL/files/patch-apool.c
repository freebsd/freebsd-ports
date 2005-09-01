--- apool.c.orig	Fri Aug 12 00:09:34 2005
+++ apool.c	Thu Sep  1 02:23:50 2005
@@ -27,7 +27,7 @@
 #include <math.h>
 #include <time.h>
 #include <string.h>
-#include <getopt.h>
+#include <unistd.h>
 #include <SDL/SDL.h>
 #include <GL/gl.h>
 #include <GL/glu.h>
@@ -103,10 +103,10 @@
   for( i=0;i<2;i++)
    { ply[i].stat = ply[i].wait = ply[i].col = ply[i].hole_black = 0; }
   first_hit = bande_hit = anstoss = 1;
-  if( !(dat = fopen("table.dat","r")) ) 
+  if( !(dat = fopen(DATADIR"/table.dat","r")) ) 
     {
       close_graphics();
-      printf("error: can't find the file 'table.dat'. \n");
+      printf("error: can't find the file '" DATADIR "/table.dat'. \n");
       printf("create this file using 'apool -init 50' ...\n\n");
       exit(0);
     }
@@ -427,9 +427,9 @@
  time_t sys_time;
  char opt;
  opterr=0; /* Keine Fehlermeldung bei "falscher" Option ausgeben */
- if( !(datei = fopen("konst.dat","r") ) ) 
+ if( !(datei = fopen(DATADIR"/konst.dat","r") ) ) 
   { /* Datei für die (phys.) Konstanten */
-  printf("can't open file 'konst.dat'\n");
+  printf("can't open file '" DATADIR "/konst.dat'\n");
   exit( 0 ); 
   }
  fscanf(datei,"%lg%*[^\n]%lg%*[^\n]%lg%*[^\n]%lg%*[^\n]%lg%*[^\n]",

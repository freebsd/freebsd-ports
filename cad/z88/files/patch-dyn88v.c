--- dyn88v.c.orig	Tue Dec 28 22:30:55 2004
+++ dyn88v.c	Tue Dec 28 22:31:29 2004
@@ -47,7 +47,7 @@
 #include <stdio.h>   /* FILE,NULL,fopen,fclose,fgets,sscanf */
                      /* rewind                              */
 #include <string.h>  /* strstr */
-#include <malloc.h>  /* FR_CALLOC */
+#include <stdlib.h>  /* FR_CALLOC */
 #endif
 
 /***********************************************************************

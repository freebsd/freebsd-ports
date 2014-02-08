--- ./f.meta.cc.orig	2014-02-05 20:42:34.000000000 +0100
+++ ./f.meta.cc	2014-02-06 10:32:37.000000000 +0100
@@ -23,6 +23,7 @@
 
 #define EX extern                                                          //  enable extern declarations
 #include "fotoxx.h"
+#include <sys/wait.h>
 
 
 /**************************************************************************
@@ -5786,7 +5787,7 @@
       strcpy(sxrec.size,"null");
 
    if (! sxrec.tags) 
-      sxrec.tags = strdupz("null"tagdelimB,0,"search-index");
+      sxrec.tags = strdupz("null" tagdelimB,0,"search-index");
 
    if (! sxrec.capt) 
       sxrec.capt = strdupz("null",0,"search-index");
@@ -5993,7 +5994,7 @@
 
          if (sxrec->tags) 
             nn = fprintf(fid2,"tags: %s\n",sxrec->tags);                   //  tags rec.
-         else nn = fprintf(fid2,"tags: null"tagdelimB"\n");
+         else nn = fprintf(fid2,"tags: null" tagdelimB"\n");
          if (! nn) goto file_err;
 
          if (sxrec->capt) 
@@ -6147,7 +6148,7 @@
       strcpy(sxrec.size,"null");
 
    if (! sxrec.tags) 
-      sxrec.tags = strdupz("null"tagdelimB,0,"search-index");
+      sxrec.tags = strdupz("null" tagdelimB,0,"search-index");
    
    if (! sxrec.capt) 
       sxrec.capt = strdupz("null",0,"search-index");
@@ -6259,7 +6260,7 @@
 
    if (sxrec->tags) 
       nn = fprintf(fid,"tags: %s\n",sxrec->tags);                          //  tags rec.
-   else nn = fprintf(fid,"tags: null"tagdelimB"\n");
+   else nn = fprintf(fid,"tags: null" tagdelimB"\n");
    if (! nn) goto file_err;
 
    if (sxrec->capt) 

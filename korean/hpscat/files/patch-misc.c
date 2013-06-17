--- misc.c.orig	1995-11-23 15:40:07.000000000 -0500
+++ misc.c	2013-06-12 18:43:01.000000000 -0400
@@ -2,8 +2,8 @@
 #include "hpscat.h"
 #include "paper.h"
 
-extern totalpages;
-static converted;
+extern int totalpages;
+static int converted;
 char  *tmpfn;
 
 void
@@ -36,6 +36,7 @@
 #endif
       case Nbyte: strcpy(args[1], fromN); break;
       case ISO:   strcpy(args[1], fromI); break;
+      default:    /* NOTREACHED */ return;
     }
     execute(args);
     fclose(fp);

--- misc.c.orig	1995-11-23 20:40:07 UTC
+++ misc.c
@@ -2,8 +2,8 @@
 #include "hpscat.h"
 #include "paper.h"
 
-extern totalpages;
-static converted;
+extern int totalpages;
+static int converted;
 char  *tmpfn;
 
 void
@@ -36,6 +36,7 @@ convert(s)
 #endif
       case Nbyte: strcpy(args[1], fromN); break;
       case ISO:   strcpy(args[1], fromI); break;
+      default:    /* NOTREACHED */ return;
     }
     execute(args);
     fclose(fp);

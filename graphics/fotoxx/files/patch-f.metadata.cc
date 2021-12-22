--- f.metadata.cc.orig	2015-05-01 09:40:38 UTC
+++ f.metadata.cc
@@ -92,6 +92,11 @@
 
 #define EX extern                                                          //  enable extern declarations
 #include "fotoxx.h"                                                        //  (variables in fotoxx.h are refs)
+#include <sys/wait.h>
+
+#ifndef ECOMM
+#define ECOMM EIO
+#endif
 
 /**************************************************************************/
 
@@ -5911,7 +5917,7 @@ int get_sxrec(sxrec_t &sxrec, cchar *fil
       strcpy(sxrec.size,"null");
 
    if (! sxrec.tags)
-      sxrec.tags = zstrdup("null"tagdelimB);
+      sxrec.tags = zstrdup("null" tagdelimB);
 
    if (! sxrec.capt)
       sxrec.capt = zstrdup("null");
@@ -6118,7 +6124,7 @@ int put_sxrec(sxrec_t *sxrec, cchar *fil
 
          if (sxrec->tags)
             nn = fprintf(fid2,"tags: %s\n",sxrec->tags);                   //  tags rec.
-         else nn = fprintf(fid2,"tags: null"tagdelimB"\n");
+         else nn = fprintf(fid2,"tags: null" tagdelimB"\n");
          if (! nn) goto file_err;
 
          if (sxrec->capt)
@@ -6270,7 +6276,7 @@ int read_sxrec_seq(sxrec_t &sxrec, int &
       strcpy(sxrec.size,"null");
 
    if (! sxrec.tags)
-      sxrec.tags = zstrdup("null"tagdelimB);
+      sxrec.tags = zstrdup("null" tagdelimB);
 
    if (! sxrec.capt)
       sxrec.capt = zstrdup("null");
@@ -6381,7 +6387,7 @@ int write_sxrec_seq(sxrec_t *sxrec, int 
 
    if (sxrec->tags)
       nn = fprintf(fid,"tags: %s\n",sxrec->tags);                          //  tags rec.
-   else nn = fprintf(fid,"tags: null"tagdelimB"\n");
+   else nn = fprintf(fid,"tags: null" tagdelimB"\n");
    if (! nn) goto file_err;
 
    if (sxrec->capt)

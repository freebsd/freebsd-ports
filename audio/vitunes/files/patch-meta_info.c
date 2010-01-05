--- ./meta_info.c.orig	2010-01-04 03:17:55.000000000 +0100
+++ ./meta_info.c	2010-01-05 18:33:03.000000000 +0100
@@ -678,7 +678,7 @@
       const char *errstr = NULL;
 
       /* note that the range is here what libid3tag can handle */
-      gindex = strtonum(mi->cinfo[MI_CINFO_GENRE], 0, 147, &errstr);
+      gindex = atoll(mi->cinfo[MI_CINFO_GENRE]);
       if (errstr != NULL) {  /* check for invalid genre number */
          free(mi->cinfo[MI_CINFO_GENRE]);
          mi->cinfo[MI_CINFO_GENRE] = NULL;

--- bin/fits/keywords.c.orig	2020-05-15 16:58:42 UTC
+++ bin/fits/keywords.c
@@ -413,6 +413,8 @@ keywords_date_to_seconds(struct fitsparams *p, fitsfil
   /* Return the number of seconds (and subseconds) that it corresponds
      to. */
   seconds=gal_fits_key_date_to_seconds(fitsdate, &subsecstr, &subsec);
+  if(seconds==GAL_BLANK_SIZE_T)
+    error(EXIT_FAILURE, 0, "the time string couldn't be interpretted");
 
   /* Print the result (for the sub-seconds, print everything after the */
   if( !p->cp.quiet )

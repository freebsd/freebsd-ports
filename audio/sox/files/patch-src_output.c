--- src/output.c.orig	2021-05-09 20:19:07 UTC
+++ src/output.c
@@ -31,6 +31,11 @@ static int flow(sox_effect_t *effp, sox_sample_t const
     sox_sample_t * obuf, size_t * isamp, size_t * osamp)
 {
   priv_t * p = (priv_t *)effp->priv;
+  /* Abort if there are no samples to write */
+  if (*isamp == 0) {
+    *osamp = 0;
+    return SOX_SUCCESS;
+  }
   /* Write out *isamp samples */
   size_t len = sox_write(p->file, ibuf, *isamp);
 

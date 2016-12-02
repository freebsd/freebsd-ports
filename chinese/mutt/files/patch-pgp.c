--- pgp.c.orig	2016-10-09 03:30:21.000000000 +0800
+++ pgp.c	2016-12-02 11:18:42.603476000 +0800
@@ -1154,7 +1154,7 @@ BODY *pgp_sign_message (BODY *a)
   int empty = 1;
   pid_t thepid;
   
-  convert_to_7bit (a); /* Signed data _must_ be in 7-bit format. */
+  if (!option(OPTBBSISLAME)) convert_to_7bit (a); /* Signed data _must_ be in 7-bit format. */
 
   mutt_mktemp (sigfile, sizeof (sigfile));
   if ((fp = safe_fopen (sigfile, "w")) == NULL)

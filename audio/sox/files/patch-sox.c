Fix badly-imbalanced parens.

diff -burp sox-14.1.0/src/sox.c sox-14.1.0-dan/src/sox.c
--- src/sox.c	2008-07-28 15:04:36.000000000 -0500
+++ src/sox.c	2008-07-30 11:36:41.046073378 -0500
@@ -1716,7 +1716,7 @@ int main(int argc, char **argv)
     combine_method = sox_concatenate;
 
   /* Make sure we got at least the required # of input filenames */
-  if (input_count < is_serial(combine_method ? 1 : 2))
+  if (input_count < (is_serial(combine_method) ? 1 : 2))
     usage("Not enough input filenames specified");
 
   /* Check for misplaced input/output-specific options */

--- src/alac.c.orig	2011-08-20 22:06:21 UTC
+++ src/alac.c
@@ -804,7 +804,7 @@ void decode_frame(alac_file *alac,
             }
             else
             {
-                fprintf(stderr, "FIXME: unhandled predicition type: %i\n", prediction_type);
+                xprintf("FIXME: unhandled predicition type: %i\n", prediction_type);
                 /* i think the only other prediction type (or perhaps this is just a
                  * boolean?) runs adaptive fir twice.. like:
                  * predictor_decompress_fir_adapt(predictor_error, tempout, ...)
@@ -885,7 +885,7 @@ void decode_frame(alac_file *alac,
         }
         case 20:
         case 32:
-            fprintf(stderr, "FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
+            xprintf("FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
             break;
         default:
             break;
@@ -1004,7 +1004,7 @@ void decode_frame(alac_file *alac,
             }
             else
             { /* see mono case */
-                fprintf(stderr, "FIXME: unhandled predicition type: %i\n", prediction_type_a);
+                xprintf("FIXME: unhandled predicition type: %i\n", prediction_type_a);
             }
 
             /* channel 2 */
@@ -1029,7 +1029,7 @@ void decode_frame(alac_file *alac,
             }
             else
             {
-                fprintf(stderr, "FIXME: unhandled predicition type: %i\n", prediction_type_b);
+                xprintf("FIXME: unhandled predicition type: %i\n", prediction_type_b);
             }
         }
         else
@@ -1106,7 +1106,7 @@ void decode_frame(alac_file *alac,
         }
         case 20:
         case 32:
-            fprintf(stderr, "FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
+            xprintf("FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
             break;
         default:
             break;

--- src/alac.c.orig	2011-08-21 00:06:21.000000000 +0200
+++ src/alac.c	2012-10-09 12:09:33.000000000 +0200
@@ -804,7 +804,7 @@
             }
             else
             {
-                fprintf(stderr, "FIXME: unhandled predicition type: %i\n", prediction_type);
+                xprintf("FIXME: unhandled predicition type: %i\n", prediction_type);
                 /* i think the only other prediction type (or perhaps this is just a
                  * boolean?) runs adaptive fir twice.. like:
                  * predictor_decompress_fir_adapt(predictor_error, tempout, ...)
@@ -885,7 +885,7 @@
         }
         case 20:
         case 32:
-            fprintf(stderr, "FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
+            xprintf("FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
             break;
         default:
             break;
@@ -1004,7 +1004,7 @@
             }
             else
             { /* see mono case */
-                fprintf(stderr, "FIXME: unhandled predicition type: %i\n", prediction_type_a);
+                xprintf("FIXME: unhandled predicition type: %i\n", prediction_type_a);
             }
 
             /* channel 2 */
@@ -1029,7 +1029,7 @@
             }
             else
             {
-                fprintf(stderr, "FIXME: unhandled predicition type: %i\n", prediction_type_b);
+                xprintf("FIXME: unhandled predicition type: %i\n", prediction_type_b);
             }
         }
         else
@@ -1106,7 +1106,7 @@
         }
         case 20:
         case 32:
-            fprintf(stderr, "FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
+            xprintf("FIXME: unimplemented sample size %i\n", alac->setinfo_sample_size);
             break;
         default:
             break;

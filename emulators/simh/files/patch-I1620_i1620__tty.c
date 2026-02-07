--- I1620/i1620_tty.c.orig	2016-12-01 22:43:42 UTC
+++ I1620/i1620_tty.c
@@ -260,7 +260,7 @@ do {
         *c = 0x7F;
     else if ((raw == '~') || (raw == '`'))              /* flag? mark */
         flg = FLAG;
-    else if (cp = strchr (tti_to_num, raw))             /* legal? */
+    else if ((cp = strchr (tti_to_num, raw)))           /* legal? */
         *c = ((int8) (cp - tti_to_num)) | flg;          /* assemble char */
     else raw = 007;                                     /* beep! */
     tto_write (raw);                                    /* echo */

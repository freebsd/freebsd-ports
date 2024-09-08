--- src/xvjpeg.c.orig	2024-08-12 21:10:49 UTC
+++ src/xvjpeg.c
@@ -710,7 +710,7 @@ L2:
         if ((cmy = k - *q++) < 0) { cmy = 0; } *p++ = cmy; /* R */
         if ((cmy = k - *q++) < 0) { cmy = 0; } *p++ = cmy; /* G */
         if ((cmy = k - *q++) < 0) { cmy = 0; } *p++ = cmy; /* B */
-      } while (++q <= pic_end);
+      } while (++q < pic_end);
     }
     pic = realloc(pic,p-pic); /* Release extra storage */
   }

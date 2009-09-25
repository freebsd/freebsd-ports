$OpenBSD$
--- xvjpeg.c.orig	Fri Aug 28 13:41:30 2009
+++ xvjpeg.c	Fri Aug 28 18:58:46 2009
@@ -696,7 +696,7 @@ L2:
         if ((cmy = *q++ - k) < 0) cmy = 0; *p++ = cmy; /* R */
         if ((cmy = *q++ - k) < 0) cmy = 0; *p++ = cmy; /* G */
         if ((cmy = *q++ - k) < 0) cmy = 0; *p++ = cmy; /* B */
-      } while (++q <= pic_end);
+      } while (++q < pic_end);
     }
     else { /* assume normal data */
       register byte *q = pic;
@@ -707,7 +707,7 @@ L2:
         if ((cmy = k - *q++) < 0) cmy = 0; *p++ = cmy; /* R */
         if ((cmy = k - *q++) < 0) cmy = 0; *p++ = cmy; /* G */
         if ((cmy = k - *q++) < 0) cmy = 0; *p++ = cmy; /* B */
-      } while (++q <= pic_end);
+      } while (++q < pic_end);
     }
     pic = realloc(pic,p-pic); /* Release extra storage */
   }

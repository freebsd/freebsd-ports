--- lib/zlib/src/inffast.c.orig	Thu Jun 20 08:40:24 2002
+++ lib/zlib/src/inffast.c	Sun Aug  4 17:16:50 2002
@@ -1,5 +1,5 @@
 /* inffast.c -- process literals and length/distance pairs fast
- * Copyright (C) 1995-1998 Mark Adler
+ * Copyright (C) 1995-2002 Mark Adler
  * For conditions of distribution and use, see copyright notice in zlib.h 
  */
 
@@ -93,28 +93,41 @@
 
             /* do the copy */
             m -= c;
-            if ((uInt)(q - s->window) >= d)     /* offset before dest */
-            {                                   /*  just copy */
-              r = q - d;
-              *q++ = *r++;  c--;        /* minimum count is three, */
-              *q++ = *r++;  c--;        /*  so unroll loop a little */
-            }
-            else                        /* else offset after destination */
+            r = q - d;
+            if (r < s->window)                  /* wrap if needed */
             {
-              e = d - (uInt)(q - s->window); /* bytes from offset to end */
-              r = s->end - e;           /* pointer to offset */
-              if (c > e)                /* if source crosses, */
+              do {
+                r += s->end - s->window;        /* force pointer in window */
+              } while (r < s->window);          /* covers invalid distances */
+              e = s->end - r;
+              if (c > e)
               {
-                c -= e;                 /* copy to end of window */
+                c -= e;                         /* wrapped copy */
                 do {
-                  *q++ = *r++;
+                    *q++ = *r++;
                 } while (--e);
-                r = s->window;          /* copy rest from start of window */
+                r = s->window;
+                do {
+                    *q++ = *r++;
+                } while (--c);
               }
+              else                              /* normal copy */
+              {
+                *q++ = *r++;  c--;
+                *q++ = *r++;  c--;
+                do {
+                    *q++ = *r++;
+                } while (--c);
+              }
+            }
+            else                                /* normal copy */
+            {
+              *q++ = *r++;  c--;
+              *q++ = *r++;  c--;
+              do {
+                *q++ = *r++;
+              } while (--c);
             }
-            do {                        /* copy all or what's left */
-              *q++ = *r++;
-            } while (--c);
             break;
           }
           else if ((e & 64) == 0)

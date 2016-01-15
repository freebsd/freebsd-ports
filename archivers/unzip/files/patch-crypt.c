--- crypt.c.orig	2007-01-05 16:47:36.000000000 +0100
+++ crypt.c	2016-01-04 14:39:27.300502995 +0100
@@ -465,7 +465,17 @@
     GLOBAL(pInfo->encrypted) = FALSE;
     defer_leftover_input(__G);
     for (n = 0; n < RAND_HEAD_LEN; n++) {
-        b = NEXTBYTE;
+        /* 2012-11-23 SMS.  (OUSPG report.)
+         * Quit early if compressed size < HEAD_LEN.  The resulting
+         * error message ("unable to get password") could be improved,
+         * but it's better than trying to read nonexistent data, and
+         * then continuing with a negative G.csize.  (See
+         * fileio.c:readbyte()).
+         */
+        if ((b = NEXTBYTE) == (ush)EOF)
+        {
+            return PK_ERR;
+        }
         h[n] = (uch)b;
         Trace((stdout, " (%02x)", h[n]));
     }

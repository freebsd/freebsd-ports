--- crypt.c.orig	2007-01-05 15:47:36 UTC
+++ crypt.c
@@ -465,7 +465,17 @@ int decrypt(__G__ passwrd)
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

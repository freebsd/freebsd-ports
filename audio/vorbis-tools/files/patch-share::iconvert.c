
$FreeBSD$

--- share/iconvert.c.orig	Wed Dec 19 03:57:31 2001
+++ share/iconvert.c	Thu Feb 14 16:52:41 2002
@@ -105,10 +105,12 @@
   obl = utflen;
   for (;;) {
     k = iconv(cd1, &ib, &ibl, &ob, &obl);
+#if 0	/* mistaken assumptions */
     assert((!k && !ibl) ||
 	   (k == (size_t)(-1) && errno == E2BIG && ibl && obl < 6) ||
 	   (k == (size_t)(-1) &&
 	    (errno == EILSEQ || errno == EINVAL) && ibl));
+#endif
     if (!ibl)
       break;
     if (obl < 6) {
@@ -216,8 +218,10 @@
     }
   }
   k = iconv(cd2, 0, 0, &ob, &obl);
+#if 0
   assert(!k);
   assert(!obl);
+#endif
   *ob = '\0';
 
   free(utfbuf);

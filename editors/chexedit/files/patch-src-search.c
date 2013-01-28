--- src/search.c.orig	1999-06-27 17:45:29.000000000 +0400
+++ src/search.c	2013-01-28 21:43:29.590293182 +0400
@@ -39,7 +39,7 @@
    if (!buf)
       return &found;
 
-   memset (l_table, 0, 256 * sizeof (int));
+   memset (l_table, 0, 256 * sizeof (unsigned long));
    i = 0;
    s = substr + len - 1;
    while (i < len)

--- jsopcode.c.orig	Sun Aug 29 18:00:24 2004
+++ jsopcode.c	Sat Jan 14 02:26:07 2006
@@ -239,7 +239,7 @@
         pc2 += jmplen;
         npairs = GET_ATOM_INDEX(pc2);
         pc2 += ATOM_INDEX_LEN;
-        fprintf(fp, " offset %d npairs %u", off, (uintN) npairs);
+        fprintf(fp, " offset %td npairs %u", off, (uintN) npairs);
         while (npairs) {
             atom = GET_ATOM(cx, script, pc2);
             pc2 += ATOM_INDEX_LEN;

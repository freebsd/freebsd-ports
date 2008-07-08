--- jsopcode.c	2007-09-27 20:30:18.000000000 +0200
+++ jsopcode.c	2008-06-19 16:10:44.000000000 +0200
@@ -262,7 +262,7 @@
         pc2 += jmplen;
         npairs = GET_ATOM_INDEX(pc2);
         pc2 += ATOM_INDEX_LEN;
-        fprintf(fp, " offset %d npairs %u", off, (uintN) npairs);
+        fprintf(fp, " offset %td npairs %u", off, (uintN) npairs);
         while (npairs) {
             atom = GET_ATOM(cx, script, pc2);
             pc2 += ATOM_INDEX_LEN;

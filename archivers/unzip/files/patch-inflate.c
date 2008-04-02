--- unzip-5.52.orig/inflate.c
+++ inflate.c
@@ -983,6 +983,7 @@
   unsigned l;           /* last length */
   unsigned m;           /* mask for bit lengths table */
   unsigned n;           /* number of lengths to get */
+  struct huft *tlp;     
   struct huft *tl;      /* literal/length code table */
   struct huft *td;      /* distance code table */
   unsigned bl;          /* lookup bits for tl */
@@ -996,6 +997,8 @@
   int retval = 0;       /* error code returned: initialized to "no error" */
 
 
+  td = tlp = tl = (struct huft *)NULL;
+
   /* make local bit buffer */
   Trace((stderr, "\ndynamic block"));
   b = G.bb;
@@ -1047,9 +1050,9 @@
   while (i < n)
   {
     NEEDBITS(bl)
-    j = (td = tl + ((unsigned)b & m))->b;
+    j = (tlp = tl + ((unsigned)b & m))->b;
     DUMPBITS(j)
-    j = td->v.n;
+    j = tlp->v.n;
     if (j < 16)                 /* length of code in bits (0..15) */
       ll[i++] = l = j;          /* save last length in l */
     else if (j == 16)           /* repeat last length 3 to 6 times */
@@ -1141,6 +1144,7 @@
       huft_free(td);
     }
     huft_free(tl);
+
     return retval;
   }
 
@@ -1149,8 +1153,8 @@
 
 cleanup_and_exit:
   /* free the decoding tables, return */
-  huft_free(tl);
-  huft_free(td);
+  if (tl) huft_free(tl);
+  if (td) huft_free(td);
   return retval;
 }
 

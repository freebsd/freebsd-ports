--- gcin2tab.c.orig	Sun Dec  3 11:05:26 2006
+++ gcin2tab.c	Sun Dec  3 11:08:36 2006
@@ -129,7 +129,10 @@
   int d;
   if ((d = a->key - b->key)) return d;
 
-  return memcmp(a->ch ,b->ch, CH_SZ);
+  d = memcmp(a->ch ,b->ch, CH_SZ);
+  if (d) return d;
+  
+  return a->oseq - b->oseq;
 }
 
 int qcmp2_64(const void *aa, const void *bb)
@@ -139,7 +142,10 @@
   if (a->key > b->key) return 1;
   if (a->key < b->key) return -1;
 
-  return memcmp(a->ch ,b->ch, CH_SZ);
+  int d = memcmp(a->ch ,b->ch, CH_SZ);
+  if (d) return d;
+  
+  return a->oseq - b->oseq;
 }
 
 int qcmp(const void *aa, const void *bb)

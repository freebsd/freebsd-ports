--- corelib/ncbimisc.c.orig
+++ corelib/ncbimisc.c
@@ -1266,7 +1266,7 @@
   if (len < 1) return NULL;
 
   rsult = (Nlm_CharPtr) MemNew (len + 3);
-  if (rsult == NULL) return;
+  if (rsult == NULL) return NULL;
   tmp = rsult;
 
   for (i = 0; /* local [i] != NULL */ i < numitems; i++) {

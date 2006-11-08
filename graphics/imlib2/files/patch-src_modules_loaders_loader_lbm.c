--- src/modules/loaders/loader_lbm.c.orig	Wed Nov  8 19:42:46 2006
+++ src/modules/loaders/loader_lbm.c	Wed Nov  8 19:47:10 2006
@@ -421,7 +421,7 @@
 
         im->w = L2RWORD(ilbm.bmhd.data);
         im->h = L2RWORD(ilbm.bmhd.data + 2);
-        if (im->w <= 0 || im->h <= 0) ok = 0;
+        if (im->w <= 0 || im->h <= 0 || im->w > 16383 || im->h > 16383) ok = 0;
 
         ilbm.depth = ilbm.bmhd.data[8];
         if (ilbm.depth < 1 || (ilbm.depth > 8 && ilbm.depth != 24 && ilbm.depth != 32)) ok = 0; /* Only 1 to 8, 24, or 32 planes. */
@@ -453,6 +453,8 @@
         }
     }
     if (!full || !ok) {
+	im->w = 0;
+	im->h = 0;
         freeilbm(&ilbm);
         return ok;
     }
@@ -468,11 +470,14 @@
     plane[0] = NULL;
 
     im->data = malloc(im->w * im->h * sizeof(DATA32));
-    if (im->data) {
-        n = ilbm.depth;
-        if (ilbm.mask == 1) n++;
 
-        plane[0] = malloc(((im->w + 15) / 16) * 2 * n);
+    n = ilbm.depth;
+    if (ilbm.mask == 1)
+	n++;
+
+    plane[0] = malloc(((im->w + 15) / 16) * 2 * n);
+
+    if (im->data != NULL && plane[0] != NULL) {
         for (i = 1; i < n; i++) plane[i] = plane[i - 1] + ((im->w + 15) / 16) * 2;
 
         z = ((im->w + 15) / 16) * 2 * n;
@@ -511,6 +516,8 @@
    * the memory for im->data.
    *----------*/
     if (!ok) {
+	im->w = 0;
+	im->h = 0;
         if (im->data) free(im->data);
         im->data = NULL;
     }

--- filters/kword/pdf/xpdf/xpdf/XRef.cc.orig	2004-09-17 23:54:38.000000000 -0700
+++ filters/kword/pdf/xpdf/xpdf/XRef.cc	2004-09-25 17:59:36.000000000 -0700
@@ -76,6 +76,12 @@
 
   // trailer is ok - read the xref table
   } else {
+    if (size*sizeof(XRefEntry)/sizeof(XRefEntry) != size) {
+      error(-1, "Invalid 'size' inside xref table.");
+      ok = gFalse;
+      errCode = errDamaged;
+      return;
+    }
     entries = (XRefEntry *)gmalloc(size * sizeof(XRefEntry));
     for (i = 0; i < size; ++i) {
       entries[i].offset = 0xffffffff;
@@ -267,6 +273,10 @@
     // table size
     if (first + n > size) {
       newSize = size + 256;
+      if (newSize*sizeof(XRefEntry)/sizeof(XRefEntry) != newSize) {
+        error(-1, "Invalid 'newSize'");
+        goto err2;
+      }
       entries = (XRefEntry *)grealloc(entries, newSize * sizeof(XRefEntry));
       for (i = size; i < newSize; ++i) {
 	entries[i].offset = 0xffffffff;
@@ -410,6 +420,10 @@
 	    if (!strncmp(p, "obj", 3)) {
 	      if (num >= size) {
 		newSize = (num + 1 + 255) & ~255;
+	        if (newSize*sizeof(XRefEntry)/sizeof(XRefEntry) != newSize) {
+	          error(-1, "Invalid 'obj' parameters.");
+	          return gFalse;
+	        }
 		entries = (XRefEntry *)
 		            grealloc(entries, newSize * sizeof(XRefEntry));
 		for (i = size; i < newSize; ++i) {
@@ -431,6 +445,11 @@
     } else if (!strncmp(p, "endstream", 9)) {
       if (streamEndsLen == streamEndsSize) {
 	streamEndsSize += 64;
+        if (streamEndsSize*sizeof(int)/sizeof(int) != streamEndsSize) {
+          error(-1, "Invalid 'endstream' parameter.");
+          return gFalse;
+        }
+
 	streamEnds = (Guint *)grealloc(streamEnds,
 				       streamEndsSize * sizeof(int));
       }

--- kpdf/xpdf/XRef.cc	20 Aug 2003 21:25:12 -0000	1.3
+++ kpdf/xpdf/XRef.cc	18 Oct 2004 20:12:09 -0000
@@ -74,10 +74,16 @@ XRef::XRef(BaseStream *strA, GString *ow
       return;
     }
 
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
       entries[i].used = gFalse;
     }
@@ -265,10 +271,14 @@ GBool XRef::readXRef(Guint *pos) {
     }
     // check for buggy PDF files with an incorrect (too small) xref
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
 	entries[i].used = gFalse;
       }
@@ -413,10 +423,14 @@ GBool XRef::constructXRef() {
 	      ++p;
 	    } while (*p && isspace(*p));
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
 		  entries[i].offset = 0xffffffff;
 		  entries[i].used = gFalse;
@@ -434,10 +448,15 @@ GBool XRef::constructXRef() {
       }
 
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
       streamEnds[streamEndsLen++] = pos;
     }

--- xpdf/Gfx.cc	Mon May 17 21:37:57 2004
+++ xpdf/Gfx.cc	Fri Dec 24 17:01:42 2004
@@ -2654,7 +2654,9 @@
     haveMask = gFalse;
     dict->lookup("Mask", &maskObj);
     if (maskObj.isArray()) {
-      for (i = 0; i < maskObj.arrayGetLength(); ++i) {
+      for (i = 0;
+	   i < maskObj.arrayGetLength() && i < 2*gfxColorMaxComps;
+	   ++i) {
 	maskObj.arrayGet(i, &obj1);
 	maskColors[i] = obj1.getInt();
 	obj1.free();
--- xpdf/GfxState.cc	Mon May 17 21:37:57 2004
+++ xpdf/GfxState.cc	Fri Dec 24 17:01:42 2004
@@ -714,6 +714,11 @@
   }
   nCompsA = obj2.getInt();
   obj2.free();
+  if (nCompsA > gfxColorMaxComps) {
+    error(-1, "ICCBased color space with too many (%d > %d) components",
+	  nCompsA, gfxColorMaxComps);
+    nCompsA = gfxColorMaxComps;
+  }
   if (dict->lookup("Alternate", &obj2)->isNull() ||
       !(altA = GfxColorSpace::parse(&obj2))) {
     switch (nCompsA) {
@@ -1060,7 +1065,7 @@
   }
   nCompsA = obj1.arrayGetLength();
   if (nCompsA > gfxColorMaxComps) {
-    error(-1, "DeviceN color space with more than %d > %d components",
+    error(-1, "DeviceN color space with too many (%d > %d) components",
 	  nCompsA, gfxColorMaxComps);
     nCompsA = gfxColorMaxComps;
   }

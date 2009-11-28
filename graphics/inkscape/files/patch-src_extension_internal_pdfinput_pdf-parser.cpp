--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2009-11-26 03:14:38.000000000 +0100
+++ src/extension/internal/pdfinput/pdf-parser.cpp	2009-11-26 03:14:47.000000000 +0100
@@ -809,7 +809,7 @@ void PdfParser::opSetExtGState(Object ar
 	  blendingColorSpace = NULL;
 	  isolated = knockout = gFalse;
 	  if (!obj4.dictLookup(const_cast<char*>("CS"), &obj5)->isNull()) {
-	    blendingColorSpace = GfxColorSpace::parse(&obj5);
+	    blendingColorSpace = GfxColorSpace::parse(&obj5,(Gfx*)this);
 	  }
 	  obj5.free();
 	  if (obj4.dictLookup(const_cast<char*>("I"), &obj5)->isBool()) {
@@ -1009,9 +1009,9 @@ void PdfParser::opSetFillColorSpace(Obje
   state->setFillPattern(NULL);
   res->lookupColorSpace(args[0].getName(), &obj);
   if (obj.isNull()) {
-    colorSpace = GfxColorSpace::parse(&args[0]);
+    colorSpace = GfxColorSpace::parse(&args[0],(Gfx*)this);
   } else {
-    colorSpace = GfxColorSpace::parse(&obj);
+    colorSpace = GfxColorSpace::parse(&obj,(Gfx*)this);
   }
   obj.free();
   if (colorSpace) {
@@ -1032,9 +1032,9 @@ void PdfParser::opSetStrokeColorSpace(Ob
   state->setStrokePattern(NULL);
   res->lookupColorSpace(args[0].getName(), &obj);
   if (obj.isNull()) {
-    colorSpace = GfxColorSpace::parse(&args[0]);
+    colorSpace = GfxColorSpace::parse(&args[0],(Gfx*)this);
   } else {
-    colorSpace = GfxColorSpace::parse(&obj);
+    colorSpace = GfxColorSpace::parse(&obj,(Gfx*)this);
   }
   obj.free();
   if (colorSpace) {
@@ -1101,7 +1101,7 @@ void PdfParser::opSetFillColorN(Object a
       builder->updateStyle(state);
     }
     if (args[numArgs-1].isName() &&
-	(pattern = res->lookupPattern(args[numArgs-1].getName()))) {
+	(pattern = res->lookupPattern(args[numArgs-1].getName(),(Gfx*)this))) {
       state->setFillPattern(pattern);
       builder->updateStyle(state);
     }
@@ -1145,7 +1145,7 @@ void PdfParser::opSetStrokeColorN(Object
       builder->updateStyle(state);
     }
     if (args[numArgs-1].isName() &&
-	(pattern = res->lookupPattern(args[numArgs-1].getName()))) {
+	(pattern = res->lookupPattern(args[numArgs-1].getName(),(Gfx*)this))) {
       state->setStrokePattern(pattern);
       builder->updateStyle(state);
     }
@@ -1543,7 +1543,7 @@ void PdfParser::opShFill(Object args[], 
   double *matrix = NULL;
   GBool savedState = gFalse;
 
-  if (!(shading = res->lookupShading(args[0].getName()))) {
+  if (!(shading = res->lookupShading(args[0].getName(),(Gfx*)this))) {
     return;
   }
 
@@ -2507,7 +2655,7 @@ void PdfParser::doImage(Object *ref, Str
       }
     }
     if (!obj1.isNull()) {
-      colorSpace = GfxColorSpace::parse(&obj1);
+      colorSpace = GfxColorSpace::parse(&obj1,(Gfx*)this);
     } else if (csMode == streamCSDeviceGray) {
       colorSpace = new GfxDeviceGrayColorSpace();
     } else if (csMode == streamCSDeviceRGB) {
@@ -2592,7 +2740,7 @@ void PdfParser::doImage(Object *ref, Str
 	  obj2.free();
 	}
       }
-      maskColorSpace = GfxColorSpace::parse(&obj1);
+      maskColorSpace = GfxColorSpace::parse(&obj1,(Gfx*)this);
       obj1.free();
       if (!maskColorSpace || maskColorSpace->getMode() != csDeviceGray) {
 	goto err1;
@@ -2767,7 +2915,7 @@ void PdfParser::doForm(Object *str) {
     if (obj1.dictLookup(const_cast<char*>("S"), &obj2)->isName(const_cast<char*>("Transparency"))) {
       transpGroup = gTrue;
       if (!obj1.dictLookup(const_cast<char*>("CS"), &obj3)->isNull()) {
-	blendingColorSpace = GfxColorSpace::parse(&obj3);
+	blendingColorSpace = GfxColorSpace::parse(&obj3,(Gfx*)this);
       }
       obj3.free();
       if (obj1.dictLookup(const_cast<char*>("I"), &obj3)->isBool()) {

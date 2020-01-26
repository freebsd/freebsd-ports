--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2020-01-25 21:47:43 UTC
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -265,14 +265,14 @@ GfxPatch blankPatch()
 class ClipHistoryEntry {
 public:
 
-    ClipHistoryEntry(GfxPath *clipPath = NULL, GfxClipType clipType = clipNormal);
+    ClipHistoryEntry(const GfxPath *clipPath = NULL, GfxClipType clipType = clipNormal);
     virtual ~ClipHistoryEntry();
 
     // Manipulate clip path stack
     ClipHistoryEntry *save();
     ClipHistoryEntry *restore();
-    GBool hasSaves() { return saved != NULL; }
-    void setClip(GfxPath *newClipPath, GfxClipType newClipType = clipNormal);
+    bool hasSaves() { return saved != NULL; }
+    void setClip(const GfxPath *newClipPath, GfxClipType newClipType = clipNormal);
     GfxPath *getClipPath() { return clipPath; }
     GfxClipType getClipType() { return clipType; }
 
@@ -299,11 +299,11 @@ PdfParser::PdfParser(XRef *xrefA,
                      _POPPLER_CONST PDFRectangle *cropBox) :
     xref(xrefA),
     builder(builderA),
-    subPage(gFalse),
+    subPage(false),
     printCommands(false),
     res(new GfxResources(xref, resDict, NULL)), // start the resource stack
-    state(new GfxState(72.0, 72.0, box, rotate, gTrue)),
-    fontChanged(gFalse),
+    state(new GfxState(72.0, 72.0, box, rotate, true)),
+    fontChanged(false),
     clip(clipNone),
     ignoreUndef(0),
     baseMatrix(),
@@ -356,11 +356,11 @@ PdfParser::PdfParser(XRef *xrefA,
 		     _POPPLER_CONST PDFRectangle *box) :
     xref(xrefA),
     builder(builderA),
-    subPage(gTrue),
+    subPage(true),
     printCommands(false),
     res(new GfxResources(xref, resDict, NULL)), // start the resource stack
-    state(new GfxState(72, 72, box, 0, gFalse)),
-    fontChanged(gFalse),
+    state(new GfxState(72, 72, box, 0, false)),
+    fontChanged(false),
     clip(clipNone),
     ignoreUndef(0),
     baseMatrix(),
@@ -409,7 +409,7 @@ PdfParser::~PdfParser() {
   }
 }
 
-void PdfParser::parse(Object *obj, GBool topLevel) {
+void PdfParser::parse(Object *obj, bool topLevel) {
   Object obj2;
 
   if (obj->isArray()) {
@@ -426,13 +426,13 @@ void PdfParser::parse(Object *obj, GBool topLevel) {
 	error(errInternal, -1, "Weird page contents");
     	return;
   }
-  parser = new Parser(xref, new Lexer(xref, obj), gFalse);
+  parser = new _POPPLER_NEW_PARSER(xref, obj);
   go(topLevel);
   delete parser;
   parser = NULL;
 }
 
-void PdfParser::go(GBool /*topLevel*/)
+void PdfParser::go(bool /*topLevel*/)
 {
   Object obj;
   Object args[maxArgs];
@@ -620,7 +620,7 @@ PdfOperator* PdfParser::findOp(const char *name) {
   return &opTab[a];
 }
 
-GBool PdfParser::checkArg(Object *arg, TchkType type) {
+bool PdfParser::checkArg(Object *arg, TchkType type) {
   switch (type) {
   case tchkBool:   return arg->isBool();
   case tchkInt:    return arg->isInt();
@@ -630,9 +630,9 @@ GBool PdfParser::checkArg(Object *arg, TchkType type) 
   case tchkArray:  return arg->isArray();
   case tchkProps:  return arg->isDict() || arg->isName();
   case tchkSCN:    return arg->isNum() || arg->isName();
-  case tchkNone:   return gFalse;
+  case tchkNone:   return false;
   }
-  return gFalse;
+  return false;
 }
 
 int PdfParser::getPos() {
@@ -687,7 +687,7 @@ void PdfParser::opConcat(Object args[], int /*numArgs*
       builder->pushGroup();
       builder->setTransform(a0, a1, a2, a3, a4, a5);
   }
-  fontChanged = gTrue;
+  fontChanged = true;
 }
 
 // TODO not good that numArgs is ignored but args[] is used:
@@ -749,8 +749,8 @@ void PdfParser::opSetExtGState(Object args[], int /*nu
   Object obj1, obj2, obj3, obj4, obj5;
   Function *funcs[4] = {0, 0, 0, 0};
   GfxColor backdropColor;
-  GBool haveBackdropColor = gFalse;
-  GBool alpha = gFalse;
+  bool haveBackdropColor = false;
+  bool alpha = false;
 
   _POPPLER_CALL_ARGS(obj1, res->lookupGState, args[0].getName());
   if (obj1.isNull()) {
@@ -787,7 +787,7 @@ void PdfParser::opSetExtGState(Object args[], int /*nu
   _POPPLER_FREE(obj2);
 
   // fill/stroke overprint
-  GBool haveFillOP = gFalse;
+  bool haveFillOP = false;
   if ((haveFillOP = _POPPLER_CALL_ARGS_DEREF(obj2, obj1.dictLookup, "op").isBool())) {
     state->setFillOverprint(obj2.getBool());
   }
@@ -845,9 +845,9 @@ void PdfParser::opSetExtGState(Object args[], int /*nu
       builder->clearSoftMask(state);
     } else if (obj2.isDict()) {
       if (_POPPLER_CALL_ARGS_DEREF(obj3, obj2.dictLookup, "S").isName("Alpha")) {
-	alpha = gTrue;
+	alpha = true;
       } else { // "Luminosity"
-	alpha = gFalse;
+	alpha = false;
       }
       _POPPLER_FREE(obj3);
       funcs[0] = NULL;
@@ -877,8 +877,8 @@ void PdfParser::opSetExtGState(Object args[], int /*nu
       if (_POPPLER_CALL_ARGS_DEREF(obj3, obj2.dictLookup, "G").isStream()) {
 	if (_POPPLER_CALL_ARGS_DEREF(obj4, obj3.streamGetDict()->lookup, "Group").isDict()) {
 	  GfxColorSpace *blendingColorSpace = 0;
-	  GBool isolated = gFalse;
-	  GBool knockout = gFalse;
+	  bool isolated = false;
+	  bool knockout = false;
 	  if (!_POPPLER_CALL_ARGS_DEREF(obj5, obj4.dictLookup, "CS").isNull()) {
 #if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
 	    blendingColorSpace = GfxColorSpace::parse(NULL, &obj5, NULL, NULL);
@@ -929,9 +929,9 @@ void PdfParser::opSetExtGState(Object args[], int /*nu
   _POPPLER_FREE(obj1);
 }
 
-void PdfParser::doSoftMask(Object *str, GBool alpha,
+void PdfParser::doSoftMask(Object *str, bool alpha,
 		     GfxColorSpace *blendingColorSpace,
-		     GBool isolated, GBool knockout,
+		     bool isolated, bool knockout,
 		     Function *transferFunc, GfxColor *backdropColor) {
   Dict *dict, *resDict;
   double m[6], bbox[4];
@@ -988,7 +988,7 @@ void PdfParser::doSoftMask(Object *str, GBool alpha,
 
   // draw it
   ++formDepth;
-  doForm1(str, resDict, m, bbox, gTrue, gTrue,
+  doForm1(str, resDict, m, bbox, true, true,
 	  blendingColorSpace, isolated, knockout,
 	  alpha, transferFunc, backdropColor);
   --formDepth;
@@ -1444,7 +1444,7 @@ void PdfParser::opFill(Object /*args*/[], int /*numArg
   if (state->isPath()) {
     if (state->getFillColorSpace()->getMode() == csPattern &&
         !builder->isPatternTypeSupported(state->getFillPattern())) {
-      doPatternFillFallback(gFalse);
+      doPatternFillFallback(false);
     } else {
       builder->addPath(state, true, false);
     }
@@ -1461,7 +1461,7 @@ void PdfParser::opEOFill(Object /*args*/[], int /*numA
   if (state->isPath()) {
     if (state->getFillColorSpace()->getMode() == csPattern &&
         !builder->isPatternTypeSupported(state->getFillPattern())) {
-      doPatternFillFallback(gTrue);
+      doPatternFillFallback(true);
     } else {
       builder->addPath(state, true, false, true);
     }
@@ -1476,7 +1476,7 @@ void PdfParser::opFillStroke(Object /*args*/[], int /*
     return;
   }
   if (state->isPath()) {
-    doFillAndStroke(gFalse);
+    doFillAndStroke(false);
   } else {
     builder->addPath(state, true, true);
   }
@@ -1491,7 +1491,7 @@ void PdfParser::opCloseFillStroke(Object /*args*/[], i
   }
   if (state->isPath()) {
     state->closePath();
-    doFillAndStroke(gFalse);
+    doFillAndStroke(false);
   }
   doEndPath();
 }
@@ -1503,7 +1503,7 @@ void PdfParser::opEOFillStroke(Object /*args*/[], int 
     return;
   }
   if (state->isPath()) {
-    doFillAndStroke(gTrue);
+    doFillAndStroke(true);
   }
   doEndPath();
 }
@@ -1516,20 +1516,20 @@ void PdfParser::opCloseEOFillStroke(Object /*args*/[],
   }
   if (state->isPath()) {
     state->closePath();
-    doFillAndStroke(gTrue);
+    doFillAndStroke(true);
   }
   doEndPath();
 }
 
-void PdfParser::doFillAndStroke(GBool eoFill) {
-    GBool fillOk = gTrue, strokeOk = gTrue;
+void PdfParser::doFillAndStroke(bool eoFill) {
+    bool fillOk = true, strokeOk = true;
     if (state->getFillColorSpace()->getMode() == csPattern &&
         !builder->isPatternTypeSupported(state->getFillPattern())) {
-        fillOk = gFalse;
+        fillOk = false;
     }
     if (state->getStrokeColorSpace()->getMode() == csPattern &&
         !builder->isPatternTypeSupported(state->getStrokePattern())) {
-        strokeOk = gFalse;
+        strokeOk = false;
     }
     if (fillOk && strokeOk) {
         builder->addPath(state, true, true, eoFill);
@@ -1539,7 +1539,7 @@ void PdfParser::doFillAndStroke(GBool eoFill) {
     }
 }
 
-void PdfParser::doPatternFillFallback(GBool eoFill) {
+void PdfParser::doPatternFillFallback(bool eoFill) {
   GfxPattern *pattern;
 
   if (!(pattern = state->getFillPattern())) {
@@ -1549,7 +1549,7 @@ void PdfParser::doPatternFillFallback(GBool eoFill) {
   case 1:
     break;
   case 2:
-    doShadingPatternFillFallback(static_cast<GfxShadingPattern *>(pattern), gFalse, eoFill);
+    doShadingPatternFillFallback(static_cast<GfxShadingPattern *>(pattern), false, eoFill);
     break;
   default:
     error(errUnimplemented, getPos(), "Unimplemented pattern type (%d) in fill",
@@ -1568,7 +1568,7 @@ void PdfParser::doPatternStrokeFallback() {
   case 1:
     break;
   case 2:
-    doShadingPatternFillFallback(static_cast<GfxShadingPattern *>(pattern), gTrue, gFalse);
+    doShadingPatternFillFallback(static_cast<GfxShadingPattern *>(pattern), true, false);
     break;
   default:
     error(errUnimplemented, getPos(), "Unimplemented pattern type ({0:d}) in stroke",
@@ -1578,7 +1578,7 @@ void PdfParser::doPatternStrokeFallback() {
 }
 
 void PdfParser::doShadingPatternFillFallback(GfxShadingPattern *sPat,
-                                             GBool stroke, GBool eoFill) {
+                                             bool stroke, bool eoFill) {
   GfxShading *shading;
   GfxPath *savedPath;
   const double *ctm, *btm, *ptm;
@@ -1692,7 +1692,7 @@ void PdfParser::opShFill(Object args[], int /*numArgs*
   double xTemp, yTemp;
   double gradientTransform[6];
   double *matrix = NULL;
-  GBool savedState = gFalse;
+  bool savedState = false;
 
 #if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
   if (!(shading = res->lookupShading(args[0].getName(), NULL, NULL))) {
@@ -1708,13 +1708,13 @@ void PdfParser::opShFill(Object args[], int /*numArgs*
   if (shading->getType() != 2 && shading->getType() != 3) {
     savedPath = state->getPath()->copy();
     saveState();
-    savedState = gTrue;
+    savedState = true;
   } else {  // get gradient transform if possible
       // check proper operator sequence
       // first there should be one W(*) and then one 'cm' somewhere before 'sh'
-      GBool seenClip, seenConcat;
+      bool seenClip, seenConcat;
       seenClip = (clipHistory->getClipPath() != NULL);
-      seenConcat = gFalse;
+      seenConcat = false;
       int i = 1;
       while (i <= maxOperatorHistoryDepth) {
         const char *opName = getPreviousOperator(i);
@@ -1722,7 +1722,7 @@ void PdfParser::opShFill(Object args[], int /*numArgs*
           if (seenConcat) {   // more than one 'cm'
             break;
           } else {
-            seenConcat = gTrue;
+            seenConcat = true;
           }
         }
         i++;
@@ -2177,7 +2177,7 @@ void PdfParser::opBeginText(Object /*args*/[], int /*n
   state->setTextMat(1, 0, 0, 1, 0, 0);
   state->textMoveTo(0, 0);
   builder->updateTextPosition(0.0, 0.0);
-  fontChanged = gTrue;
+  fontChanged = true;
   builder->beginTextObject(state);
 }
 
@@ -2205,7 +2205,7 @@ void PdfParser::opSetFont(Object args[], int /*numArgs
     // unsetting the font (drawing no text) is better than using the
     // previous one and drawing random glyphs from it
     state->setFont(NULL, args[1].getNum());
-    fontChanged = gTrue;
+    fontChanged = true;
     return;
   }
   if (printCommands) {
@@ -2218,7 +2218,7 @@ void PdfParser::opSetFont(Object args[], int /*numArgs
 
   font->incRefCnt();
   state->setFont(font, args[1].getNum());
-  fontChanged = gTrue;
+  fontChanged = true;
 }
 
 // TODO not good that numArgs is ignored but args[] is used:
@@ -2251,7 +2251,7 @@ void PdfParser::opSetHorizScaling(Object args[], int /
 {
   state->setHorizScaling(args[0].getNum());
   builder->updateTextMatrix(state);
-  fontChanged = gTrue;
+  fontChanged = true;
 }
 
 //------------------------------------------------------------------------
@@ -2291,7 +2291,7 @@ void PdfParser::opSetTextMatrix(Object args[], int /*n
   state->textMoveTo(0, 0);
   builder->updateTextMatrix(state);
   builder->updateTextPosition(0.0, 0.0);
-  fontChanged = gTrue;
+  fontChanged = true;
 }
 
 void PdfParser::opTextNextLine(Object /*args*/[], int /*numArgs*/)
@@ -2317,7 +2317,7 @@ void PdfParser::opShowText(Object args[], int /*numArg
   }
   if (fontChanged) {
     builder->updateFont(state);
-    fontChanged = gFalse;
+    fontChanged = false;
   }
   doShowText(args[0].getString());
 }
@@ -2334,7 +2334,7 @@ void PdfParser::opMoveShowText(Object args[], int /*nu
   }
   if (fontChanged) {
     builder->updateFont(state);
-    fontChanged = gFalse;
+    fontChanged = false;
   }
   tx = state->getLineX();
   ty = state->getLineY() - state->getLeading();
@@ -2355,7 +2355,7 @@ void PdfParser::opMoveSetShowText(Object args[], int /
   }
   if (fontChanged) {
     builder->updateFont(state);
-    fontChanged = gFalse;
+    fontChanged = false;
   }
   state->setWordSpace(args[0].getNum());
   state->setCharSpace(args[1].getNum());
@@ -2379,7 +2379,7 @@ void PdfParser::opShowSpaceText(Object args[], int /*n
   }
   if (fontChanged) {
     builder->updateFont(state);
-    fontChanged = gFalse;
+    fontChanged = false;
   }
   wMode = state->getFont()->getWMode();
   a = args[0].getArray();
@@ -2414,7 +2414,7 @@ void PdfParser::doShowText(GooString *s) {
   int wMode;
   double riseX, riseY;
   CharCode code;
-  Unicode *u = NULL;
+  const Unicode *u = NULL;
   double x, y, dx, dy, tdx, tdy;
   double originX, originY, tOriginX, tOriginY;
   double oldCTM[6], newCTM[6];
@@ -2487,7 +2487,7 @@ void PdfParser::doShowText(GooString *s) {
 	  pushResources(resDict);
 	}
 	if (charProc.isStream()) {
-	  //parse(&charProc, gFalse); // TODO: parse into SVG font
+	  //parse(&charProc, false); // TODO: parse into SVG font
 	} else {
 	  error(errSyntaxError, getPos(), "Missing or bad Type3 CharProc entry");
 	}
@@ -2537,7 +2537,7 @@ void PdfParser::doShowText(GooString *s) {
       originY *= state->getFontSize();
       state->textTransformDelta(originX, originY, &tOriginX, &tOriginY);
       builder->addChar(state, state->getCurX() + riseX, state->getCurY() + riseY,
-                       dx, dy, tOriginX, tOriginY, code, n, u, uLen);
+                       dx, dy, tOriginX, tOriginY, code, n, const_cast<Unicode*>(u), uLen);
       state->shift(tdx, tdy);
       p += n;
       len -= n;
@@ -2574,7 +2574,7 @@ void PdfParser::opXObject(Object args[], int /*numArgs
   _POPPLER_CALL_ARGS(obj2, obj1.streamGetDict()->lookup, "Subtype");
   if (obj2.isName(const_cast<char*>("Image"))) {
     _POPPLER_CALL_ARGS(refObj, res->lookupXObjectNF, name);
-    doImage(&refObj, obj1.getStream(), gFalse);
+    doImage(&refObj, obj1.getStream(), false);
     _POPPLER_FREE(refObj);
   } else if (obj2.isName(const_cast<char*>("Form"))) {
     doForm(&obj1);
@@ -2591,19 +2591,19 @@ void PdfParser::opXObject(Object args[], int /*numArgs
   _POPPLER_FREE(obj1);
 }
 
-void PdfParser::doImage(Object * /*ref*/, Stream *str, GBool inlineImg)
+void PdfParser::doImage(Object * /*ref*/, Stream *str, bool inlineImg)
 {
     Dict *dict;
     int width, height;
     int bits;
-    GBool interpolate;
+    bool interpolate;
     StreamColorSpaceMode csMode;
-    GBool mask;
-    GBool invert;
+    bool mask;
+    bool invert;
     Object maskObj, smaskObj;
-    GBool haveColorKeyMask, haveExplicitMask, haveSoftMask;
-    GBool maskInvert;
-    GBool maskInterpolate;
+    bool haveColorKeyMask, haveExplicitMask, haveSoftMask;
+    bool maskInvert;
+    bool maskInterpolate;
     Object obj1, obj2;
     
     // get info from the stream
@@ -2655,9 +2655,9 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
     if (obj1.isBool())
       interpolate = obj1.getBool();
     else
-      interpolate = gFalse;
+      interpolate = false;
     _POPPLER_FREE(obj1);
-    maskInterpolate = gFalse;
+    maskInterpolate = false;
 
     // image or mask?
     _POPPLER_CALL_ARGS(obj1, dict->lookup, "ImageMask");
@@ -2665,7 +2665,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
         _POPPLER_FREE(obj1);
         _POPPLER_CALL_ARGS(obj1, dict->lookup, "IM");
     }
-    mask = gFalse;
+    mask = false;
     if (obj1.isBool()) {
         mask = obj1.getBool();
     }
@@ -2697,7 +2697,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
         if (bits != 1) {
             goto err1;
         }
-        invert = gFalse;
+        invert = false;
         _POPPLER_CALL_ARGS(obj1, dict->lookup, "Decode");
         if (obj1.isNull()) {
             _POPPLER_FREE(obj1);
@@ -2706,7 +2706,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
         if (obj1.isArray()) {
             _POPPLER_CALL_ARGS(obj2, obj1.arrayGet, 0);
             if (obj2.isInt() && obj2.getInt() == 1) {
-                invert = gTrue;
+                invert = true;
             }
             _POPPLER_FREE(obj2);
         } else if (!obj1.isNull()) {
@@ -2773,11 +2773,11 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
         
         // get the mask
         int maskColors[2*gfxColorMaxComps];
-        haveColorKeyMask = haveExplicitMask = haveSoftMask = gFalse;
+        haveColorKeyMask = haveExplicitMask = haveSoftMask = false;
         Stream *maskStr = NULL;
         int maskWidth = 0;
         int maskHeight = 0;
-        maskInvert = gFalse;
+        maskInvert = false;
         GfxImageColorMap *maskColorMap = NULL;
         _POPPLER_CALL_ARGS(maskObj, dict->lookup, "Mask");
         _POPPLER_CALL_ARGS(smaskObj, dict->lookup, "SMask");
@@ -2827,7 +2827,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
 	    if (obj1.isBool())
 	      maskInterpolate = obj1.getBool();
 	    else
-	      maskInterpolate = gFalse;
+	      maskInterpolate = false;
 	    _POPPLER_FREE(obj1);
             _POPPLER_CALL_ARGS(obj1, maskDict->lookup, "ColorSpace");
             if (obj1.isNull()) {
@@ -2870,7 +2870,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
                 goto err1;
             }
             //~ handle the Matte entry
-            haveSoftMask = gTrue;
+            haveSoftMask = true;
         } else if (maskObj.isArray()) {
             // color key mask
             int i;
@@ -2879,7 +2879,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
                 maskColors[i] = obj1.getInt();
                 _POPPLER_FREE(obj1);
             }
-              haveColorKeyMask = gTrue;
+              haveColorKeyMask = true;
         } else if (maskObj.isStream()) {
             // explicit mask
             if (inlineImg) {
@@ -2924,9 +2924,9 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
 	    if (obj1.isBool())
 	      maskInterpolate = obj1.getBool();
 	    else
-	      maskInterpolate = gFalse;
+	      maskInterpolate = false;
 	    _POPPLER_FREE(obj1);
-            maskInvert = gFalse;
+            maskInvert = false;
             _POPPLER_CALL_ARGS(obj1, maskDict->lookup, "Decode");
             if (obj1.isNull()) {
                 _POPPLER_FREE(obj1);
@@ -2935,14 +2935,14 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
             if (obj1.isArray()) {
                 _POPPLER_CALL_ARGS(obj2, obj1.arrayGet, 0);
                 if (obj2.isInt() && obj2.getInt() == 1) {
-                    maskInvert = gTrue;
+                    maskInvert = true;
                 }
                 _POPPLER_FREE(obj2);
             } else if (!obj1.isNull()) {
                 goto err2;
             }
             _POPPLER_FREE(obj1);
-            haveExplicitMask = gTrue;
+            haveExplicitMask = true;
         }
         
         // draw it
@@ -2973,7 +2973,7 @@ void PdfParser::doImage(Object * /*ref*/, Stream *str,
 
 void PdfParser::doForm(Object *str) {
   Dict *dict;
-  GBool transpGroup, isolated, knockout;
+  bool transpGroup, isolated, knockout;
   GfxColorSpace *blendingColorSpace;
   Object matrixObj, bboxObj;
   double m[6], bbox[4];
@@ -3031,11 +3031,11 @@ void PdfParser::doForm(Object *str) {
   resDict = resObj.isDict() ? resObj.getDict() : (Dict *)NULL;
 
   // check for a transparency group
-  transpGroup = isolated = knockout = gFalse;
+  transpGroup = isolated = knockout = false;
   blendingColorSpace = NULL;
   if (_POPPLER_CALL_ARGS_DEREF(obj1, dict->lookup, "Group").isDict()) {
     if (_POPPLER_CALL_ARGS_DEREF(obj2, obj1.dictLookup, "S").isName("Transparency")) {
-      transpGroup = gTrue;
+      transpGroup = true;
       if (!_POPPLER_CALL_ARGS_DEREF(obj3, obj1.dictLookup, "CS").isNull()) {
 #if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
 	blendingColorSpace = GfxColorSpace::parse(NULL, &obj3, NULL, NULL);
@@ -3062,7 +3062,7 @@ void PdfParser::doForm(Object *str) {
   // draw it
   ++formDepth;
   doForm1(str, resDict, m, bbox,
-	  transpGroup, gFalse, blendingColorSpace, isolated, knockout);
+	  transpGroup, false, blendingColorSpace, isolated, knockout);
   --formDepth;
 
   if (blendingColorSpace) {
@@ -3072,10 +3072,10 @@ void PdfParser::doForm(Object *str) {
 }
 
 void PdfParser::doForm1(Object *str, Dict *resDict, double *matrix, double *bbox,
-		  GBool transpGroup, GBool softMask,
+		  bool transpGroup, bool softMask,
 		  GfxColorSpace *blendingColorSpace,
-		  GBool isolated, GBool knockout,
-		  GBool alpha, Function *transferFunc,
+		  bool isolated, bool knockout,
+		  bool alpha, Function *transferFunc,
 		  GfxColor *backdropColor) {
   Parser *oldParser;
   double oldBaseMatrix[6];
@@ -3136,7 +3136,7 @@ void PdfParser::doForm1(Object *str, Dict *resDict, do
   }
 
   // draw the form
-  parse(str, gFalse);
+  parse(str, false);
 
   // restore base matrix
   for (i = 0; i < 6; ++i) {
@@ -3176,7 +3176,7 @@ void PdfParser::opBeginImage(Object /*args*/[], int /*
 
   // display the image
   if (str) {
-    doImage(NULL, str, gTrue);
+    doImage(NULL, str, true);
   
     // skip 'EI' tag
     int c1 = str->getUndecodedStream()->getChar();
@@ -3228,10 +3228,10 @@ Stream *PdfParser::buildImageStream() {
 
   // make stream
 #if defined(POPPLER_NEW_OBJECT_API)
-  str = new EmbedStream(parser->getStream(), dict.copy(), gFalse, 0);
+  str = new EmbedStream(parser->getStream(), dict.copy(), false, 0);
   str = str->addFilters(dict.getDict());
 #else
-  str = new EmbedStream(parser->getStream(), &dict, gFalse, 0);
+  str = new EmbedStream(parser->getStream(), &dict, false, 0);
   str = str->addFilters(&dict);
 #endif
 
@@ -3379,7 +3379,7 @@ void PdfParser::setApproximationPrecision(int shadingT
 // ClipHistoryEntry
 //------------------------------------------------------------------------
 
-ClipHistoryEntry::ClipHistoryEntry(GfxPath *clipPathA, GfxClipType clipTypeA) :
+ClipHistoryEntry::ClipHistoryEntry(const GfxPath *clipPathA, GfxClipType clipTypeA) :
   saved(NULL),
   clipPath((clipPathA) ? clipPathA->copy() : NULL),
   clipType(clipTypeA)
@@ -3394,7 +3394,7 @@ ClipHistoryEntry::~ClipHistoryEntry()
     }
 }
 
-void ClipHistoryEntry::setClip(GfxPath *clipPathA, GfxClipType clipTypeA) {
+void ClipHistoryEntry::setClip(const GfxPath *clipPathA, GfxClipType clipTypeA) {
     // Free previous clip path
     if (clipPath) {
         delete clipPath;

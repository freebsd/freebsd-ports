--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2025-12-26 00:35:50 UTC
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -653,7 +653,11 @@ void PdfParser::opSetLineJoin(Object args[], int /*num
 void PdfParser::opSetLineJoin(Object args[], int /*numArgs*/)
 {
   builder->beforeStateChange(state);
+#if POPPLER_CHECK_VERSION(26,2,0)
+  state->setLineJoin((GfxState::LineJoinStyle) args[0].getInt());
+#else
   state->setLineJoin(args[0].getInt());
+#endif
   builder->updateStyle(state);
 }
 
@@ -661,7 +665,11 @@ void PdfParser::opSetLineCap(Object args[], int /*numA
 void PdfParser::opSetLineCap(Object args[], int /*numArgs*/)
 {
   builder->beforeStateChange(state);
+#if POPPLER_CHECK_VERSION(26,2,0)
+  state->setLineCap((GfxState::LineCapStyle) args[0].getInt());
+#else
   state->setLineCap(args[0].getInt());
+#endif
   builder->updateStyle(state);
 }
 
@@ -1565,7 +1573,13 @@ void PdfParser::doShadingPatternFillFallback(GfxShadin
 
   // restore graphics state
   restoreState();
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+  state->clearPath();
+  GfxPath *currPath = const_cast<GfxPath*>(state->getPath());
+  currPath->append(savedPath);
+#else
   state->setPath(savedPath);
+#endif
 }
 
 // TODO not good that numArgs is ignored but args[] is used:
@@ -1626,7 +1640,13 @@ void PdfParser::opShFill(Object args[], int /*numArgs*
   // restore graphics state
   if (savedState) {
     restoreState();
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+    state->clearPath();
+    GfxPath *currPath = const_cast<GfxPath*>(state->getPath());
+    currPath->append(savedPath);
+#else
     state->setPath(savedPath);
+#endif
   }
 }
 
@@ -2213,7 +2233,7 @@ void PdfParser::opShowSpaceText(Object args[], int /*n
 {
   Array *a = nullptr;
   Object obj;
-  int wMode = 0; // Writing mode (horizontal/vertical).
+  _POPPLER_WMODE wMode = _POPPLER_WMODE_HORIZONTAL; // Writing mode (horizontal/vertical).
 
   if (!state->getFont()) {
     error(errSyntaxError, getPos(), "No font in show/space");
@@ -2227,7 +2247,7 @@ void PdfParser::opShowSpaceText(Object args[], int /*n
     if (obj.isNum()) {
       // this uses the absolute value of the font size to match
       // Acrobat's behavior
-      if (wMode) {
+      if (wMode != _POPPLER_WMODE_HORIZONTAL) {
 	state->textShift(0, -obj.getNum() * 0.001 *
 			    fabs(state->getFontSize()));
       } else {
@@ -2248,15 +2268,11 @@ void PdfParser::opShowSpaceText(Object args[], int /*n
  * This adds a string from a PDF file that is contained in one command ('Tj', ''', '"')
  * or is one string in ShowSpacetext ('TJ').
  */
-#if POPPLER_CHECK_VERSION(0,64,0)
-void PdfParser::doShowText(const GooString *s) {
-#else
-void PdfParser::doShowText(GooString *s) {
-#endif
+void PdfParser::doShowText(const std::string &s) {
     auto font = state->getFont();
-    int wMode = font->getWMode(); // Vertical/Horizontal/Invalid
+    _POPPLER_WMODE wMode = font->getWMode(); // Vertical/Horizontal/Invalid
 
-    builder->beginString(state, get_goostring_length(*s));
+    builder->beginString(state, s.size());
 
     // handle a Type 3 char
     if (font->getType() == fontType3) {
@@ -2266,8 +2282,8 @@ void PdfParser::doShowText(GooString *s) {
     double riseX, riseY;
     state->textTransformDelta(0, state->getRise(), &riseX, &riseY);
 
-    auto p = s->getCString(); // char* or const char*
-    int len = get_goostring_length(*s);
+    auto p = s.c_str(); // char* or const char*
+    int len = s.size();
 
     while (len > 0) {
 
@@ -2289,7 +2305,7 @@ void PdfParser::doShowText(GooString *s) {
         auto ax = dx;
         auto ay = dy;
 
-        if (wMode != 0) {
+        if (wMode != _POPPLER_WMODE_HORIZONTAL) {
             // Vertical text (or invalid value).
             dy += state->getCharSpace();
             if (n == 1 && *p == ' ') {
@@ -2324,7 +2340,16 @@ void PdfParser::doShowText(GooString *s) {
     builder->endString(state);
 }
 
+#if POPPLER_CHECK_VERSION(0,64,0)
+void PdfParser::doShowText(const GooString *s) {
+#else
+void PdfParser::doShowText(GooString *s) {
+#endif
+    const std::string str = s->toStr();
+    doShowText(str);
+}
 
+
 //------------------------------------------------------------------------
 // XObject operators
 //------------------------------------------------------------------------
@@ -2931,7 +2956,11 @@ Stream *PdfParser::buildImageStream() {
 
   // build dictionary
 #if defined(POPPLER_NEW_OBJECT_API)
+#if POPPLER_CHECK_VERSION(26, 3, 0)
+  dict = Object(std::make_unique<Dict>(xref));
+#else
   dict = Object(new Dict(xref));
+#endif
 #else
   dict.initDict(xref);
 #endif
@@ -2964,7 +2993,11 @@ Stream *PdfParser::buildImageStream() {
   // make stream
 #if defined(POPPLER_NEW_OBJECT_API)
   str = new EmbedStream(parser->getStream(), dict.copy(), gFalse, 0);
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+  str = str->addFilters(std::unique_ptr<Stream>(str), dict.getDict()).release();
+#else
   str = str->addFilters(dict.getDict());
+#endif
 #else
   str = new EmbedStream(parser->getStream(), &dict, gFalse, 0);
   str = str->addFilters(&dict);
@@ -3137,10 +3170,17 @@ void PdfParser::loadOptionalContentLayers(Dict *resour
             auto visible = true;
             // Normally we'd use poppler optContentIsVisible, but these dict
             // objects don't retain their references so can't be used directly.
+#if POPPLER_CHECK_VERSION(26, 2, 0)
+                for (auto &[ref, ocg] : ocgs->getOCGs()) {
+                    if (ocg->getName()->toStr() == label)
+                        visible = ocg->getState() == OptionalContentGroup::On;
+                }
+#else
             for (auto &[ref, ocg] : ocgs->getOCGs()) {
                 if (ocg->getName()->cmp(label) == 0)
                     visible = ocg->getState() == OptionalContentGroup::On;
             }
+#endif
             builder->addOptionalGroup(dict->getKey(j), label, visible);
         }
     }

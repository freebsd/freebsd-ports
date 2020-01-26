--- src/extension/internal/pdfinput/pdf-parser.h.orig	2020-01-25 21:47:43 UTC
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -97,7 +97,7 @@ struct PdfOperator {
 struct OpHistoryEntry {
     const char *name;       // operator's name
     GfxState *state;        // saved state, NULL if none
-    GBool executed;         // whether the operator has been executed
+    bool executed;         // whether the operator has been executed
 
     OpHistoryEntry *next;   // next entry on stack
     unsigned depth;         // total number of entries descending from this
@@ -140,7 +140,7 @@ class PdfParser { (public)
   virtual ~PdfParser();
 
   // Interpret a stream or array of streams.
-  void parse(Object *obj, GBool topLevel = gTrue);
+  void parse(Object *obj, bool topLevel = true);
 
   // Save graphics state.
   void saveState();
@@ -158,12 +158,12 @@ class PdfParser { (public)
 
   XRef *xref;			// the xref table for this PDF file
   SvgBuilder *builder;          // SVG generator
-  GBool subPage;		// is this a sub-page object?
-  GBool printCommands;		// print the drawing commands (for debugging)
+  bool subPage;		// is this a sub-page object?
+  bool printCommands;		// print the drawing commands (for debugging)
   GfxResources *res;		// resource stack
 
   GfxState *state;		// current graphics state
-  GBool fontChanged;		// set if font or text matrix has changed
+  bool fontChanged;		// set if font or text matrix has changed
   GfxClipType clip;		// do a clip?
   int ignoreUndef;		// current BX/EX nesting level
   double baseMatrix[6];		// default matrix for most recent
@@ -187,10 +187,10 @@ class PdfParser { (public)
   OpHistoryEntry *popOperator();
   const char *getPreviousOperator(unsigned int look_back=1);    // returns the nth previous operator's name
 
-  void go(GBool topLevel);
+  void go(bool topLevel);
   void execOp(Object *cmd, Object args[], int numArgs);
   PdfOperator *findOp(const char *name);
-  GBool checkArg(Object *arg, TchkType type);
+  bool checkArg(Object *arg, TchkType type);
   int getPos();
 
   // graphics state operators
@@ -204,9 +204,9 @@ class PdfParser { (public)
   void opSetMiterLimit(Object args[], int numArgs);
   void opSetLineWidth(Object args[], int numArgs);
   void opSetExtGState(Object args[], int numArgs);
-  void doSoftMask(Object *str, GBool alpha,
+  void doSoftMask(Object *str, bool alpha,
 		  GfxColorSpace *blendingColorSpace,
-		  GBool isolated, GBool knockout,
+		  bool isolated, bool knockout,
 		  Function *transferFunc, GfxColor *backdropColor);
   void opSetRenderingIntent(Object args[], int numArgs);
 
@@ -243,11 +243,11 @@ class PdfParser { (public)
   void opCloseFillStroke(Object args[], int numArgs);
   void opEOFillStroke(Object args[], int numArgs);
   void opCloseEOFillStroke(Object args[], int numArgs);
-  void doFillAndStroke(GBool eoFill);
-  void doPatternFillFallback(GBool eoFill);
+  void doFillAndStroke(bool eoFill);
+  void doPatternFillFallback(bool eoFill);
   void doPatternStrokeFallback();
   void doShadingPatternFillFallback(GfxShadingPattern *sPat,
-                                    GBool stroke, GBool eoFill);
+                                    bool stroke, bool eoFill);
   void opShFill(Object args[], int numArgs);
   void doFunctionShFill(GfxFunctionShading *shading);
   void doFunctionShFill1(GfxFunctionShading *shading,
@@ -300,13 +300,13 @@ class PdfParser { (public)
 
   // XObject operators
   void opXObject(Object args[], int numArgs);
-  void doImage(Object *ref, Stream *str, GBool inlineImg);
+  void doImage(Object *ref, Stream *str, bool inlineImg);
   void doForm(Object *str);
   void doForm1(Object *str, Dict *resDict, double *matrix, double *bbox,
-	       GBool transpGroup = gFalse, GBool softMask = gFalse,
+	       bool transpGroup = false, bool softMask = false,
 	       GfxColorSpace *blendingColorSpace = NULL,
-	       GBool isolated = gFalse, GBool knockout = gFalse,
-	       GBool alpha = gFalse, Function *transferFunc = NULL,
+	       bool isolated = false, bool knockout = false,
+	       bool alpha = false, Function *transferFunc = NULL,
 	       GfxColor *backdropColor = NULL);
 
   // in-line image operators

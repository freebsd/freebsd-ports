--- filters/karbon/pdf/SvgOutputDev.h.orig	2018-01-26 09:24:44 UTC
+++ filters/karbon/pdf/SvgOutputDev.h
@@ -44,11 +44,11 @@ class SvgOutputDev : public OutputDev (public)
     explicit SvgOutputDev(const QString &fileName);
     virtual ~SvgOutputDev();
 
-    GBool isOk();
+    bool isOk();
 
-    virtual GBool upsideDown();
-    virtual GBool useDrawChar();
-    virtual GBool interpretType3Chars();
+    virtual bool upsideDown();
+    virtual bool useDrawChar();
+    virtual bool interpretType3Chars();
     virtual void startPage(int pageNum, GfxState *state, XRef *xref);
     virtual void endPage();
 
@@ -58,15 +58,15 @@ class SvgOutputDev : public OutputDev (public)
     virtual void eoFill(GfxState *state);
 
     // text
-    virtual void drawString(GfxState * state, GooString * s);
+    virtual void drawString(GfxState * state, const GooString * s);
 
     // images
     virtual void drawImage(GfxState *state, Object *ref, Stream *str,
                            int width, int height, GfxImageColorMap *colorMap,
-                           int *maskColors, GBool inlineImg);
+                           int *maskColors, bool inlineImg);
     virtual void drawImage(GfxState *state, Object *ref, Stream *str,
                            int width, int height, GfxImageColorMap *colorMap,
-                           GBool interpolate, int *maskColors, GBool inlineImg);
+                           bool interpolate, int *maskColors, bool inlineImg);
 
     // styles
     virtual void updateAll(GfxState *state);

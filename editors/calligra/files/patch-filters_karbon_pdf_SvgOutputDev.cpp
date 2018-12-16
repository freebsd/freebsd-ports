--- filters/karbon/pdf/SvgOutputDev.cpp.orig	2018-01-26 09:24:44 UTC
+++ filters/karbon/pdf/SvgOutputDev.cpp
@@ -39,7 +39,7 @@ class SvgOutputDev::Private
 {
 public:
     Private(const QString &fname)
-            : svgFile(fname), defs(0), body(0), state(gTrue)
+            : svgFile(fname), defs(0), body(0), state(true)
             , brush(Qt::SolidPattern) {}
 
     ~Private() {
@@ -52,7 +52,7 @@ class SvgOutputDev::Private
     QString defsData;
     QTextStream * defs;
     QTextStream * body;
-    GBool state;
+    bool state;
     QSizeF pageSize;
     QPen pen;
     QBrush brush;
@@ -62,7 +62,7 @@ SvgOutputDev::SvgOutputDev(const QString &fileName)
         : d(new Private(fileName))
 {
     if (! d->svgFile.open(QIODevice::WriteOnly)) {
-        d->state = gFalse;
+        d->state = false;
         return;
     }
 
@@ -75,24 +75,24 @@ SvgOutputDev::~SvgOutputDev()
     delete d;
 }
 
-GBool SvgOutputDev::isOk()
+bool SvgOutputDev::isOk()
 {
     return d->state;
 }
 
-GBool SvgOutputDev::upsideDown()
+bool SvgOutputDev::upsideDown()
 {
-    return gTrue;
+    return true;
 }
 
-GBool SvgOutputDev::useDrawChar()
+bool SvgOutputDev::useDrawChar()
 {
-    return gFalse;
+    return false;
 }
 
-GBool SvgOutputDev::interpretType3Chars()
+bool SvgOutputDev::interpretType3Chars()
 {
-    return gFalse;
+    return false;
 }
 
 void SvgOutputDev::startPage(int pageNum, GfxState *state, XRef */*xref*/)
@@ -143,7 +143,9 @@ void SvgOutputDev::stroke(GfxState * state)
 {
     QString path = convertPath(state->getPath());
     *d->body << "<path";
-    *d->body << " transform=\"" << convertMatrix(state->getCTM()) << "\"";
+    const double * ctm = state->getCTM();
+    QMatrix transform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
+    *d->body << " transform=\"" << convertMatrix(transform) << "\"";
     *d->body << printStroke();
     *d->body << " fill=\"none\"";
     *d->body << " d=\"" << path << "\"";
@@ -154,7 +156,9 @@ void SvgOutputDev::fill(GfxState * state)
 {
     QString path = convertPath(state->getPath());
     *d->body << "<path";
-    *d->body << " transform=\"" << convertMatrix(state->getCTM()) << "\"";
+    const double * ctm = state->getCTM();
+    QMatrix transform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
+    *d->body << " transform=\"" << convertMatrix(transform) << "\"";
     *d->body << printFill();
     *d->body << " fill-rule=\"nonzero\"";
     *d->body << " d=\"" << path << "\"";
@@ -165,7 +169,9 @@ void SvgOutputDev::eoFill(GfxState *state)
 {
     QString path = convertPath(state->getPath());
     *d->body << "<path";
-    *d->body << " transform=\"" << convertMatrix(state->getCTM()) << "\"";
+    const double * ctm = state->getCTM();
+    QMatrix transform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
+    *d->body << " transform=\"" << convertMatrix(transform) << "\"";
     *d->body << printFill();
     *d->body << " fill-rule=\"evenodd\"";
     *d->body << " d=\"" << path << "\"";
@@ -387,7 +393,7 @@ QString SvgOutputDev::printStroke()
     return stroke;
 }
 
-void SvgOutputDev::drawString(GfxState * state, GooString * s)
+void SvgOutputDev::drawString(GfxState * state, const GooString * s)
 {
     int render = state->getRender();
     // check for invisible text -- this is used by Acrobat Capture
@@ -402,7 +408,7 @@ void SvgOutputDev::drawString(GfxState * state, GooStr
 
     QString str;
 
-    char * p = s->getCString();
+    const char * p = s->c_str();
     int len = s->getLength();
     CharCode code;
     Unicode *u = nullptr;
@@ -429,7 +435,7 @@ void SvgOutputDev::drawString(GfxState * state, GooStr
     double x = state->getCurX();
     double y = state->getCurY();
 
-    double * ctm = state->getCTM();
+    const double * ctm = state->getCTM();
     QMatrix transform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 
     QMatrix mirror;
@@ -451,11 +457,11 @@ void SvgOutputDev::drawString(GfxState * state, GooStr
     *d->body << " y=\"" << y << "px\"";
 
     if (font && font->getFamily()) {
-        *d->body << " font-family=\"" << QString::fromLatin1(font->getFamily()->getCString()) << "\"";
-        //debugPdf << "font family:" << QString::fromLatin1( font->getFamily()->getCString() );
+        *d->body << " font-family=\"" << QString::fromLatin1(font->getFamily()->c_str()) << "\"";
+        //debugPdf << "font family:" << QString::fromLatin1( font->getFamily()->c_str() );
     } else if (font && font->getName()) {
-        *d->body << " font-family=\"" << QString::fromLatin1(font->getName()->getCString()) << "\"";
-        //debugPdf << "font name:" << QString::fromLatin1( font->getName()->getCString() );
+        *d->body << " font-family=\"" << QString::fromLatin1(font->getName()->c_str()) << "\"";
+        //debugPdf << "font name:" << QString::fromLatin1( font->getName()->c_str() );
     }
     *d->body << " font-size=\"" << qMax(state->getFontSize(), state->getTransformedFontSize()) << "px\"";
 
@@ -476,7 +482,7 @@ void SvgOutputDev::drawString(GfxState * state, GooStr
 
 void SvgOutputDev::drawImage(GfxState *state, Object */*ref*/, Stream *str,
                              int width, int height, GfxImageColorMap *colorMap,
-                             int *maskColors, GBool /*inlineImg*/)
+                             int *maskColors, bool /*inlineImg*/)
 {
     ImageStream * imgStr = new ImageStream(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
     imgStr->reset();
@@ -522,7 +528,7 @@ void SvgOutputDev::drawImage(GfxState *state, Object *
         return;
     }
 
-    double * ctm = state->getCTM();
+    const double * ctm = state->getCTM();
     QMatrix m;
     m.setMatrix(ctm[0] / width, ctm[1] / width, -ctm[2] / height, -ctm[3] / height, ctm[2] + ctm[4], ctm[3] + ctm[5]);
 
@@ -531,7 +537,9 @@ void SvgOutputDev::drawImage(GfxState *state, Object *
     device.open(QIODevice::WriteOnly);
     if (image->save(&device, "PNG")) {
         *d->body << "<image";
-        *d->body << " transform=\"" << convertMatrix(m) << "\"";
+        const double * ctm = state->getCTM();
+        QMatrix transform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
+        *d->body << " transform=\"" << convertMatrix(transform) << "\"";
         *d->body << " width=\"" << width << "px\"";
         *d->body << " height=\"" << height << "px\"";
         *d->body << " xlink:href=\"data:image/png;base64," << ba.toBase64() <<  "\"";
@@ -545,7 +553,7 @@ void SvgOutputDev::drawImage(GfxState *state, Object *
 
 void SvgOutputDev::drawImage(GfxState *state, Object *ref, Stream *str,
                              int width, int height, GfxImageColorMap *colorMap,
-                             GBool /*interpolate*/, int *maskColors, GBool inlineImg)
+                             bool /*interpolate*/, int *maskColors, bool inlineImg)
 {
     drawImage(state, ref, str, width, height, colorMap, maskColors, inlineImg);
 }

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2019-10-27 20:00:15.887122000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp	2019-10-27 20:02:37.972576000 +0000
@@ -2414,7 +2414,7 @@
   int wMode;
   double riseX, riseY;
   CharCode code;
-  Unicode *u = NULL;
+  const Unicode *u = NULL;
   double x, y, dx, dy, tdx, tdy;
   double originX, originY, tOriginX, tOriginY;
   double oldCTM[6], newCTM[6];
@@ -2537,7 +2537,7 @@
       originY *= state->getFontSize();
       state->textTransformDelta(originX, originY, &tOriginX, &tOriginY);
       builder->addChar(state, state->getCurX() + riseX, state->getCurY() + riseY,
-                       dx, dy, tOriginX, tOriginY, code, n, u, uLen);
+                       dx, dy, tOriginX, tOriginY, code, n, const_cast<Unicode*>(u), uLen);
       state->shift(tdx, tdy);
       p += n;
       len -= n;

--- vcl/skia/gdiimpl.cxx.orig	2022-01-26 14:35:29 UTC
+++ vcl/skia/gdiimpl.cxx
@@ -999,7 +999,7 @@ void SkiaSalGraphicsImpl::performDrawPolyPolygon(const
         getDrawCanvas()->drawPath(polygonPath, aPaint);
     }
     postDraw();
-#if defined LINUX
+#if defined LINUX || defined FREEBSD
     // WORKAROUND: The logo in the about dialog has drawing errors. This seems to happen
     // only on Linux (not Windows on the same machine), with both AMDGPU and Mesa,
     // and only when antialiasing is enabled. Flushing seems to avoid the problem.

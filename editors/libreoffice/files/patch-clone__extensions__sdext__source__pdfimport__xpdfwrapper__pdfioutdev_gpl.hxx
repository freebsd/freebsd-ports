--- clone/extensions/sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2011-05-19 09:14:21.000000000 +0000
+++ clone/extensions/sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx	2011-10-29 20:19:33.000000000 +0000
@@ -65,7 +65,10 @@ class GfxPath;
 class GfxFont;
 class PDFDoc;
 #ifndef SYSTEM_POPPLER
+#define POPPLER_CHECK_VERSION(major,minor,micro) (0)
 typedef GString GooString;
+#else
+#include <glib/poppler-features.h>
 #endif
 
 namespace pdfi
@@ -195,7 +198,7 @@ namespace pdfi
         // virtual void cvtUserToDev(double ux, double uy, int *dx, int *dy);
         
         //----- link borders
-        virtual void processLink(Link *link, Catalog *catalog);
+        virtual void processLink(AnnotLink *link, Catalog *catalog);
         
         //----- save/restore graphics state
         virtual void saveState(GfxState *state);

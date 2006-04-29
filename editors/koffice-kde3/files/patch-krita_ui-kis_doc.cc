--- krita/ui/kis_doc.cc	2006/03/24 09:22:37	522034
+++ krita/ui/kis_doc.cc	2006/04/06 17:18:18	527039
@@ -844,7 +844,7 @@
 KisImageSP KisDoc::newImage(const QString& name, Q_INT32 width, Q_INT32 height, KisColorSpace * colorstrategy)
 {
     if (!init())
-        return false;
+        return 0;
 
     setUndo(false);
 

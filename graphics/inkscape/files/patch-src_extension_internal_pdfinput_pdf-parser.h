--- src/extension/internal/pdfinput/pdf-parser.h.orig	2025-12-26 00:35:50 UTC
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -283,10 +283,11 @@ class PdfParser { (private)
     void opMoveShowText(Object args[], int numArgs);
     void opMoveSetShowText(Object args[], int numArgs);
     void opShowSpaceText(Object args[], int numArgs);
+    void doShowText(const std::string &s);
 #if POPPLER_CHECK_VERSION(0,64,0)
-  void doShowText(const GooString *s);
+    void doShowText(const GooString *s);
 #else
-  void doShowText(GooString *s);
+    void doShowText(GooString *s);
 #endif
   
 

Fix incompatible pointer assignment for GMPathBox in GMFileSelector.

GMFileSelector previously relied on FXFileSelector::dirbox (FXDirBox*).
Explicitly declare dirbox as GMPathBox* when FOXVERSION >= 1.7.87 to match
the GMPathBox instantiation.

--- src/GMImportDialog.cpp.orig	2026-07-27 00:47:06 UTC
+++ src/GMImportDialog.cpp
@@ -182,6 +182,9 @@ FXDECLARE(GMFileSelector) (protected)
 FXDECLARE(GMFileSelector)
 protected:
   GMFileAssociations * fileassoc = nullptr;
+#if FOXVERSION >= FXVERSION(1, 7, 87)
+  GMPathBox * dirbox = nullptr;
+#endif
 protected:
   GMFileSelector(){}
 private:

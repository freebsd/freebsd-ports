--- ../sw/source/filter/ww8/ww8scan.cxx.orig	Wed Sep  3 04:12:28 2003
+++ ../sw/source/filter/ww8/ww8scan.cxx	Wed Sep  3 04:12:49 2003
@@ -163,7 +163,7 @@
     {
         ASSERT(mnNoElems && pWwSprmTab, "WW8: empty Array: Don't do that");
         std::sort(mpWwSprmTab, mpWwSprmTab + mnNoElems);
-#if OSL_DEBUG_LEVEL > 1
+#if OSL_DEBUG_LEVEL > 10 // XXX pass compilation with WITH_DEBUG=2
         bool bBroken=false;
         rtl::OUString sError;
         const C *pIter = mpWwSprmTab;

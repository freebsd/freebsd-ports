--- src/Mod/Part/App/ProgressIndicator.cpp.orig	2020-11-14 19:54:58 UTC
+++ src/Mod/Part/App/ProgressIndicator.cpp
@@ -54,6 +54,7 @@ using namespace Part;
   \endcode
  */
 
+#if OCC_VERSION_HEX < 0x070500
 ProgressIndicator::ProgressIndicator (int theMaxVal)
   : myProgress(new Base::SequencerLauncher("", theMaxVal))
 {
@@ -83,3 +84,4 @@ Standard_Boolean ProgressIndicator::UserBreak()
 {
     return myProgress->wasCanceled();
 }
+#endif

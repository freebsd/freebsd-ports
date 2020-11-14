--- src/Mod/Part/App/ProgressIndicator.h.orig	2020-11-14 19:56:01 UTC
+++ src/Mod/Part/App/ProgressIndicator.h
@@ -25,11 +25,13 @@
 #define PART_PROGRESSINDICATOR_H
 
 #include <Message_ProgressIndicator.hxx>
+#include <Standard_Version.hxx>
 #include <Base/Sequencer.h>
 #include <memory>
 
 namespace Part {
 
+#if OCC_VERSION_HEX < 0x070500
 class PartExport ProgressIndicator : public Message_ProgressIndicator
 {
 public:
@@ -42,6 +44,7 @@ class PartExport ProgressIndicator : public Message_Pr
 private:
     std::unique_ptr<Base::SequencerLauncher> myProgress;
 };
+#endif
 
 }
 

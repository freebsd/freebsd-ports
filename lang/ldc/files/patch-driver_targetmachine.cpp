--- driver/targetmachine.cpp.orig	2022-07-20 17:05:27 UTC
+++ driver/targetmachine.cpp
@@ -431,6 +431,10 @@ createTargetMachine(const std::string targetTriple, co
       // these OSes.
       // On Android, PIC is default as well.
       relocModel = llvm::Reloc::PIC_;
+    } else if (triple.isOSFreeBSD()) {
+      // We default to PIC code to avoid linking issues on FreeBSD, especially
+      // on aarch64.
+      relocModel = llvm::Reloc::PIC_;
     } else {
       // ARM for other than Darwin or Android defaults to static
       switch (triple.getArch()) {

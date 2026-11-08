--- src/ispc.cpp.orig	2026-06-25 04:07:31 UTC
+++ src/ispc.cpp
@@ -2775,6 +2775,8 @@ llvm::Triple Target::GetTriple() const {
             triple.setArchName("armv8a");
         } else if (m_arch == Arch::aarch64) {
             triple.setArchName("aarch64");
+        } else if (m_arch == Arch::ppc64le) {
+            triple.setArchName("ppc64le");
         } else {
             Error(SourcePos(), "Unknown arch.");
             exit(1);

--- src/ispc.cpp.orig	2021-07-15 23:04:31 UTC
+++ src/ispc.cpp
@@ -1464,10 +1464,22 @@ std::string Target::GetTripleString() const {
             triple.setArchName("armv7");
         } else if (m_arch == Arch::aarch64) {
             triple.setArchName("aarch64");
+        } else if (m_arch == Arch::genx32) {
+            triple.setArchName("spir");
+        } else if (m_arch == Arch::genx64) {
+            triple.setArchName("spir64");
         } else {
             Error(SourcePos(), "Unknown arch.");
             exit(1);
         }
+#ifdef ISPC_GENX_ENABLED
+        if (m_arch == Arch::genx32 || m_arch == Arch::genx64) {
+            //"spir64-unknown-unknown"
+            triple.setVendor(llvm::Triple::VendorType::UnknownVendor);
+            triple.setOS(llvm::Triple::OSType::UnknownOS);
+            return triple.str();
+        }
+#endif
         triple.setVendor(llvm::Triple::VendorType::UnknownVendor);
         triple.setOS(llvm::Triple::OSType::FreeBSD);
         break;

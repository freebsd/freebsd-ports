--- lib/libimhex/include/hex/helpers/patches.hpp.orig	2023-02-13 15:24:10 UTC
+++ lib/libimhex/include/hex/helpers/patches.hpp
@@ -4,7 +4,7 @@
 
 #include <map>
 #include <vector>
-#include <expected>
+#include <tl/expected.hpp>
 
 namespace hex {
 
@@ -18,9 +18,9 @@ namespace hex {
         MissingEOF
     };
 
-    std::expected<std::vector<u8>, IPSError> generateIPSPatch(const Patches &patches);
-    std::expected<std::vector<u8>, IPSError> generateIPS32Patch(const Patches &patches);
+    tl::expected<std::vector<u8>, IPSError> generateIPSPatch(const Patches &patches);
+    tl::expected<std::vector<u8>, IPSError> generateIPS32Patch(const Patches &patches);
 
-    std::expected<Patches, IPSError> loadIPSPatch(const std::vector<u8> &ipsPatch);
-    std::expected<Patches, IPSError> loadIPS32Patch(const std::vector<u8> &ipsPatch);
+    tl::expected<Patches, IPSError> loadIPSPatch(const std::vector<u8> &ipsPatch);
+    tl::expected<Patches, IPSError> loadIPS32Patch(const std::vector<u8> &ipsPatch);
 }
\ No newline at end of file

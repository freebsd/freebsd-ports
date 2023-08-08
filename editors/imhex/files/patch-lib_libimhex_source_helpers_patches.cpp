--- lib/libimhex/source/helpers/patches.cpp.orig	2023-02-13 15:36:19 UTC
+++ lib/libimhex/source/helpers/patches.cpp
@@ -18,7 +18,7 @@ namespace hex {
         std::memcpy((&buffer.back() - sizeof(T)) + 1, &bytes, sizeof(T));
     }
 
-    std::expected<std::vector<u8>, IPSError> generateIPSPatch(const Patches &patches) {
+    tl::expected<std::vector<u8>, IPSError> generateIPSPatch(const Patches &patches) {
         std::vector<u8> result;
 
         pushStringBack(result, "PATCH");
@@ -43,9 +43,9 @@ namespace hex {
                 bytes.push_back(values[i]);
 
                 if (bytes.size() > 0xFFFF)
-                    return std::unexpected(IPSError::PatchTooLarge);
+                    return tl::unexpected(IPSError::PatchTooLarge);
                 if (startAddress > 0xFFFF'FFFF)
-                    return std::unexpected(IPSError::AddressOutOfRange);
+                    return tl::unexpected(IPSError::AddressOutOfRange);
 
                 u32 address       = startAddress.value();
                 auto addressBytes = reinterpret_cast<u8 *>(&address);
@@ -68,7 +68,7 @@ namespace hex {
         return result;
     }
 
-    std::expected<std::vector<u8>, IPSError> generateIPS32Patch(const Patches &patches) {
+    tl::expected<std::vector<u8>, IPSError> generateIPS32Patch(const Patches &patches) {
         std::vector<u8> result;
 
         pushStringBack(result, "IPS32");
@@ -93,9 +93,9 @@ namespace hex {
                 bytes.push_back(values[i]);
 
                 if (bytes.size() > 0xFFFF)
-                    return std::unexpected(IPSError::PatchTooLarge);
+                    return tl::unexpected(IPSError::PatchTooLarge);
                 if (startAddress > 0xFFFF'FFFF)
-                    return std::unexpected(IPSError::AddressOutOfRange);
+                    return tl::unexpected(IPSError::AddressOutOfRange);
 
                 u32 address       = startAddress.value();
                 auto addressBytes = reinterpret_cast<u8 *>(&address);
@@ -119,12 +119,12 @@ namespace hex {
         return result;
     }
 
-    std::expected<Patches, IPSError> loadIPSPatch(const std::vector<u8> &ipsPatch) {
+    tl::expected<Patches, IPSError> loadIPSPatch(const std::vector<u8> &ipsPatch) {
         if (ipsPatch.size() < (5 + 3))
-            return std::unexpected(IPSError::InvalidPatchHeader);
+            return tl::unexpected(IPSError::InvalidPatchHeader);
 
         if (std::memcmp(ipsPatch.data(), "PATCH", 5) != 0)
-            return std::unexpected(IPSError::InvalidPatchHeader);
+            return tl::unexpected(IPSError::InvalidPatchHeader);
 
         Patches result;
         bool foundEOF = false;
@@ -139,7 +139,7 @@ namespace hex {
             // Handle normal record
             if (size > 0x0000) {
                 if (ipsOffset + size > ipsPatch.size() - 3)
-                    return std::unexpected(IPSError::InvalidPatchFormat);
+                    return tl::unexpected(IPSError::InvalidPatchFormat);
 
                 for (u16 i = 0; i < size; i++)
                     result[offset + i] = ipsPatch[ipsOffset + i];
@@ -148,7 +148,7 @@ namespace hex {
             // Handle RLE record
             else {
                 if (ipsOffset + 3 > ipsPatch.size() - 3)
-                    return std::unexpected(IPSError::InvalidPatchFormat);
+                    return tl::unexpected(IPSError::InvalidPatchFormat);
 
                 u16 rleSize = ipsPatch[ipsOffset + 0] | (ipsPatch[ipsOffset + 1] << 8);
 
@@ -167,15 +167,15 @@ namespace hex {
         if (foundEOF)
             return result;
         else
-            return std::unexpected(IPSError::MissingEOF);
+            return tl::unexpected(IPSError::MissingEOF);
     }
 
-    std::expected<Patches, IPSError> loadIPS32Patch(const std::vector<u8> &ipsPatch) {
+    tl::expected<Patches, IPSError> loadIPS32Patch(const std::vector<u8> &ipsPatch) {
         if (ipsPatch.size() < (5 + 4))
-            return std::unexpected(IPSError::InvalidPatchHeader);
+            return tl::unexpected(IPSError::InvalidPatchHeader);
 
         if (std::memcmp(ipsPatch.data(), "IPS32", 5) != 0)
-            return std::unexpected(IPSError::InvalidPatchHeader);
+            return tl::unexpected(IPSError::InvalidPatchHeader);
 
         Patches result;
         bool foundEEOF = false;
@@ -190,7 +190,7 @@ namespace hex {
             // Handle normal record
             if (size > 0x0000) {
                 if (ipsOffset + size > ipsPatch.size() - 3)
-                    return std::unexpected(IPSError::InvalidPatchFormat);
+                    return tl::unexpected(IPSError::InvalidPatchFormat);
 
                 for (u16 i = 0; i < size; i++)
                     result[offset + i] = ipsPatch[ipsOffset + i];
@@ -199,7 +199,7 @@ namespace hex {
             // Handle RLE record
             else {
                 if (ipsOffset + 3 > ipsPatch.size() - 3)
-                    return std::unexpected(IPSError::InvalidPatchFormat);
+                    return tl::unexpected(IPSError::InvalidPatchFormat);
 
                 u16 rleSize = ipsPatch[ipsOffset + 0] | (ipsPatch[ipsOffset + 1] << 8);
 
@@ -218,7 +218,7 @@ namespace hex {
         if (foundEEOF)
             return result;
         else
-            return std::unexpected(IPSError::MissingEOF);
+            return tl::unexpected(IPSError::MissingEOF);
     }
 
 }
\ No newline at end of file

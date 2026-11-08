--- lib/SPIRV/libSPIRV/SPIRVModule.cpp.orig	2026-09-02 08:46:07 UTC
+++ lib/SPIRV/libSPIRV/SPIRVModule.cpp
@@ -2112,8 +2112,8 @@ bool isSpirvBinary(const std::string &Img) {
 bool isSpirvBinary(const std::string &Img) {
   if (Img.size() < sizeof(unsigned))
     return false;
-  auto Magic = reinterpret_cast<const unsigned *>(Img.data());
-  return *Magic == MagicNumber;
+  std::istringstream IS(Img);
+  return readSPIRVWord(IS) == MagicNumber;
 }
 
 #ifdef _SPIRV_SUPPORT_TEXT_FMT

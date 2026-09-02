--- lib/SPIRV/libSPIRV/SPIRVModule.cpp.orig	2026-09-02 08:54:13 UTC
+++ lib/SPIRV/libSPIRV/SPIRVModule.cpp
@@ -2584,7 +2584,8 @@ std::istream &SPIRVModuleImpl::parseSPIRV(std::istream
   MI.setAutoAddExtensions(false);
 
   SPIRVWord Header[5] = {0};
-  I.read(reinterpret_cast<char *>(&Header), sizeof(Header));
+  for (auto &H : Header)
+    H = readSPIRVWord(I);
 
   SPIRVErrorLog &ErrorLog = MI.getErrorLog();
   if (!ErrorLog.checkError(!I.eof(), SPIRVEC_InvalidModule,
@@ -2621,8 +2622,7 @@ std::istream &SPIRVModuleImpl::parseSPIRV(std::istream
 
   SPIRVEntry *Scope = nullptr;
   while (true) {
-    SPIRVWord WordCountAndOpCode = 0;
-    I.read(reinterpret_cast<char *>(&WordCountAndOpCode), sizeof(SPIRVWord));
+    SPIRVWord WordCountAndOpCode = readSPIRVWord(I);
     SPIRVDBG(spvdbgs() << "Read word: W = " << WordCountAndOpCode
                        << " V = 0\n");
     SPIRVWord WordCount = WordCountAndOpCode >> 16;
@@ -2745,8 +2745,8 @@ bool isSpirvBinary(const std::string &Img) {
 bool isSpirvBinary(const std::string &Img) {
   if (Img.size() < sizeof(unsigned))
     return false;
-  const auto *Magic = reinterpret_cast<const unsigned *>(Img.data());
-  return *Magic == MagicNumber;
+  std::istringstream IS(Img);
+  return readSPIRVWord(IS) == MagicNumber;
 }
 
 #ifdef _SPIRV_SUPPORT_TEXT_FMT

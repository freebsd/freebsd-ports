--- src/Controller/Src/Filter/Saving.hpp.orig	2024-09-12 07:10:36 UTC
+++ src/Controller/Src/Filter/Saving.hpp
@@ -107,7 +107,7 @@ namespace epsonscan
      if (imgFormat == kSDIImageFormatRaw)
      {
          file = CESFile::CreateTempFileInstanceWithPrefix(ES_CMN_FUNCS::PATH::ES_GetWorkTempPath(), prefixStream.str(), CESFile::ES_OPEN_MODE_WRITE_PLUS);
-      if(file->WriteData(inDataBuf) == false)
+      if(!file || file->WriteData(inDataBuf) == false)
       {
        delete file;
        file = nullptr;

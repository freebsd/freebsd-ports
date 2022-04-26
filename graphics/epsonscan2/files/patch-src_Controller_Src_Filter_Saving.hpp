--- src/Controller/Src/Filter/Saving.hpp.orig	2022-03-20 15:38:28 UTC
+++ src/Controller/Src/Filter/Saving.hpp
@@ -76,8 +76,7 @@ namespace epsonscan
        imgFormat = kSDIImageFormatPNM;
       }
       file = CESFile::CreateTempFileInstanceWithPrefix(ES_CMN_FUNCS::PATH::ES_GetWorkTempPath(), prefixStream.str());
-      file->CloseFile();
-      if(ffMgr.Write(inDataBuf,
+      if(!file || ffMgr.Write(inDataBuf,
           file->GetFileName(),
           imgFormat,
           imageInfo,
@@ -91,6 +90,7 @@ namespace epsonscan
       }
      }
      filePath_ = file->GetFileName();
+     file->CloseFile();
      delete file;
      file = nullptr;
             }

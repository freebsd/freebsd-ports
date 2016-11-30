Fix for CVE-2016-9296.

Obtained from: https://sourceforge.net/p/p7zip/bugs/185/
Security: 48e83187-b6e9-11e6-b6cf-5453ed2e2b49
--- CPP/7zip/Archive/7z/7zIn.cpp.orig	2016-11-30 09:35:06 UTC
+++ CPP/7zip/Archive/7z/7zIn.cpp
@@ -1091,7 +1091,8 @@ HRESULT CInArchive::ReadAndDecodePackedS
       if (CrcCalc(data, unpackSize) != folders.FolderCRCs.Vals[i])
         ThrowIncorrect();
   }
-  HeadersSize += folders.PackPositions[folders.NumPackStreams];
+  if (folders.PackPositions)
+    HeadersSize += folders.PackPositions[folders.NumPackStreams];
   return S_OK;
 }
 

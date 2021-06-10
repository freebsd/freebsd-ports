--- frmts/pdf/pdfobject.cpp.orig	2021-04-27 09:12:27 UTC
+++ frmts/pdf/pdfobject.cpp
@@ -1082,7 +1082,7 @@ const CPLString& GDALPDFObjectPoppler::GetString()
         return (osStr = GDALPDFGetUTF8StringFromBytes(reinterpret_cast<const GByte*>(gooString->c_str()),
                                                       static_cast<int>(gooString->getLength())));
 #else
-        return (osStr = GDALPDFGetUTF8StringFromBytes(reinterpret_cast<const GByte*>(gooString->getCString()),
+        return (osStr = GDALPDFGetUTF8StringFromBytes(reinterpret_cast<const GByte*>(gooString->c_str()),
                                                       static_cast<int>(gooString->getLength())));
 #endif
     }
@@ -1442,7 +1442,7 @@ static char* GooStringToCharStart(GooString& gstr)
 #if (POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 72)
             const char* srcStr = gstr.c_str();
 #else
-            const char* srcStr = gstr.getCString();
+            const char* srcStr = gstr.c_str();
 #endif
             memcpy(pszContent, srcStr, nLength);
             pszContent[nLength] = '\0';

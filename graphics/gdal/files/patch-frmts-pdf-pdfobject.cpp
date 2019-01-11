--- frmts/pdf/pdfobject.cpp.orig	2018-12-14 21:37:15 UTC
+++ frmts/pdf/pdfobject.cpp
@@ -1061,7 +1061,7 @@ const CPLString& GDALPDFObjectPoppler::G
 #else
         GooString* gooString = m_po->getString();
 #endif
-        return (osStr = GDALPDFGetUTF8StringFromBytes(reinterpret_cast<const GByte*>(gooString->getCString()),
+        return (osStr = GDALPDFGetUTF8StringFromBytes(reinterpret_cast<const GByte*>(gooString->c_str()),
                                                       static_cast<int>(gooString->getLength())));
     }
     else
@@ -1422,7 +1422,7 @@ char* GDALPDFStreamPoppler::GetBytes()
         char* pszContent = (char*) VSIMalloc(m_nLength + 1);
         if (pszContent)
         {
-            memcpy(pszContent, gstr->getCString(), m_nLength);
+            memcpy(pszContent, gstr->c_str(), m_nLength);
             pszContent[m_nLength] = '\0';
         }
         delete gstr;

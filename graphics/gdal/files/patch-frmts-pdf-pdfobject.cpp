Obtained from:	https://github.com/OSGeo/gdal/commit/783addc36d7da7a3f0c15fd46dde117e0ec0bb87

--- frmts/pdf/pdfobject.cpp.orig	2019-03-15 12:33:01 UTC
+++ frmts/pdf/pdfobject.cpp
@@ -1195,7 +1195,7 @@ GDALPDFObject* GDALPDFDictionaryPoppler:
         return oIter->second;
 
 #if POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 58
-    Object o = m_poDict->lookupNF(((char*)pszKey));
+    auto&& o(m_poDict->lookupNF(((char*)pszKey)));
     if (!o.isNull())
     {
         int nRefNum = 0;
@@ -1204,7 +1204,7 @@ GDALPDFObject* GDALPDFDictionaryPoppler:
         {
             nRefNum = o.getRefNum();
             nRefGen = o.getRefGen();
-            Object o2 = m_poDict->lookup((char*)pszKey);
+            Object o2(m_poDict->lookup((char*)pszKey));
             if( !o2.isNull() )
             {
                 GDALPDFObjectPoppler* poObj = new GDALPDFObjectPoppler(new Object(std::move(o2)), TRUE);
@@ -1215,7 +1215,7 @@ GDALPDFObject* GDALPDFDictionaryPoppler:
         }
         else
         {
-            GDALPDFObjectPoppler* poObj = new GDALPDFObjectPoppler(new Object(std::move(o)), TRUE);
+            GDALPDFObjectPoppler* poObj = new GDALPDFObjectPoppler(new Object(std::move(o.copy())), TRUE);
             poObj->SetRefNumAndGen(nRefNum, nRefGen);
             m_map[pszKey] = poObj;
             return poObj;
@@ -1329,7 +1329,7 @@ GDALPDFObject* GDALPDFArrayPoppler::Get(
         return m_v[nIndex];
 
 #if POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 58
-    Object o = m_poArray->getNF(nIndex);
+    auto&& o(m_poArray->getNF(nIndex));
     if( !o.isNull() )
     {
         int nRefNum = 0;
@@ -1338,7 +1338,7 @@ GDALPDFObject* GDALPDFArrayPoppler::Get(
         {
             nRefNum = o.getRefNum();
             nRefGen = o.getRefGen();
-            Object o2 = m_poArray->get(nIndex);
+            Object o2(m_poArray->get(nIndex));
             if( !o2.isNull() )
             {
                 GDALPDFObjectPoppler* poObj = new GDALPDFObjectPoppler(new Object(std::move(o2)), TRUE);
@@ -1349,7 +1349,7 @@ GDALPDFObject* GDALPDFArrayPoppler::Get(
         }
         else
         {
-            GDALPDFObjectPoppler* poObj = new GDALPDFObjectPoppler(new Object(std::move(o)), TRUE);
+            GDALPDFObjectPoppler* poObj = new GDALPDFObjectPoppler(new Object(std::move(o.copy())), TRUE);
             poObj->SetRefNumAndGen(nRefNum, nRefGen);
             m_v[nIndex] = poObj;
             return poObj;
@@ -1416,8 +1416,6 @@ int GDALPDFStreamPoppler::GetLength()
 
 char* GDALPDFStreamPoppler::GetBytes()
 {
-    /* fillGooString() available in poppler >= 0.16.0 */
-#ifdef POPPLER_BASE_STREAM_HAS_TWO_ARGS
     GooString* gstr = new GooString();
     m_poStream->fillGooString(gstr);
 
@@ -1427,7 +1425,12 @@ char* GDALPDFStreamPoppler::GetBytes()
         char* pszContent = (char*) VSIMalloc(m_nLength + 1);
         if (pszContent)
         {
-            memcpy(pszContent, gstr->getCString(), m_nLength);
+#if (POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 72)
+            const char* srcStr = gstr->c_str();
+#else
+            const char* srcStr = gstr->getCString();
+#endif
+            memcpy(pszContent, srcStr, m_nLength);
             pszContent[m_nLength] = '\0';
         }
         delete gstr;
@@ -1438,41 +1441,6 @@ char* GDALPDFStreamPoppler::GetBytes()
         delete gstr;
         return nullptr;
     }
-#else
-    int i;
-    int nLengthAlloc = 0;
-    char* pszContent = nullptr;
-    if( m_nLength >= 0 )
-    {
-        pszContent = (char*) VSIMalloc(m_nLength + 1);
-        if (!pszContent)
-            return nullptr;
-        nLengthAlloc = m_nLength;
-    }
-    m_poStream->reset();
-    for(i = 0; ; ++i )
-    {
-        int nVal = m_poStream->getChar();
-        if (nVal == EOF)
-            break;
-        if( i >= nLengthAlloc )
-        {
-            nLengthAlloc = 32 + nLengthAlloc + nLengthAlloc / 3;
-            char* pszContentNew = (char*) VSIRealloc(pszContent, nLengthAlloc + 1);
-            if( pszContentNew == nullptr )
-            {
-                CPLFree(pszContent);
-                m_nLength = 0;
-                return nullptr;
-            }
-            pszContent = pszContentNew;
-        }
-        pszContent[i] = (GByte)nVal;
-    }
-    m_nLength = i;
-    pszContent[i] = '\0';
-    return pszContent;
-#endif
 }
 
 #endif // HAVE_POPPLER

src/xmlParser/xmlParser.cpp:743:27: error: cast from pointer to smaller type 'char' loses information
        lpszNew[cbData] = (TCHAR)NULL;

--- src/xmlParser/xmlParser.cpp.orig	2018-01-17 09:27:41 UTC
+++ src/xmlParser/xmlParser.cpp
@@ -740,7 +740,7 @@ LPTSTR stringDup(LPCTSTR lpszData, int cbData)
     if (lpszNew)
     {
         memcpy(lpszNew, lpszData, (cbData) * sizeof(TCHAR));
-        lpszNew[cbData] = (TCHAR)NULL;
+        lpszNew[cbData] = 0;
     }
     return lpszNew;
 }

Fix build with clang6.
src/xmlParser.cpp:676:27: error: cast from pointer to smaller type 'char' loses information
        lpszNew[cbData] = (XMLCHAR)NULL;
                          ^~~~~~~~~~~~~

--- src/xmlParser.cpp.orig	2018-01-20 21:39:55 UTC
+++ src/xmlParser.cpp
@@ -673,7 +673,7 @@ XMLSTR stringDup(XMLCSTR lpszData, int cbData)
     if (lpszNew)
     {
         memcpy(lpszNew, lpszData, (cbData) * sizeof(XMLCHAR));
-        lpszNew[cbData] = (XMLCHAR)NULL;
+        lpszNew[cbData] = 0;
     }
     return lpszNew;
 }

--- ui/zinf/src/Headlines.cpp.orig	2003-09-16 17:35:32 UTC
+++ ui/zinf/src/Headlines.cpp
@@ -215,7 +215,7 @@ Error Headlines::PCData(string &oData)
 
 Error Headlines::EndElement(string &oElement)
 {
-    char *pPtr;
+    const char *pPtr;
     int   iOffset;
 
     pPtr = strrchr(m_oPath.c_str(), '/');

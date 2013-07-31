--- IccLibXML/IccUtilXml.cpp.orig	2013-07-31 15:27:36.570207432 +0400
+++ IccLibXML/IccUtilXml.cpp	2013-07-31 15:28:45.056197105 +0400
@@ -685,7 +685,7 @@ CIccXmlArrayType<T, Tsig>::~CIccXmlArray
 template <class T, icTagTypeSignature Tsig>
 bool CIccXmlArrayType<T, Tsig>::ParseArray(xmlNode *pNode)
 {
-  char *scanType = (Tsig == icSigFloatArrayType ? "f" : "n");
+  char *scanType = (char *)(Tsig == icSigFloatArrayType ? "f" : "n");
   icUInt32Number n = icXmlNodeCount(pNode, scanType);
   
   if (n) {

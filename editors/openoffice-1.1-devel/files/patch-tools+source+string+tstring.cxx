--- ../tools/source/string/tstring.cxx.orig	Thu Mar 27 18:04:53 2003
+++ ../tools/source/string/tstring.cxx	Sat May 31 23:04:05 2003
@@ -103,6 +103,9 @@
 xub_StrLen ImplStringLen( const sal_Char* pStr )
 {
 	const sal_Char* pTempStr = pStr;
+
+	if (pStr == NULL)
+		return(0);
 	while( *pTempStr )
 		++pTempStr;
 	return (xub_StrLen)(pTempStr-pStr);
@@ -113,6 +116,9 @@
 xub_StrLen ImplStringLen( const sal_Unicode* pStr )
 {
 	const sal_Unicode* pTempStr = pStr;
+
+	if (pStr == NULL)
+		return(0);
 	while( *pTempStr )
 		++pTempStr;
 	return (xub_StrLen)(pTempStr-pStr);

--- ../tools/source/string/tstring.cxx.orig	Sat Aug 10 12:53:42 2002
+++ ../tools/source/string/tstring.cxx	Sat Aug 10 12:54:16 2002
@@ -103,6 +103,9 @@
 xub_StrLen ImplStringLen( const sal_Char* pStr )
 {
 	const sal_Char* pTempStr = pStr;
+
+	if (pStr == NULL)
+		return(0);
 	while( *pTempStr )
 		pTempStr++;
 	return (xub_StrLen)(pTempStr-pStr);
@@ -113,6 +116,9 @@
 xub_StrLen ImplStringLen( const sal_Unicode* pStr )
 {
 	const sal_Unicode* pTempStr = pStr;
+
+	if (pStr == NULL)
+		return(0);
 	while( *pTempStr )
 		pTempStr++;
 	return (xub_StrLen)(pTempStr-pStr);

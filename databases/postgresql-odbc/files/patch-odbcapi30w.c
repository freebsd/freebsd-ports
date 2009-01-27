--- odbcapi30w.c.orig	2009-01-26 23:23:19.000000000 +0600
+++ odbcapi30w.c	2009-01-26 23:24:07.000000000 +0600
@@ -255,7 +255,7 @@
 	SQLPOINTER	pCharAttr,
 	SQLSMALLINT	cbCharAttrMax,	
 	SQLSMALLINT	*pcbCharAttr,
-#if defined(WITH_UNIXODBC) || (defined(WIN32) && ! defined(_WIN64))
+#if defined(WIN32)
 	SQLPOINTER	pNumAttr
 #else
 	SQLLEN		*pNumAttr

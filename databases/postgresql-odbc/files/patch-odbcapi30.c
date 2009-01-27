--- odbcapi30.c.orig	2009-01-26 23:20:59.000000000 +0600
+++ odbcapi30.c	2009-01-26 23:21:47.000000000 +0600
@@ -118,9 +118,7 @@
 			SQLPOINTER CharacterAttribute,
 			SQLSMALLINT BufferLength,
 			SQLSMALLINT *StringLength,
-#if defined(_WIN64)
-			SQLLEN *NumericAttribute
-#elif defined(WITH_UNIXODBC) || defined(WIN32)
+#if defined(WIN32)
 			SQLPOINTER NumericAttribute
 #else
 			SQLLEN *NumericAttribute

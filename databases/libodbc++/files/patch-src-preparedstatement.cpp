--- src/preparedstatement.cpp.orig	Sun Nov 12 13:28:34 2006
+++ src/preparedstatement.cpp	Sun Nov 12 13:30:27 2006
@@ -161,7 +161,7 @@
   numParams_=np;
   
   SQLSMALLINT sqlType;
-  SQLUINTEGER prec;
+  SQLULEN prec;
   SQLSMALLINT scale;
   SQLSMALLINT nullable;
 

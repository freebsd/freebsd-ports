--- info.c.orig	Thu Sep 20 02:04:08 2001
+++ info.c	Tue Feb  5 10:57:03 2002
@@ -171,11 +171,13 @@
     *pcbInfoValue=(SQLSMALLINT) (strmake((char*) rgbInfoValue,"Y",cbInfoValueMax)
 			   - (char*) rgbInfoValue);
     break;
+#if (ODBCVER < 0x0300)
 #ifdef SQL_MAX_IDENTIFIER_LEN
   case SQL_MAX_IDENTIFIER_LEN:
     *((SQLUSMALLINT*) rgbInfoValue)=NAME_LEN;
     break;
 #endif
+#endif
   case SQL_CONCAT_NULL_BEHAVIOR:
     *((SQLSMALLINT*) rgbInfoValue)=SQL_CB_NULL;
     *pcbInfoValue=sizeof(SQLSMALLINT);
@@ -188,7 +190,7 @@
 #ifdef SQL_CURSOR_SENSITIVITY
   case SQL_CURSOR_SENSITIVITY:
     *((SQLUINTEGER*) rgbInfoValue)=SQL_UNSPECIFIED;
-    break
+    break;
 #endif
   case SQL_DEFAULT_TXN_ISOLATION:
     *((long*) rgbInfoValue)= DEFAULT_TXN_ISOLATION;
@@ -411,7 +413,7 @@
     *pcbInfoValue=sizeof(long);
     break;
 #if (ODBCVER >= 0x0300)
-  case SQL_MAX_IDENTIFIER_LENGTH:
+  case SQL_MAX_IDENTIFIER_LEN:
     *((long*) rgbInfoValue)=NAME_LEN;
     *pcbInfoValue=sizeof(long);
     break;

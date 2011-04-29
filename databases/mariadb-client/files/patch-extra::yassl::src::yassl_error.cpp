--- extra/yassl/src/yassl_error.cpp     2010-04-28 12:52:24 +0000
+++ extra/yassl/src/yassl_error.cpp     2011-03-01 17:03:38 +0000
@@ -128,7 +128,7 @@
         break;

     case badVersion_error :
-        strncpy(buffer, "protocl version mismatch", max);
+        strncpy(buffer, "protocol version mismatch", max);
         break;

     case compress_error :



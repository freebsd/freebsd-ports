--- extra/yassl/src/yassl_error.cpp.orig	2011-03-01 22:22:55.000000000 -0800
+++ extra/yassl/src/yassl_error.cpp	2011-05-31 16:50:56.000000000 -0700
@@ -128,7 +128,7 @@
         break;
 
     case badVersion_error :
-        strncpy(buffer, "protocl version mismatch", max);
+        strncpy(buffer, "protocol version mismatch", max);
         break;
         
     case compress_error :

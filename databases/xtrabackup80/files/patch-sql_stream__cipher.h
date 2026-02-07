--- sql/stream_cipher.h.orig	2023-11-24 10:33:10 UTC
+++ sql/stream_cipher.h
@@ -25,7 +25,7 @@
 
 #include <openssl/evp.h>
 #include <memory>
-#include <string>
+#include <vector>
 
 /**
   @file stream_cipher.h
@@ -34,7 +34,7 @@
          binary log files.
 */
 
-typedef std::basic_string<unsigned char> Key_string;
+typedef std::vector<unsigned char> Key_string;
 
 /**
   @class Stream_cipher

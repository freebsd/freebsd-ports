--- sql/stream_cipher.h.orig	2024-07-12 19:15:25 UTC
+++ sql/stream_cipher.h
@@ -27,6 +27,7 @@
 #include <openssl/evp.h>
 #include <memory>
 #include <string>
+#include <vector>
 
 /**
   @file stream_cipher.h
@@ -35,7 +36,7 @@
          binary log files.
 */
 
-typedef std::basic_string<unsigned char> Key_string;
+typedef std::vector<unsigned char> Key_string;
 
 /**
   @class Stream_cipher

--- sql/stream_cipher.h.orig	2025-08-19 10:33:36 UTC
+++ sql/stream_cipher.h
@@ -27,6 +27,7 @@
 #include <openssl/evp.h>
 #include <memory>
 #include <string>
+#include <vector>
 
 #include "my_char_traits.h"
 
@@ -38,7 +39,7 @@ using Key_string =
 */
 
 using Key_string =
-    std::basic_string<unsigned char, my_char_traits<unsigned char>>;
+    std::vector<unsigned char>;
 
 /**
   @class Stream_cipher

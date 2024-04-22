--- vendor/adb/tls/include/adb/tls/tls_connection.h.orig	2024-02-11 15:40:31 UTC
+++ vendor/adb/tls/include/adb/tls/tls_connection.h
@@ -21,6 +21,7 @@
 
 #include <string_view>
 #include <vector>
+#include <functional>
 
 #include <android-base/unique_fd.h>
 #include <openssl/ssl.h>

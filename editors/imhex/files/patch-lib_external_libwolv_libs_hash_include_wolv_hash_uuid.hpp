--- lib/external/libwolv/libs/hash/include/wolv/hash/uuid.hpp.orig	2023-06-24 12:12:43 UTC
+++ lib/external/libwolv/libs/hash/include/wolv/hash/uuid.hpp
@@ -11,15 +11,15 @@ namespace wolv::hash {
         std::random_device randomDevice;
         std::mt19937 generator(randomDevice());
 
-        std::uniform_int_distribution<char> distribution(0, 15);
+        std::uniform_int_distribution<int> distribution(0, 15);
 
         std::string uuid = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";
         for (char &c : uuid) {
             if (c == 'x') {
-                c = distribution(generator);
+                c = static_cast<char>(distribution(generator));
                 c = c < 10 ? char('0' + c) : char('a' + c - 10);
             } else if (c == 'y') {
-                c = distribution(generator);
+                c = static_cast<char>(distribution(generator));
                 c = char(char(c & u8(0x03)) | char(0x08));
                 c = c < 10 ? char('0' + c) : char('a' + c - 10);
             }

--- ext/bifrost/src/strict_fstream.hpp.orig	2024-07-23 11:27:57 UTC
+++ ext/bifrost/src/strict_fstream.hpp
@@ -64,7 +64,7 @@ static std::string strerror()
     } else {
         return "Unknown error (" + std::to_string(err_num) + ")";
     }
-#elif ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE) || defined(__APPLE__) || defined(__MUSL__)
+#elif ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE) || defined(__APPLE__) || defined(__MUSL__) || defined(__FreeBSD__)
 // XSI-compliant strerror_r()
     const int err_num = errno; // See above
     if (strerror_r(err_num, buff.data(), buff.size()) == 0) {

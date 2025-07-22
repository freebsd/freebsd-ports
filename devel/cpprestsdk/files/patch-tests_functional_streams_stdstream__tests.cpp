--- tests/functional/streams/stdstream_tests.cpp.orig	2023-12-05 04:23:31 UTC
+++ tests/functional/streams/stdstream_tests.cpp
@@ -13,6 +13,7 @@
 #include "cpprest/filestream.h"
 #include "cpprest/producerconsumerstream.h"
 #include "cpprest/rawptrstream.h"
+#include "cpprest/details/char_traits.h"
 
 #if (!defined(_WIN32) || !defined(CPPREST_EXCLUDE_WEBSOCKETS)) && !defined(__cplusplus_winrt)
 #include <boost/interprocess/streams/bufferstream.hpp>
@@ -303,7 +304,8 @@ SUITE(stdstreambuf_tests)
 
         const std::streamsize iterations = 100;
 
-        const std::string the_alphabet("abcdefghijklmnopqrstuvwxyz");
+        const char *the_alphabet_characters = "abcdefghijklmnopqrstuvwxyz";
+        const std::basic_string<uint8_t,typename utility::CanUseStdCharTraits<uint8_t>::TraitsType> the_alphabet(reinterpret_cast<const uint8_t *>(the_alphabet_characters));
 
         auto writer = pplx::create_task([ostream, iterations, the_alphabet]() {
             auto os = ostream;
@@ -341,7 +343,8 @@ SUITE(stdstreambuf_tests)
 
         const std::streamsize iterations = 100;
 
-        const std::string the_alphabet("abcdefghijklmnopqrstuvwxyz");
+        const char *the_alphabet_chars = "abcdefghijklmnopqrstuvwxyz";
+        const std::basic_string<uint8_t,typename CanUseStdCharTraits<uint8_t>::TraitsType> the_alphabet(reinterpret_cast<const uint8_t *>(the_alphabet_chars));
 
         auto writer = pplx::create_task([ostream, iterations, the_alphabet]() {
             auto os = ostream;

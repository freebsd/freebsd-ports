--- include/cpprest/streams.h.orig	2023-12-05 04:23:31 UTC
+++ include/cpprest/streams.h
@@ -16,6 +16,7 @@
 #define CASA_STREAMS_H
 
 #include "cpprest/astreambuf.h"
+#include "cpprest/details/char_traits.h"
 #include <iosfwd>
 #include <cstdio>
 
@@ -60,31 +61,96 @@ class basic_istream_helper (private)
     concurrency::streams::streambuf<CharType> m_buffer;
 };
 
-template<typename CharType>
+template<typename CharType, class Traits = typename utility::CanUseStdCharTraits<CharType>::TraitsType>
 struct Value2StringFormatter
 {
+    struct SanitizeInput
+    {
+        const std::basic_string<char> &operator () (const std::basic_string<char> &input)
+        {
+            return input;
+        }
+        template <class InputTraits> std::basic_string<char> operator () (const std::basic_string<unsigned char, InputTraits> &input)
+        {
+            return {reinterpret_cast<const char *>(input.c_str()), input.size()};
+        }
+        const char *operator () (const char *input) {
+            return input;
+        }
+        const char *operator () (const unsigned char *input)
+        {
+            return reinterpret_cast<const char *>(input);
+        }
+        template <class T> T operator () (T input)
+        {
+            return input;
+        }
+    };
+    struct GenerateFormatOutput
+    {
+        std::basic_string<CharType,Traits> &&operator() (std::basic_string<CharType,Traits> &&result)
+        {
+            return std::move(result);
+        }
+        std::basic_string<CharType,Traits> operator() (const std::basic_string<char> &intermediate)
+        {
+            return {reinterpret_cast<const CharType *>(intermediate.c_str()), intermediate.size()};
+        }
+    };
     template<typename T>
-    static std::basic_string<CharType> format(const T& val)
+    static std::basic_string<CharType, Traits> format(const T& val)
     {
-        std::basic_ostringstream<CharType> ss;
-        ss << val;
-        return ss.str();
+        typename std::conditional<
+            sizeof(CharType) == 1,
+            std::basic_ostringstream<char>,
+            std::basic_ostringstream<typename std::make_signed<CharType>::type>
+        >::type ss;
+        SanitizeInput sanitizer;
+        ss << sanitizer(val);
+        typename std::conditional<
+            sizeof(CharType) == 1,
+            std::basic_string<char>,
+            std::basic_string<typename std::make_signed<CharType>::type>
+        >::type str = ss.str();
+        GenerateFormatOutput generateFormatOutput;
+        return generateFormatOutput(std::move(str));
     }
 };
 
-template<>
-struct Value2StringFormatter<uint8_t>
+template<class Traits, typename T>
+struct Value2StringFormatterUint8Format
 {
-    template<typename T>
-    static std::basic_string<uint8_t> format(const T& val)
+    std::basic_string<uint8_t, Traits> operator () (const T& val)
     {
         std::basic_ostringstream<char> ss;
         ss << val;
         return reinterpret_cast<const uint8_t*>(ss.str().c_str());
     }
+};
 
-    static std::basic_string<uint8_t> format(const utf16string& val)
+template <class Traits>
+struct Value2StringFormatterUint8Format<Traits, std::basic_string<uint8_t,Traits>>
+{
+    std::basic_string<uint8_t, Traits> operator () (
+        const std::basic_string<uint8_t, typename utility::CanUseStdCharTraits<uint8_t>::TraitsType>& val)
     {
+        Value2StringFormatterUint8Format<Traits,std::basic_string<char>> format;
+        return format(reinterpret_cast<const std::basic_string<char>&>(val));
+    }
+};
+
+template<>
+struct Value2StringFormatter<uint8_t>
+{
+    template <typename T, class Traits = typename utility::CanUseStdCharTraits<uint8_t>::TraitsType>
+    static std::basic_string<uint8_t, Traits> format(const T& val)
+    {
+        Value2StringFormatterUint8Format<Traits, T> format;
+        return format(val);
+    }
+
+    static std::basic_string<uint8_t, typename utility::CanUseStdCharTraits<uint8_t>::TraitsType> format(const utf16string& val)
+    {
         return format(utility::conversions::utf16_to_utf8(val));
     }
 };
@@ -262,7 +328,7 @@ class basic_ostream (public)
     /// Write the specified string to the output stream.
     /// </summary>
     /// <param name="str">Input string.</param>
-    pplx::task<size_t> print(const std::basic_string<CharType>& str) const
+    pplx::task<size_t> print(const std::basic_string<CharType,traits>& str) const
     {
         pplx::task<size_t> result;
         if (!_verify_and_return_task(details::_out_stream_msg, result)) return result;
@@ -273,7 +339,7 @@ class basic_ostream (public)
         }
         else
         {
-            auto sharedStr = std::make_shared<std::basic_string<CharType>>(str);
+            auto sharedStr = std::make_shared<std::basic_string<CharType,traits>>(str);
             return helper()->m_buffer.putn_nocopy(sharedStr->c_str(), sharedStr->size()).then([sharedStr](size_t size) {
                 return size;
             });
@@ -294,7 +360,7 @@ class basic_ostream (public)
         if (!_verify_and_return_task(details::_out_stream_msg, result)) return result;
         // TODO in the future this could be improved to have Value2StringFormatter avoid another unnecessary copy
         // by putting the string on the heap before calling the print string overload.
-        return print(details::Value2StringFormatter<CharType>::format(val));
+        return print(details::Value2StringFormatter<CharType, traits>::format(val));
     }
 
     /// <summary>

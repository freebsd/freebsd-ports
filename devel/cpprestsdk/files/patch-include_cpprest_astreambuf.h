--- include/cpprest/astreambuf.h.orig	2023-12-05 04:23:31 UTC
+++ include/cpprest/astreambuf.h
@@ -15,6 +15,7 @@
 
 #include "cpprest/asyncrt_utils.h"
 #include "cpprest/details/basic_types.h"
+#include "cpprest/details/char_traits.h"
 #include "pplx/pplxtasks.h"
 #include <atomic>
 #include <cstring>
@@ -56,55 +57,28 @@ namespace streams
 /// <typeparam name="_CharType">
 /// The data type of the basic element of the stream.
 /// </typeparam>
+namespace detail
+{
 template<typename _CharType>
-struct char_traits : std::char_traits<_CharType>
+struct char_traits : utility::CanUseStdCharTraits<_CharType>::TraitsType
 {
     /// <summary>
     /// Some synchronous functions will return this value if the operation
     /// requires an asynchronous call in a given situation.
     /// </summary>
     /// <returns>An <c>int_type</c> value which implies that an asynchronous call is required.</returns>
-    static typename std::char_traits<_CharType>::int_type requires_async()
+    static typename utility::CanUseStdCharTraits<_CharType>::TraitsType::int_type requires_async()
     {
-        return std::char_traits<_CharType>::eof() - 1;
+        return utility::CanUseStdCharTraits<_CharType>::TraitsType::eof() - 1;
     }
 };
+}
+template<typename _CharType> struct char_traits : detail::char_traits<_CharType> {
+};
 #if !defined(_WIN32)
-template<>
-struct char_traits<unsigned char> : private std::char_traits<char>
-{
-public:
-    typedef unsigned char char_type;
-
-    using std::char_traits<char>::eof;
-    using std::char_traits<char>::int_type;
-    using std::char_traits<char>::off_type;
-    using std::char_traits<char>::pos_type;
-
-    static size_t length(const unsigned char* str)
-    {
-        return std::char_traits<char>::length(reinterpret_cast<const char*>(str));
-    }
-
-    static void assign(unsigned char& left, const unsigned char& right) { left = right; }
-    static unsigned char* assign(unsigned char* left, size_t n, unsigned char value)
-    {
-        return reinterpret_cast<unsigned char*>(
-            std::char_traits<char>::assign(reinterpret_cast<char*>(left), n, static_cast<char>(value)));
-    }
-
-    static unsigned char* copy(unsigned char* left, const unsigned char* right, size_t n)
-    {
-        return reinterpret_cast<unsigned char*>(
-            std::char_traits<char>::copy(reinterpret_cast<char*>(left), reinterpret_cast<const char*>(right), n));
-    }
-
-    static unsigned char* move(unsigned char* left, const unsigned char* right, size_t n)
-    {
-        return reinterpret_cast<unsigned char*>(
-            std::char_traits<char>::move(reinterpret_cast<char*>(left), reinterpret_cast<const char*>(right), n));
-    }
-
+template <> struct char_traits<unsigned char> : detail::char_traits<unsigned char> {
+    typedef typename std::char_traits<char>::int_type int_type;
+    static int_type eof() { return std::char_traits<char>::eof(); }
     static int_type requires_async() { return eof() - 1; }
 };
 #endif

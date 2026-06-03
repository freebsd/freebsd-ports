--- platform.h.orig	2024-12-04 12:34:01.000000000 -0800
+++ platform.h	2026-03-09 21:09:29.579167000 -0700
@@ -11,7 +11,7 @@
 // http://predef.sourceforge.net/prearch.html , these ought to work on
 // gcc, Sun Studio and Visual Studio.
 // Throw in ia64 as well, though I doubt anyone will play EL on that.
-#if defined (__x86_64__) || defined (_M_X64) || defined (__ia64__) || defined (_M_IA64)
+#if defined (__x86_64__) || defined (_M_X64) || defined (__ia64__) || defined (_M_IA64) || defined (__amd64__)
  #define X86_64
 #endif
 
@@ -192,6 +192,47 @@
 
 #ifdef __cplusplus
 } // extern "C"
+
+#include <string>
+#include <cstring>
+
+namespace std {
+    template<> struct char_traits<unsigned char> {
+        typedef unsigned char char_type;
+        typedef int int_type;
+        typedef streamoff off_type;
+        typedef streampos pos_type;
+        typedef mbstate_t state_type;
+
+        static void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }
+        static bool eq(const char_type& c1, const char_type& c2) noexcept { return c1 == c2; }
+        static bool lt(const char_type& c1, const char_type& c2) noexcept { return c1 < c2; }
+
+        static int compare(const char_type* s1, const char_type* s2, size_t n) {
+            return memcmp(s1, s2, n);
+        }
+        static size_t length(const char_type* s) {
+            return strlen(reinterpret_cast<const char*>(s));
+        }
+        static const char_type* find(const char_type* s, size_t n, const char_type& a) {
+            return static_cast<const char_type*>(memchr(s, a, n));
+        }
+        static char_type* move(char_type* s1, const char_type* s2, size_t n) {
+            return static_cast<char_type*>(memmove(s1, s2, n));
+        }
+        static char_type* copy(char_type* s1, const char_type* s2, size_t n) {
+            return static_cast<char_type*>(memcpy(s1, s2, n));
+        }
+        static char_type* assign(char_type* s, size_t n, char_type a) {
+            return static_cast<char_type*>(memset(s, a, n));
+        }
+        static int_type not_eof(const int_type& i) noexcept { return i != eof() ? i : !eof(); }
+        static char_type to_char_type(const int_type& i) noexcept { return static_cast<char_type>(i); }
+        static int_type to_int_type(const char_type& c) noexcept { return static_cast<int_type>(c); }
+        static bool eq_int_type(const int_type& i1, const int_type& i2) noexcept { return i1 == i2; }
+        static int_type eof() noexcept { return static_cast<int_type>(EOF); }
+    };
+}
 #endif
 
 #endif // PLATFORM_H

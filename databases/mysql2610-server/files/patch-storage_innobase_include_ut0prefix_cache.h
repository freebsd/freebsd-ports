--- storage/innobase/include/ut0prefix_cache.h.orig	2026-10-30 11:03:27 UTC
+++ storage/innobase/include/ut0prefix_cache.h
@@ -23,7 +23,10 @@
 */
 #pragma once
 
+#include <cstring>
+#include <cwchar>
 #include <functional>
+#include <iosfwd>
 #include <list>
 #include <map>
 #include <string>
@@ -47,11 +50,80 @@
 Important limitation of this class (met by the parser usecase) is that it can
 work only with prefix-free languages, i.e. that is it doesn't support adding two
 prefixes such that one is a proper prefix of another. */
+/* libc++ provides character traits only for the standard character types, so
+a sequence of plain bytes needs traits of its own.  The members below are the
+ones a character traits class has to provide; of those only the comparisons
+and the copying are ever used here. */
+template <typename CharType>
+struct byte_traits {
+  using char_type = CharType;
+  using int_type = int;
+  using off_type = std::streamoff;
+  using pos_type = std::streampos;
+  using state_type = std::mbstate_t;
+
+  static constexpr void assign(char_type &c1, const char_type &c2) { c1 = c2; }
+  static constexpr bool eq(char_type c1, char_type c2) { return c1 == c2; }
+  static constexpr bool lt(char_type c1, char_type c2) { return c1 < c2; }
+
+  static constexpr int compare(const char_type *s1, const char_type *s2,
+                               std::size_t n) {
+    for (std::size_t i = 0; i < n; ++i) {
+      if (lt(s1[i], s2[i])) return -1;
+      if (lt(s2[i], s1[i])) return 1;
+    }
+    return 0;
+  }
+
+  static constexpr std::size_t length(const char_type *s) {
+    std::size_t n = 0;
+    while (eq(s[n], char_type()) == false) ++n;
+    return n;
+  }
+
+  static constexpr const char_type *find(const char_type *s, std::size_t n,
+                                         const char_type &a) {
+    for (std::size_t i = 0; i < n; ++i) {
+      if (eq(s[i], a)) return s + i;
+    }
+    return nullptr;
+  }
+
+  static char_type *move(char_type *s1, const char_type *s2, std::size_t n) {
+    return n == 0 ? s1 : static_cast<char_type *>(std::memmove(s1, s2, n));
+  }
+
+  static char_type *copy(char_type *s1, const char_type *s2, std::size_t n) {
+    return n == 0 ? s1 : static_cast<char_type *>(std::memcpy(s1, s2, n));
+  }
+
+  static constexpr char_type *assign(char_type *s, std::size_t n,
+                                     char_type a) {
+    for (std::size_t i = 0; i < n; ++i) s[i] = a;
+    return s;
+  }
+
+  static constexpr int_type not_eof(int_type c) {
+    return eq_int_type(c, eof()) ? 0 : c;
+  }
+  static constexpr char_type to_char_type(int_type c) {
+    return static_cast<char_type>(c);
+  }
+  static constexpr int_type to_int_type(char_type c) {
+    return static_cast<int_type>(c);
+  }
+  static constexpr bool eq_int_type(int_type c1, int_type c2) {
+    return c1 == c2;
+  }
+  static constexpr int_type eof() { return static_cast<int_type>(-1); }
+};
+
 template <typename CharType, typename Value>
 class prefix_cache {
  public:
-  using sequence = std::basic_string<CharType>;
-  using sequence_view = std::basic_string_view<CharType>;
+  using traits = byte_traits<CharType>;
+  using sequence = std::basic_string<CharType, traits>;
+  using sequence_view = std::basic_string_view<CharType, traits>;
 
   /** Create a cache with at most @p capacity stored prefixes.
 
@@ -148,8 +220,7 @@
 
   static bool is_prefix(sequence_view key, sequence_view buffer) {
     return buffer.size() >= key.size() &&
-           std::char_traits<CharType>::compare(key.data(), buffer.data(),
-                                               key.size()) == 0;
+           traits::compare(key.data(), buffer.data(), key.size()) == 0;
   }
 
   It try_find(sequence_view buffer) {

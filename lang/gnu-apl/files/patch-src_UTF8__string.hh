--- src/UTF8_string.hh.orig	2019-06-23 12:39:20 UTC
+++ src/UTF8_string.hh
@@ -45,7 +45,7 @@ utf8P(const void * vp)
 }
 //-----------------------------------------------------------------------------
 /// an UTF8 encoded Unicode (RFC 3629) string
-class UTF8_string : public std::basic_string<UTF8>
+class UTF8_string : public std::string
 {
 public:
    /// constructor: empty UTF8_string
@@ -79,15 +79,9 @@ class UTF8_string : public std::basic_string<UTF8> (pu
         return true;
       }
 
-   /// return \b this string as a 0-termionated C string
-   const char * c_str() const
-      { return reinterpret_cast<const char *>
-                               (std::basic_string<UTF8>::c_str()); }
-
-   /// prevent basic_string::erase() with its dangerous default value for
-   /// the number of erased character.
+   /// erase one item at \b pos
    void erase(size_t pos)
-      { basic_string::erase(pos, 1); }
+      { std::string::erase(begin() + pos); }
 
    /// return the last byte in this string
    UTF8 back() const

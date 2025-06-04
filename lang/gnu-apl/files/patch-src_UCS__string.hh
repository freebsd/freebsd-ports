--- src/UCS_string.hh.orig	2019-06-23 12:39:20 UTC
+++ src/UCS_string.hh
@@ -23,7 +23,7 @@
 
 #include <stdint.h>
 #include <stdio.h>
-#include <string>
+#include <vector>
 
 #include "Assert.hh"
 #include "Common.hh"
@@ -44,7 +44,7 @@ class UCS_string_vector;
 
 //=============================================================================
 /// A string of Unicode characters (32-bit)
-class UCS_string : public  basic_string<Unicode>
+class UCS_string : public vector<Unicode>
 {
 public:
    /// default constructor: empty string
@@ -186,7 +186,7 @@ class UCS_string : public  basic_string<Unicode> (publ
 
    /// remove the last character in \b this string
    void pop_back()
-   { Assert(size() > 0);   resize(size() - 1); }
+      { Assert(size() > 0);   vector<Unicode>::pop_back(); }
 
    /// return this string reversed (i.e. characters from back to front).
    UCS_string reverse() const;
@@ -216,13 +216,13 @@ class UCS_string : public  basic_string<Unicode> (publ
    int atoi() const;
 
    /// append UCS_string other to this string
-   void append(const UCS_string & other)
-      { basic_string::append(other); }
+   void append(const UCS_string & suffix)
+      { loop(s, suffix.size())   push_back(suffix[s]); }
 
    /// append 0-terminated ASCII string \b str to this string. str is NOT
    /// interpreted as UTF8 string (use append_UTF8() if such interpretation        /// is desired)
    void append_ASCII(const char * ascii)
-      { while (*ascii)   *this += Unicode(*ascii++); }
+      { while (const char cc = *ascii++)   push_back(Unicode(cc)); }
 
 
    /// append 0-terminated UTF8 string str to \b this UCS_string.
@@ -241,7 +241,7 @@ class UCS_string : public  basic_string<Unicode> (publ
 
    /// more intuitive insert() function
    void insert(ShapeItem pos, Unicode uni)
-      { basic_string::insert(pos, 1, uni); }
+      { vector<Unicode>::insert(begin() + pos, uni); }
 
    /// prepend character \b uni
    void prepend(Unicode uni)
@@ -249,7 +249,7 @@ class UCS_string : public  basic_string<Unicode> (publ
 
    /// return \b this string and \b other concatenated
    UCS_string operator +(const UCS_string & other) const
-      { UCS_string ret(*this);   ret += other;   return ret; }
+      { UCS_string ret(*this);   ret.append(other);   return ret; }
 
    /// append C-string \b str
    UCS_string & operator <<(const char * str)
@@ -261,11 +261,11 @@ class UCS_string : public  basic_string<Unicode> (publ
 
    /// append character \b uni
    UCS_string & operator <<(Unicode uni)
-      { *this += uni;   return *this; }
+      { push_back(uni);   return *this; }
 
    /// append UCS_string \b other
    UCS_string & operator <<(const UCS_string & other)
-      { basic_string::append(other);   return *this; }
+      { append(other);   return *this; }
 
    /// compare \b this with UCS_string \b other
    Comp_result compare(const UCS_string & other) const
@@ -301,16 +301,16 @@ class UCS_string : public  basic_string<Unicode> (publ
    /// the inverse of \b un_escape().
    UCS_string do_escape(bool double_quoted) const;
 
-   /// overload basic_string::size() so that it returns a signed length
+   /// overload vector::size() so that it returns a signed length
    ShapeItem size() const
-      { return basic_string::size(); }
+      { return ShapeItem(vector<Unicode>::size()); }
 
    /// an iterator for UCS_strings
    class iterator
       {
         public:
            /// constructor: start at position p
-           iterator(const UCS_string & ucs, int p)
+           iterator(const UCS_string & ucs, int p = 0)
            : s(ucs),
              pos(p)
            {}
@@ -335,10 +335,6 @@ class UCS_string : public  basic_string<Unicode> (publ
            int pos;
       };
 
-   /// an iterator set to the start of this string
-   UCS_string::iterator begin() const
-      { return iterator(*this, 0); }
-
    /// round last digit and discard it.
    void round_last_digit();
 
@@ -362,7 +358,7 @@ class UCS_string : public  basic_string<Unicode> (publ
 
    /// erase 1 (!) character at pos
    void erase(ShapeItem pos)
-      { basic_string::erase(pos, 1); }
+      { vector<Unicode>::erase(begin() + pos); }
 
    /// helper function for Heapsort<Unicode>::sort()
    static bool greater_uni(const Unicode & u1, const Unicode & u2, const void *)
@@ -425,7 +421,7 @@ class UCS_string : public  basic_string<Unicode> (publ
 private:
    /// prevent accidental usage of the rather dangerous default len parameter
    /// in basic_strng::erase(pos, len = npos)
-   basic_string & erase(size_type pos, size_type len);
+   vector<Unicode> & erase(size_type pos, size_type len);
 };
 //-----------------------------------------------------------------------------
 inline void

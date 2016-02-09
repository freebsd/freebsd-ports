Obtained from:

	https://github.com/maekitalo/cxxtools/commit/645dedf575da32198ac815655e5c6e5cd5cc4461

--- include/cxxtools/char.h.orig	2014-01-17 19:05:09 UTC
+++ include/cxxtools/char.h
@@ -72,23 +72,8 @@ namespace cxxtools
             : _value(0)
             {}
 
-            //! Constructs a character using the given char as base for the character value.
-            Char(char ch)
-            : _value(value_type(static_cast<unsigned char>(ch)))
-            {}
-
-            //! Constructs a character using the given char as base for the character value.
-            Char(unsigned char ch)
-            : _value( value_type(ch) )
-            {}
-
-            //! Constructs a character using the given char as base for the character value.
-            Char(wchar_t ch)
-            : _value( value_type(static_cast<uint16_t>(ch)) )
-            {}
-
-            //! Constructs a character using the given unsigned 32-bit as base for the character value.
-            explicit Char(value_type ch)
+            //! Constructs a character using the given value as base for the character value.
+            Char(value_type ch)
             : _value(ch)
             {}
 

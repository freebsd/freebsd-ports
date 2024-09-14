--- folly/io/Cursor.h.orig	2024-09-07 03:24:18 UTC
+++ folly/io/Cursor.h
@@ -677,6 +677,7 @@ class CursorBase {
     return ByteRange{data(), available};
   }
 
+#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION < 190000
   /**
    * Alternate version of peekBytes() that returns a std::basic_string_view
    * instead of a ByteRage.
@@ -687,6 +688,7 @@ class CursorBase {
     auto bytes = peekBytes();
     return {bytes.data(), bytes.size()};
   }
+#endif // _LIBCPP_VERSION < 190000
 
   /**
    * Alternate version of peekBytes() that returns a std::pair

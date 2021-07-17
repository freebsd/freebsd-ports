--- src/libutil/ustring.cpp.orig	2021-07-01 18:54:28 UTC
+++ src/libutil/ustring.cpp
@@ -308,7 +308,7 @@ struct libcpp_string__long {
     std::string::size_type __size_;
     std::string::size_type __cap_;
 };
-#    if _LIBCPP_BIG_ENDIAN
+#    ifdef _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = 0x1ul };
 #    else   // _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = ~(std::string::size_type(~0) >> 1) };
@@ -319,7 +319,7 @@ struct libcpp_string__long {
     std::string::size_type __size_;
     std::string::pointer __data_;
 };
-#    if _LIBCPP_BIG_ENDIAN
+#    ifdef _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = ~(std::string::size_type(~0) >> 1) };
 #    else   // _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = 0x1ul };

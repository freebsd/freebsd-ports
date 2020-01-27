--- src/libutil/ustring.cpp.orig	2020-01-27 21:27:51 UTC
+++ src/libutil/ustring.cpp
@@ -314,7 +314,7 @@ struct libcpp_string__long {
     std::string::size_type __size_;
     std::string::size_type __cap_;
 };
-#    if _LIBCPP_BIG_ENDIAN
+#    ifdef _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = 0x1ul };
 #    else   // _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = ~(std::string::size_type(~0) >> 1) };
@@ -325,7 +325,7 @@ struct libcpp_string__long {
     std::string::size_type __size_;
     std::string::pointer __data_;
 };
-#    if _LIBCPP_BIG_ENDIAN
+#    ifdef _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = ~(std::string::size_type(~0) >> 1) };
 #    else   // _LIBCPP_BIG_ENDIAN
 enum { libcpp_string__long_mask = 0x1ul };

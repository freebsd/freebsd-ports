--- boost/network/protocol/http/server/impl/parsers.ipp.orig	2018-07-19 06:37:41 UTC
+++ boost/network/protocol/http/server/impl/parsers.ipp
@@ -13,6 +13,7 @@
 #include <tuple>
 #include <boost/fusion/include/std_tuple.hpp>
 #include <boost/network/protocol/http/message/header.hpp>
+#include <boost/regex/pending/unicode_iterator.hpp>
 
 #ifdef BOOST_NETWORK_NO_LIB
 #ifndef BOOST_NETWORK_INLINE
@@ -32,7 +33,7 @@ struct assign_to_container_from_value<std::string, u32
 template <>  // <typename Attrib, typename T, typename Enable>
 struct assign_to_container_from_value<std::string, u32_string, void> {
   static void call(u32_string const& val, std::string& attr) {
-    u32_to_u8_iterator<u32_string::const_iterator> begin = val.begin(),
+    boost::u32_to_u8_iterator<u32_string::const_iterator> begin = val.begin(),
                                                    end = val.end();
     for (; begin != end; ++begin) attr += *begin;
   }

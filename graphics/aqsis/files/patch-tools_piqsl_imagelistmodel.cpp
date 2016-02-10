--- tools/piqsl/imagelistmodel.cpp.orig	2012-08-24 12:26:50 UTC
+++ tools/piqsl/imagelistmodel.cpp
@@ -42,11 +42,6 @@
 #include <boost/archive/iterators/transform_width.hpp>
 #include <boost/archive/iterators/remove_whitespace.hpp>
 #include <boost/version.hpp>
-#if BOOST_VERSION < 103700
-#   include <boost/pfto.hpp>
-#else
-#   include <boost/serialization/pfto.hpp>
-#endif
 
 
 #include "displayserverimage.h"
@@ -286,7 +281,7 @@ class SocketDataHandler
                                 std::string data = dataText->Value();
                                 std::vector<unsigned char> binaryData;
                                 binaryData.reserve(count);
-                                base64_binary ti_begin = base64_binary(BOOST_MAKE_PFTO_WRAPPER(data.begin()));
+                                base64_binary ti_begin = base64_binary(data.begin());
                                 std::size_t padding = 2 - count % 3;
                                 while(--count > 0)
                                 {

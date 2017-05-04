https://svn.boost.org/trac/boost/ticket/12982
https://github.com/boostorg/serialization/commit/1d8626158123

--- boost/serialization/array.hpp.orig	2017-04-17 02:22:24 UTC
+++ boost/serialization/array.hpp
@@ -23,6 +23,8 @@ namespace std{ 
 } // namespace std
 #endif
 
+#include <boost/serialization/array_wrapper.hpp>
+
 #ifndef BOOST_NO_CXX11_HDR_ARRAY
 
 #include <array>

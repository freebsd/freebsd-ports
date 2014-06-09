--- boost/archive/iterators/transform_width.hpp.orig	2013-04-28 18:07:27.000000000 +0200
+++ boost/archive/iterators/transform_width.hpp	2014-06-09 17:27:54.615330893 +0200
@@ -30,6 +30,8 @@
 #include <boost/iterator/iterator_adaptor.hpp>
 #include <boost/iterator/iterator_traits.hpp>
 
+#include <algorithm> // std::min
+
 namespace boost { 
 namespace archive {
 namespace iterators {

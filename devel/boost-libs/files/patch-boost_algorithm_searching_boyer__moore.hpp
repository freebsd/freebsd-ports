Patch from: https://github.com/boostorg/algorithm/pull/124
Fixed patch paths to match boost distribution.

--- boost/algorithm/searching/boyer_moore.hpp.orig	2025-08-06 18:49:07 UTC
+++ boost/algorithm/searching/boyer_moore.hpp
@@ -10,6 +10,7 @@
 #ifndef BOOST_ALGORITHM_BOYER_MOORE_SEARCH_HPP
 #define BOOST_ALGORITHM_BOYER_MOORE_SEARCH_HPP
 
+#include <algorithm>    // for std::reverse_copy
 #include <iterator>     // for std::iterator_traits
 
 #include <boost/config.hpp>

https://svn.boost.org/trac/boost/ticket/12537

--- boost/math/tools/tuple.hpp.orig	2016-09-21 14:33:24 UTC
+++ boost/math/tools/tuple.hpp
@@ -6,6 +6,7 @@
 #ifndef BOOST_MATH_TUPLE_HPP_INCLUDED
 #  define BOOST_MATH_TUPLE_HPP_INCLUDED
 #  include <boost/config.hpp>
+#  include <boost/detail/workaround.hpp>
 
 #if !defined(BOOST_NO_CXX11_HDR_TUPLE) && !BOOST_WORKAROUND(BOOST_GCC_VERSION, < 40500)
 

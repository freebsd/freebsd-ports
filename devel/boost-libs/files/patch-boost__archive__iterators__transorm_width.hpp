--- boost/archive/iterators/transform_width.hpp.orig	2013-04-29 01:07:27.000000000 +0900
+++ boost/archive/iterators/transform_width.hpp	2015-08-30 04:46:06.968463000 +0900
@@ -30,6 +30,8 @@
 #include <boost/iterator/iterator_adaptor.hpp>
 #include <boost/iterator/iterator_traits.hpp>
 
+#include <algorithm> // std::min
+
 namespace boost { 
 namespace archive {
 namespace iterators {
@@ -112,6 +114,7 @@
     transform_width(BOOST_PFTO_WRAPPER(T) start) : 
         super_t(Base(BOOST_MAKE_PFTO_WRAPPER(static_cast< T >(start)))),
         m_buffer_out_full(false),
+        m_buffer_in(0),
         m_remaining_bits(0),
         m_end_of_sequence(false)
     {}
@@ -119,8 +122,8 @@
     transform_width(const transform_width & rhs) : 
         super_t(rhs.base_reference()),
         m_buffer_out_full(rhs.m_buffer_out_full),
-        m_remaining_bits(rhs.m_remaining_bits),
         m_buffer_in(rhs.m_buffer_in),
+        m_remaining_bits(rhs.m_remaining_bits),
         m_end_of_sequence(false)
     {}
 };

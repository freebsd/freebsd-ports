--- boost/range/detail/any_iterator_interface.hpp.orig	2025-04-03 11:37:29 UTC
+++ boost/range/detail/any_iterator_interface.hpp
@@ -13,6 +13,7 @@
 #include <boost/mpl/if.hpp>
 #include <boost/range/detail/any_iterator_buffer.hpp>
 #include <boost/iterator/iterator_categories.hpp>
+#include <boost/type_traits/add_const.hpp>
 #include <boost/type_traits/is_convertible.hpp>
 #include <boost/type_traits/is_reference.hpp>
 #include <boost/type_traits/remove_const.hpp>

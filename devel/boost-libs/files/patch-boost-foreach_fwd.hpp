--- boost/foreach_fwd.hpp	(revision 62661)
+++ boost/foreach_fwd.hpp	(revision 75540)
@@ -15,4 +15,6 @@
 #define BOOST_FOREACH_FWD_HPP
 
+#include <utility> // for std::pair
+
 // This must be at global scope, hence the uglified name
 enum boost_foreach_argument_dependent_lookup_hack
@@ -26,4 +28,7 @@
 namespace foreach
 {
+    template<typename T>
+    std::pair<T, T> in_range(T begin, T end);
+
     ///////////////////////////////////////////////////////////////////////////////
     // boost::foreach::tag
@@ -47,4 +52,22 @@
 } // namespace foreach
 
+// Workaround for unfortunate https://svn.boost.org/trac/boost/ticket/6131
+namespace BOOST_FOREACH
+{
+    using foreach::in_range;
+    using foreach::tag;
+
+    template<typename T>
+    struct is_lightweight_proxy
+      : foreach::is_lightweight_proxy<T>
+    {};
+
+    template<typename T>
+    struct is_noncopyable
+      : foreach::is_noncopyable<T>
+    {};
+
+} // namespace BOOST_FOREACH
+
 } // namespace boost
 

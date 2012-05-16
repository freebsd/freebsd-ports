--- boost/foreach.hpp	(revision 75077)
+++ boost/foreach.hpp	(revision 75540)
@@ -166,5 +166,5 @@
 //   at the global namespace for your type.
 template<typename T>
-inline boost::foreach::is_lightweight_proxy<T> *
+inline boost::BOOST_FOREACH::is_lightweight_proxy<T> *
 boost_foreach_is_lightweight_proxy(T *&, BOOST_FOREACH_TAG_DEFAULT) { return 0; }
 
@@ -191,5 +191,5 @@
 //   at the global namespace for your type.
 template<typename T>
-inline boost::foreach::is_noncopyable<T> *
+inline boost::BOOST_FOREACH::is_noncopyable<T> *
 boost_foreach_is_noncopyable(T *&, BOOST_FOREACH_TAG_DEFAULT) { return 0; }
 

--- src/ui/tool/node.h.orig	2012-02-14 04:22:17.670697000 +0100
+++ src/ui/tool/node.h	2013-10-17 12:47:44.000000000 +0200
@@ -16,7 +16,13 @@
 #include <iosfwd>
 #include <stdexcept>
 #include <cstddef>
+
+#if __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+#endif
+
 #include <boost/utility.hpp>
 #include <boost/shared_ptr.hpp>
 #include <boost/optional.hpp>
@@ -32,11 +38,13 @@
 }
 }
 
+#if __cplusplus < 201103L && !defined(_LIBCPP_VERSION)
 namespace std {
 namespace tr1 {
 template <typename N> struct hash< Inkscape::UI::NodeIterator<N> >;
 }
 }
+#endif
 
 namespace Inkscape {
 namespace UI {

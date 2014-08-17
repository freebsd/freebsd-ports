--- src/libtomahawk/utils/Closure.h.orig	2014-08-15 16:48:25.000000000 +0200
+++ src/libtomahawk/utils/Closure.h	2014-08-15 16:49:47.000000000 +0200
@@ -30,6 +30,10 @@
 #include <boost/noncopyable.hpp>
 #include <boost/scoped_ptr.hpp>
 
+#ifdef _LIBCPP_VERSION
+namespace std { namespace tr1 = std; }
+#endif
+
 namespace _detail {
 
 class DLLEXPORT ClosureArgumentWrapper {

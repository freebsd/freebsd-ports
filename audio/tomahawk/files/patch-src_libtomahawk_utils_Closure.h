--- src/libtomahawk/utils/Closure.h.orig	2015-04-15 04:41:40 UTC
+++ src/libtomahawk/utils/Closure.h
@@ -40,6 +40,10 @@ using std::tr1::function;
 #include <boost/noncopyable.hpp>
 #include <boost/scoped_ptr.hpp>
 
+#ifdef _LIBCPP_VERSION
+namespace std { namespace tr1 = std; }
+#endif
+
 namespace _detail {
 
 class DLLEXPORT ClosureArgumentWrapper {

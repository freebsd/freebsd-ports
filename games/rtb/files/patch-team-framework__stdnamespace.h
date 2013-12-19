--- team-framework/stdnamespace.h.orig
+++ team-framework/stdnamespace.h
@@ -25,9 +25,13 @@
 
 **************************************************************************/
 
+#if !defined(_LIBCPP_VERSION)
 #include <iosfwd>	// This file contains the forward declaration in particular of std::string
 
 namespace std
 {
 	template <class _Tp> class auto_ptr;	// Origin: The header file <memory>
 }
+#else
+#include <memory>
+#endif

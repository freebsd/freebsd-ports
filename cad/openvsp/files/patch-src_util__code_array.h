Workaround for libc++, which declares std::array even if not in C++11 mode (see
ports/207253 for a bigger discussion).
--- src/util_code/array.h.orig	2016-02-25 10:29:49 UTC
+++ src/util_code/array.h
@@ -20,11 +20,12 @@
 #include <iostream>
 using namespace std;
 
+namespace openvsp {
+
 // Define Error Flags //
 #define BELOW_BOUNDS	0
 #define ABOVE_BOUNDS	1
 
-
 template<class Item_type>
 
 class array
@@ -328,5 +331,6 @@ void array<Item_type>::print_error_messa
 
 }
 
+}  // namespace openvsp
 
 #endif

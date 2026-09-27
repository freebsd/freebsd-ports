--- libcore/FillStyle.h.orig
+++ libcore/FillStyle.h
@@ -25,6 +25,7 @@
 #include <iosfwd> 
 #include <boost/intrusive_ptr.hpp>
 #include <cassert>
+#include <type_traits>
 
 #include "SWFMatrix.h"
 #include "SWF.h"
@@ -289,7 +290,9 @@
     /// The non-explicit templated contructor allows the same syntax as a
     /// simple boost::variant:
     ///     FillStyle f = GradientFill();
-    template<typename T> FillStyle(const T& f) : fill(f) {}
+    template<typename T, typename = typename std::enable_if<
+        std::is_constructible<Fill, const T&>::value>::type>
+    FillStyle(const T& f) : fill(f) {}
 
     FillStyle(const FillStyle& other)
         :

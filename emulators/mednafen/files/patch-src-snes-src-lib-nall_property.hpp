--- src/snes/src/lib/nall/property.hpp	2014-04-05 16:03:07.000000000 -0500
+++ src/snes/src/lib/nall/property.hpp	2014-04-05 16:03:17.000000000 -0500
@@ -61,7 +61,7 @@
       operator T&() { return value; }
       const T& operator=(const T& value_) { return value = value_; }
       T value;
-      friend class traits<C>::type;
+      friend typename traits<C>::type;
     };
 
     template<typename T> struct writeonly {

--- src/snes/src/lib/nall/property.hpp	2013-08-31 16:33:30.000000000 -0500
+++ src/snes/src/lib/nall/property.hpp	2014-04-05 18:58:31.000000000 -0500
@@ -61,7 +61,11 @@
       operator T&() { return value; }
       const T& operator=(const T& value_) { return value = value_; }
       T value;
+#if defined(__clang__)
+      friend typename traits<C>::type;
+#else
       friend class traits<C>::type;
+#endif
     };
 
     template<typename T> struct writeonly {

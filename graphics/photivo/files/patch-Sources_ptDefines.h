--- Sources/ptDefines.h.orig	2016-03-22 03:34:55 UTC
+++ Sources/ptDefines.h
@@ -33,6 +33,8 @@
 #define __STDC_LIMIT_MACROS
 #include <cstdint>
 
+#include <cstdlib>
+
 // disable the file manager
 // #define PT_WITHOUT_FILEMGR
 
@@ -63,7 +65,7 @@ std::unique_ptr<T> make_unique(Args&& ..
 namespace pt {
   namespace detail {
     struct c_deleter {
-      void operator()(void* ptr) { std::free(ptr); }
+      void operator()(void* ptr) { free(ptr); }
     };
   }
   template<typename T>

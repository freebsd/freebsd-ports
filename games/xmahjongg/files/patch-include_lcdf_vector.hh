--- include/lcdf/vector.hh.orig	2018-02-21 11:37:54 UTC
+++ include/lcdf/vector.hh
@@ -7,7 +7,11 @@
 #elif defined(HAVE_NEW_H)
 # include <new.h>
 #else
-static inline void *operator new(size_t, void *v) { return v; }
+#if __cplusplus > 199711L
+  inline void *operator new(size_t, void *v) { return v; }
+#else
+  static inline void *operator new(size_t, void *v) { return v; }
+#endif
 #endif
 
 template <class T>

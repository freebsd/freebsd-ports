--- src/misc/re.cxx.orig	2015-08-12 21:02:27 UTC
+++ src/misc/re.cxx
@@ -120,12 +120,25 @@ void re_t::suboff(size_t n, int* start, 
 	}
 }
 
+#ifdef __clang__
+  #if __has_include(<functional>)
+    #include <functional>
+    #define HAS_STD_TR1
+  #endif
+#endif
+#ifndef HAS_STD_TR1
 #include <tr1/functional>
+#endif
 
 size_t re_t::hash(void) const
 {
+#ifdef HAS_STD_TR1
+	size_t h = std::hash<string>()(pattern);
+	return h ^ (std::hash<int>()(cflags) + 0x9e3779b9 + (h << 6) + (h >> 2));
+#else
 	size_t h = tr1::hash<string>()(pattern);
 	return h ^ (tr1::hash<int>()(cflags) + 0x9e3779b9 + (h << 6) + (h >> 2));
+#endif
 }
 
 // ------------------------------------------------------------------------

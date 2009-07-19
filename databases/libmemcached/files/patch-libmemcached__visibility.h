--- libmemcached/visibility.h.orig	2009-07-18 20:31:32.000000000 +0800
+++ libmemcached/visibility.h	2009-07-18 20:31:49.000000000 +0800
@@ -34,6 +34,9 @@
 # elif defined(_MSC_VER)
 #  define LIBMEMCACHED_API extern __declspec(dllexport) 
 #  define LIBMEMCACHED_LOCAL
+# else
+#  define LIBMEMCACHED_API
+#  define LIBMEMCACHED_LOCAL
 # endif /* defined(HAVE_VISIBILITY) */
 #else  /* defined(BUILDING_LIBMEMCACHED) */
 # if defined(_MSC_VER)

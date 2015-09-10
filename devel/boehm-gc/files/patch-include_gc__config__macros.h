--- include/gc_config_macros.h.orig	2014-06-03 06:08:02 UTC
+++ include/gc_config_macros.h
@@ -242,13 +242,17 @@
 #ifndef GC_ATTR_ALLOC_SIZE
   /* 'alloc_size' attribute improves __builtin_object_size correctness. */
   /* Only single-argument form of 'alloc_size' attribute is used.       */
-# if defined(__GNUC__) && (__GNUC__ > 4 \
-        || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3 && !defined(__ICC)) \
-        || __clang_major__ > 3 \
-        || (__clang_major__ == 3 && __clang_minor__ >= 2))
+# ifdef __clang__
+#   if __has_attribute(__alloc_size__)
+#     define GC_ATTR_ALLOC_SIZE(argnum) __attribute__((__alloc_size__(argnum)))
+#   else
+#     define GC_ATTR_ALLOC_SIZE(argnum) /* empty */
+#   endif
+# elif __GNUC__ > 4 \
+       || (__GNUC__ == 4 && __GNUC_MINOR__ >=3 && !defined(__ICC))
 #   define GC_ATTR_ALLOC_SIZE(argnum) __attribute__((__alloc_size__(argnum)))
 # else
-#   define GC_ATTR_ALLOC_SIZE(argnum)
+#   define GC_ATTR_ALLOC_SIZE(argnum) /* empty */
 # endif
 #endif
 

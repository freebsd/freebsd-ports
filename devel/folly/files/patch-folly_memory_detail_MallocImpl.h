--- folly/memory/detail/MallocImpl.h.orig	2020-08-03 02:16:39 UTC
+++ folly/memory/detail/MallocImpl.h
@@ -38,9 +38,9 @@ int mallctlnametomib(const char*, size_t*, size_t*)
     __attribute__((__nothrow__, __weak__));
 int mallctlbymib(const size_t*, size_t, void*, size_t*, void*, size_t)
     __attribute__((__nothrow__, __weak__));
+#endif
 bool MallocExtension_Internal_GetNumericProperty(const char*, size_t, size_t*)
     __attribute__((__weak__));
-#endif
 #else
 #if (!defined(USE_JEMALLOC) && !defined(FOLLY_USE_JEMALLOC)) || FOLLY_SANITIZE
 // we do not want to declare these if we have jemalloc support

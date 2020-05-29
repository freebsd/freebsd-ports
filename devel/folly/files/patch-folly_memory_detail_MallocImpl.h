--- folly/memory/detail/MallocImpl.h.orig	2020-05-27 18:42:57 UTC
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
 extern void* (*mallocx)(size_t, int);
 extern void* (*rallocx)(void*, size_t, int);

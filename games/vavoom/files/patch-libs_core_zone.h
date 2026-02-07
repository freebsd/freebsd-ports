--- libs/core/zone.h.orig	2022-12-31 03:37:53 UTC
+++ libs/core/zone.h
@@ -27,88 +27,21 @@
 //**
 //**************************************************************************
 
-//#define ZONE_DEBUG		1
-
 void Z_Shutdown();
 
-#ifdef ZONE_DEBUG
-
-void* Z_Malloc(int size, const char* FileName, int LineNumber);
-void* Z_Calloc(int size, const char* FileName, int LineNumber);
-void Z_Free(void* ptr, const char* FileName, int LineNumber);
-
-inline void* operator new(size_t Size, const char* FileName, int LineNumber)
+static inline void* Z_Malloc(int size)
 {
-	return Z_Malloc(Size, FileName, LineNumber);
+	return static_cast<void *>(operator new(size));
 }
 
-inline void operator delete(void* Ptr, const char* FileName, int LineNumber)
+static inline void* Z_Calloc(int size)
 {
-	Z_Free(Ptr, FileName, LineNumber);
+	return memset(Z_Malloc(size), 0, size);
 }
 
-inline void* operator new[](size_t Size, const char* FileName, int LineNumber)
+static inline void Z_Free(void* ptr)
 {
-	return Z_Malloc(Size, FileName, LineNumber);
+	char *p = (char *)ptr;
+	delete p;
 }
 
-inline void operator delete[](void* Ptr, const char* FileName, int LineNumber)
-{
-	Z_Free(Ptr, FileName, LineNumber);
-}
-
-inline void* operator new(size_t Size)
-{
-	return Z_Malloc(Size, "", 0);
-}
-
-inline void operator delete(void* Ptr)
-{
-	Z_Free(Ptr, "", 0);
-}
-
-inline void* operator new[](size_t Size)
-{
-	return Z_Malloc(Size, "", 0);
-}
-
-inline void operator delete[](void* Ptr)
-{
-	Z_Free(Ptr, "", 0);
-}
-
-#define Z_Malloc(size)				Z_Malloc(size, __FILE__, __LINE__)
-#define Z_Calloc(size)				Z_Calloc(size, __FILE__, __LINE__)
-#define Z_Free(ptr)					Z_Free(ptr, __FILE__, __LINE__)
-
-#define ZONE_DEBUG_NEW				new(__FILE__, __LINE__)
-#undef new
-#define new							ZONE_DEBUG_NEW
-
-#else
-
-void* Z_Malloc(int size);
-void* Z_Calloc(int size);
-void Z_Free(void* ptr);
-
-inline void* operator new(size_t Size)
-{
-	return Z_Malloc(int(Size));
-}
-
-inline void operator delete(void* Ptr)
-{
-	Z_Free(Ptr);
-}
-
-inline void* operator new[](size_t Size)
-{
-	return Z_Malloc(int(Size));
-}
-
-inline void operator delete[](void* Ptr)
-{
-	Z_Free(Ptr);
-}
-
-#endif

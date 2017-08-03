--- Common/debug/assert.h.orig	2017-08-03 13:21:09 UTC
+++ Common/debug/assert.h
@@ -18,31 +18,6 @@
 #ifndef __AGS_CN_DEBUG__ASSERT_H
 #define __AGS_CN_DEBUG__ASSERT_H
 
-#ifdef _DEBUG
-
-// TODO: revise this later (add platform-specific output maybe?)
-#if defined(WINDOWS_VERSION)
-
-inline void assert(bool expr)
-{
-    if (!expr) {
-        _asm {
-            int 3
-        }
-    }
-}
-
-#else // !WINDOWS_VERSION
-
 #include <assert.h>
-
-#endif
-
-#else // !_DEBUG
-
-// JJS: GCC has trouble with macro overloading
-inline void assert(bool expr) {}
-
-#endif // !_DEBUG
 
 #endif // __AGS_CN_DEBUG__ASSERT_H

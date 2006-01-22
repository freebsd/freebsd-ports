--- base/src/utils/sharedlibrary.cpp.orig
+++ base/src/utils/sharedlibrary.cpp
@@ -73,7 +73,7 @@
 #elif defined(OS_LINUX)
     m_impl->handle = dlopen(path.c_str(), RTLD_NOW);
 #elif defined(OS_BSD)
-    m_impl->handle = dlopen(path.c_str(), DL_LAZY);
+    m_impl->handle = dlopen(path.c_str(), RTLD_LAZY);
 #elif defined(OS_POSIX)
     m_impl->handle = dlopen(path.c_str(), 0);
 #endif

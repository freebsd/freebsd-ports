--- src/google/protobuf/stubs/common.h.orig	2018-07-27 20:30:28 UTC
+++ src/google/protobuf/stubs/common.h
@@ -206,7 +206,7 @@ LIBPROTOBUF_EXPORT void OnShutdownRun(vo
 
 template <typename T>
 T* OnShutdownDelete(T* p) {
-  OnShutdownRun([](const void* p) { delete static_cast<const T*>(p); }, p);
+  OnShutdownRun([](const void* pp) { delete static_cast<const T*>(pp); }, p);
   return p;
 }
 

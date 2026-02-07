--- swift/stdlib/public/stubs/Random.cpp.orig	2024-06-06 04:26:30 UTC
+++ swift/stdlib/public/stubs/Random.cpp
@@ -54,7 +54,7 @@ using namespace swift;
 
 using namespace swift;
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 
 SWIFT_RUNTIME_STDLIB_API
 void swift_stdlib_random(void *buf, __swift_size_t nbytes) {

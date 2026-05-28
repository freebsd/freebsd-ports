--- opennurbs_string_scan.cpp.orig	2026-04-14 14:48:14 UTC
+++ opennurbs_string_scan.cpp
@@ -83,7 +83,7 @@ int ON_String::ScanBufferVargs(
   )
 {
 #if defined(ON_COMPILER_CLANG) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   if (nullptr == buffer || nullptr == format)
     return -1;
   return vsscanf(buffer, format, args);
@@ -396,7 +396,7 @@ const char* ON_String::ToNumber(
 
   double x = value_on_failure;
 #if defined(ON_COMPILER_CLANG) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   if (1 == sscanf(local_buffer, "%lg", &x))
   {
     *value = x;
@@ -658,7 +658,7 @@ const wchar_t* ON_wString::ToNumber(
 
   double x = value_on_failure;
 #if defined(ON_COMPILER_CLANG) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   if (1 == sscanf(local_buffer, "%lg", &x))
   {
     *value = x;

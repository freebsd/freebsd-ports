--- opennurbs_locale.cpp.orig	2026-04-14 14:48:14 UTC
+++ opennurbs_locale.cpp
@@ -32,13 +32,13 @@ static ON_CRT_locale_t ON_CRT_C_locale()
     ON_C_locale = _create_locale(LC_ALL, "C");
 #elif defined(ON_RUNTIME_APPLE)
     ON_C_locale = _c_locale;
-#elif defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#elif defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
     ON_C_locale = 0;
 #else
-    ON_C_locale = _create_locale(category, locale);
+    ON_C_locale = _create_locale(LC_ALL, "C");
 #endif
   }
-  
+
   return ON_C_locale;
 }
 
@@ -101,10 +101,10 @@ static ON_CRT_locale_t ON_CRT_create_locale_ALL( const
     }
   }
   return newlocale(LC_ALL_MASK, apple_name, ON_CRT_C_locale() );
-#elif defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#elif defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   return 0;
 #else
-  return _create_locale(category, locale);
+  return _create_locale(LC_ALL, locale);
 #endif
 }
 
@@ -1345,7 +1345,7 @@ class ON_CRT_LOCALE (public)
   static bool Validate_sprintf_l()
   {
 #if defined(ON_COMPILER_CLANG) || defined(ON_COMPILER_GNU)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
     // Test formatted printing
     char buffer[64] = { 0 };
     // Testing C-runtime - do not using ON_String::FormatIntoBuffer
@@ -1370,7 +1370,7 @@ class ON_CRT_LOCALE (public)
   static bool Validate_sprintf_s_l()
   {
 #if defined(ON_COMPILER_CLANG) || defined(ON_COMPILER_GNU)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
     // Test formatted printing
     char buffer[64] = { 0 };
     size_t buffer_capacity = (sizeof(buffer) / sizeof(buffer[0])) - 1;
@@ -1424,7 +1424,7 @@ class ON_CRT_LOCALE (public)
   static bool Validate_sscanf_l()
   {
 #if defined(ON_COMPILER_CLANG) || defined(ON_COMPILER_GNU)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
     // Test formatted scanning
     double a = ON_UNSET_VALUE;
     // Testing C-runtime - do not using ON_String::Scan
@@ -1449,7 +1449,7 @@ class ON_CRT_LOCALE (public)
   static bool Validate_sscanf_s_l()
   {
 #if defined(ON_COMPILER_CLANG) || defined(ON_COMPILER_GNU)
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
     // Test formatted scanning
     double a = ON_UNSET_VALUE;
     // Testing C-runtime - do not using ON_String::Scan

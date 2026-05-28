--- opennurbs_string_format.cpp.orig	2026-04-14 14:48:14 UTC
+++ opennurbs_string_format.cpp
@@ -802,7 +802,7 @@ int ON_String::FormatVargsIntoBuffer(
   // CLang modifies args so a copy is required
   va_list args_copy;
   va_copy (args_copy, args);
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   int len = vsnprintf(buffer, buffer_capacity, format, args_copy);
 #else
   int len = vsnprintf_l(buffer, buffer_capacity, ON_Locale::Ordinal.NumericLocalePtr(), format, args_copy);
@@ -855,7 +855,7 @@ int ON_String::FormatVargsOutputCount(
   va_list args_copy;
   va_copy (args_copy, args);
 
-#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   int len = vsnprintf(nullptr, 0, format, args_copy);
 #else
   int len = vsnprintf_l(nullptr, 0, ON_Locale::Ordinal.NumericLocalePtr(), format, args_copy);

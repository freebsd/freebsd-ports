--- lib/vulkan-hpp/vulkan/vulkan.hpp.orig	2021-01-28 12:10:12 UTC
+++ lib/vulkan-hpp/vulkan/vulkan.hpp
@@ -61,7 +61,7 @@
 #endif
 
 #if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL == 1
-#  if defined(__linux__) || defined(__APPLE__)
+#  if defined(__unix__) || defined(__APPLE__)
 #   include <dlfcn.h>
 #  endif
 
@@ -67953,7 +67953,7 @@ namespace VULKAN_HPP_NAMESPACE
     DynamicLoader() : m_success( false )
 #endif
     {
-#if defined(__linux__)
+#if defined(__unix__)
       m_library = dlopen( "libvulkan.so", RTLD_NOW | RTLD_LOCAL );
 #elif defined(__APPLE__)
       m_library = dlopen( "libvulkan.dylib", RTLD_NOW | RTLD_LOCAL );
@@ -67977,7 +67977,7 @@ namespace VULKAN_HPP_NAMESPACE
     {
       if ( m_library )
       {
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__) || defined(__APPLE__)
         dlclose( m_library );
 #elif defined(_WIN32)
         FreeLibrary( m_library );
@@ -67988,7 +67988,7 @@ namespace VULKAN_HPP_NAMESPACE
     template <typename T>
     T getProcAddress( const char* function ) const VULKAN_HPP_NOEXCEPT
     {
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__) || defined(__APPLE__)
       return (T)dlsym( m_library, function );
 #elif defined(_WIN32)
       return (T)GetProcAddress( m_library, function );
@@ -67999,7 +67999,7 @@ namespace VULKAN_HPP_NAMESPACE
 
   private:
     bool m_success;
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__) || defined(__APPLE__)
     void *m_library;
 #elif defined(_WIN32)
     HMODULE m_library;

--- include/vulkan/vulkan.hpp.orig	2020-05-14 18:48:51 UTC
+++ include/vulkan/vulkan.hpp
@@ -65,7 +65,7 @@
 #endif
 
 #if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL == 1
-#  if defined(__linux__) || defined(__APPLE__)
+#  if defined(__unix__)
 #   include <dlfcn.h>
 #  endif
 
@@ -81153,7 +81153,7 @@ namespace VULKAN_HPP_NAMESPACE
     DynamicLoader() : m_success( false )
 #endif
     {
-#if defined(__linux__)
+#if defined(__unix__)
       m_library = dlopen( "libvulkan.so", RTLD_NOW | RTLD_LOCAL );
 #elif defined(__APPLE__)
       m_library = dlopen( "libvulkan.dylib", RTLD_NOW | RTLD_LOCAL );
@@ -81195,7 +81195,7 @@ namespace VULKAN_HPP_NAMESPACE
     {
       if ( m_library )
       {
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
         dlclose( m_library );
 #elif defined(_WIN32)
         FreeLibrary( m_library );
@@ -81206,7 +81206,7 @@ namespace VULKAN_HPP_NAMESPACE
     template <typename T>
     T getProcAddress( const char* function ) const VULKAN_HPP_NOEXCEPT
     {
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
       return (T)dlsym( m_library, function );
 #elif defined(_WIN32)
       return (T)GetProcAddress( m_library, function );
@@ -81217,7 +81217,7 @@ namespace VULKAN_HPP_NAMESPACE
 
   private:
     bool m_success;
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
     void *m_library;
 #elif defined(_WIN32)
     HMODULE m_library;

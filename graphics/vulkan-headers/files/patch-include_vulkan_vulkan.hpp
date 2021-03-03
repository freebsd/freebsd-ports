--- include/vulkan/vulkan.hpp.orig	2021-03-01 06:51:42 UTC
+++ include/vulkan/vulkan.hpp
@@ -67,7 +67,7 @@
 #endif
 
 #if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL == 1
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
 #    include <dlfcn.h>
 #  elif defined( _WIN32 )
 typedef struct HINSTANCE__ * HINSTANCE;
@@ -92518,7 +92518,7 @@ namespace VULKAN_HPP_NAMESPACE
     {
       if ( !vulkanLibraryName.empty() )
       {
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
         m_library = dlopen( vulkanLibraryName.c_str(), RTLD_NOW | RTLD_LOCAL );
 #  elif defined( _WIN32 )
         m_library = ::LoadLibraryA( vulkanLibraryName.c_str() );
@@ -92528,7 +92528,7 @@ namespace VULKAN_HPP_NAMESPACE
       }
       else
       {
-#  if defined( __linux__ ) || defined( __QNXNTO__ )
+#  if defined( __unix__ ) || defined( __QNXNTO__ )
         m_library = dlopen( "libvulkan.so", RTLD_NOW | RTLD_LOCAL );
         if ( m_library == nullptr )
         {
@@ -92571,7 +92571,7 @@ namespace VULKAN_HPP_NAMESPACE
     {
       if ( m_library )
       {
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
         dlclose( m_library );
 #  elif defined( _WIN32 )
         ::FreeLibrary( m_library );
@@ -92584,7 +92584,7 @@ namespace VULKAN_HPP_NAMESPACE
     template <typename T>
     T getProcAddress( const char* function ) const VULKAN_HPP_NOEXCEPT
     {
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
       return (T)dlsym( m_library, function );
 #  elif defined( _WIN32 )
       return (T)::GetProcAddress( m_library, function );
@@ -92596,7 +92596,7 @@ namespace VULKAN_HPP_NAMESPACE
     bool success() const VULKAN_HPP_NOEXCEPT { return m_library != nullptr; }
 
   private:
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ )
     void * m_library;
 #  elif defined( _WIN32 )
     ::HINSTANCE m_library;

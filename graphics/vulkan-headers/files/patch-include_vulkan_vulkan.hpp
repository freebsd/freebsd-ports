--- include/vulkan/vulkan.hpp.orig	2021-04-19 06:31:54 UTC
+++ include/vulkan/vulkan.hpp
@@ -67,7 +67,7 @@
 #endif
 
 #if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL == 1
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
 #    include <dlfcn.h>
 #  elif defined( _WIN32 )
 typedef struct HINSTANCE__ * HINSTANCE;
@@ -121385,7 +121385,7 @@ namespace VULKAN_HPP_NAMESPACE
     {
       if ( !vulkanLibraryName.empty() )
       {
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
         m_library = dlopen( vulkanLibraryName.c_str(), RTLD_NOW | RTLD_LOCAL );
 #  elif defined( _WIN32 )
         m_library = ::LoadLibraryA( vulkanLibraryName.c_str() );
@@ -121395,7 +121395,7 @@ namespace VULKAN_HPP_NAMESPACE
       }
       else
       {
-#  if defined( __linux__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
+#  if defined( __unix__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
         m_library = dlopen( "libvulkan.so", RTLD_NOW | RTLD_LOCAL );
         if ( m_library == nullptr )
         {
@@ -121439,7 +121439,7 @@ namespace VULKAN_HPP_NAMESPACE
     {
       if ( m_library )
       {
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
         dlclose( m_library );
 #  elif defined( _WIN32 )
         ::FreeLibrary( m_library );
@@ -121452,7 +121452,7 @@ namespace VULKAN_HPP_NAMESPACE
     template <typename T>
     T getProcAddress( const char * function ) const VULKAN_HPP_NOEXCEPT
     {
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
       return (T)dlsym( m_library, function );
 #  elif defined( _WIN32 )
       return ( T )::GetProcAddress( m_library, function );
@@ -121467,7 +121467,7 @@ namespace VULKAN_HPP_NAMESPACE
     }
 
   private:
-#  if defined( __linux__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
+#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
     void * m_library;
 #  elif defined( _WIN32 )
     ::HINSTANCE m_library;

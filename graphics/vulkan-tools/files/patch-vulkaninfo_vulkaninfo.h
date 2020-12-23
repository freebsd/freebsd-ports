--- vulkaninfo/vulkaninfo.h.orig	2020-04-08 02:52:46 UTC
+++ vulkaninfo/vulkaninfo.h
@@ -60,7 +60,7 @@
 #include <windows.h>
 #endif  // _WIN32
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__) || defined(__APPLE__)
 #include <dlfcn.h>
 #endif
 
@@ -253,7 +253,7 @@ auto GetVector(const char *func_name, F &&f, Ts &&... 
 // ----------- Instance Setup ------- //
 struct VkDll {
     VkResult Initialize() {
-#if defined(__linux__)
+#if defined(__unix__)
         library = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
         if (!library) library = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
 #elif defined(_WIN32)
@@ -265,7 +265,7 @@ struct VkDll {
         return VK_SUCCESS;
     }
     void Close() {
-#if defined(__linux__)
+#if defined(__unix__)
         dlclose(library);
 #elif defined(_WIN32)
         FreeLibrary(library);
@@ -427,13 +427,13 @@ struct VkDll {
    private:
     template <typename T>
     void Load(T &func_dest, const char *func_name) {
-#if defined(__linux__)
+#if defined(__unix__)
         func_dest = reinterpret_cast<T>(dlsym(library, func_name));
 #elif defined(_WIN32)
         func_dest = reinterpret_cast<T>(GetProcAddress(library, func_name));
 #endif
     }
-#if defined(__linux__)
+#if defined(__unix__)
     void *library;
 #elif defined(_WIN32)
     HMODULE library;

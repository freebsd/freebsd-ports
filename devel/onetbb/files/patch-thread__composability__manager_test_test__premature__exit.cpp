--- thread_composability_manager/test/test_premature_exit.cpp.orig	2026-10-28 16:32:17 UTC
+++ thread_composability_manager/test/test_premature_exit.cpp
@@ -19,7 +19,7 @@
 #include <cstdlib>              // for std::exit
 #include <string>
 
-#if __linux__
+#if __linux__ || __FreeBSD__
 #include <dlfcn.h>              // for dlopen, dlsym
 #elif _WIN32
 #include <Windows.h>
@@ -38,7 +38,7 @@ void load_tcm() {
 const char* api_names[] = {"tcmConnect()", "tcmRequestPermit()"};
 
 void load_tcm() {
-#if __linux__
+#if __linux__ || __FreeBSD__
     void* tcm_handler = dlopen(TCM_LIB_NAME, /*flags*/ RTLD_NOW | RTLD_LOCAL);
 #elif _WIN32
     HMODULE tcm_handler = LoadLibrary(TEXT(TCM_LIB_NAME));
@@ -46,7 +46,7 @@ void load_tcm() {
     if (NULL == tcm_handler)
         return;
 
-#if __linux__
+#if __linux__ || __FreeBSD__
     tcm_connect = (tcm_connect_t)dlsym(tcm_handler, "tcmConnect");
     tcm_request_permit = (tcm_request_permit_t)dlsym(tcm_handler, "tcmRequestPermit");
 #elif _WIN32

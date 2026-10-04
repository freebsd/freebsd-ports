--- src/tests/test_utils/common_test_utils/src/file_utils.cpp.orig	2026-04-10 13:28:49 UTC
+++ src/tests/test_utils/common_test_utils/src/file_utils.cpp
@@ -54,7 +54,7 @@ std::string getOpenvinoLibDirectoryA() {
     }
     GetModuleFileNameA(hm, (LPSTR)ov_library_path, sizeof(ov_library_path));
     return get_path_name(std::string(ov_library_path));
-#elif defined(__APPLE__) || defined(__linux__) || defined(__EMSCRIPTEN__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__)
     Dl_info info;
     dladdr(reinterpret_cast<void*>(ov::get_openvino_version), &info);
     return ov::util::path_to_string(ov::util::get_absolute_file_path(info.dli_fname).parent_path());
@@ -82,7 +82,7 @@ std::wstring getOpenvinoLibDirectoryW() {
     }
     GetModuleFileNameW(hm, (LPWSTR)ov_library_path, sizeof(ov_library_path) / sizeof(ov_library_path[0]));
     return get_path_name(std::wstring(ov_library_path));
-#    elif defined(__linux__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#    elif defined(__linux__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__)
     return ov::util::string_to_wstring(getOpenvinoLibDirectoryA());
 #    else
 #        error "Unsupported OS"
@@ -130,7 +130,7 @@ std::wstring getExecutableDirectoryW() {
     GetModuleFileNameW(hm, (LPWSTR)ov_ext_path, sizeof(ov_ext_path) / sizeof(ov_ext_path[0]));
     auto path = std::wstring(ov_ext_path);
     return ov::util::get_directory(path).wstring();
-#    elif defined(__linux__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#    elif defined(__linux__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__)
     return ov::util::string_to_wstring(getExecutableDirectoryA());
 #    else
 #        error "Unsupported OS"

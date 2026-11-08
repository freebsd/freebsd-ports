--- src/common/util/src/file_util.cpp.orig	2026-03-25 14:35:23 UTC
+++ src/common/util/src/file_util.cpp
@@ -178,7 +178,7 @@ std::filesystem::path ov::util::get_ov_lib_path() {
     GetModuleFileNameA(hm, (LPSTR)ov_library_path, sizeof(ov_library_path));
     return make_path(ov_library_path).parent_path();
 #    endif
-#elif defined(__APPLE__) || defined(__linux__) || defined(__EMSCRIPTEN__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__EMSCRIPTEN__) || (__FreeBSD__)
     Dl_info info;
     dladdr(reinterpret_cast<void*>(ov::util::get_ov_lib_path), &info);
     return ov::util::get_absolute_file_path(info.dli_fname).parent_path();

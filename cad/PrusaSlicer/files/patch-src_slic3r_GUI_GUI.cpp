--- src/slic3r/GUI/GUI.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/GUI.cpp
@@ -296,7 +296,7 @@ void desktop_open_folder(const boost::filesystem::path
 	const wxString widepath = path.wstring();
 	const wchar_t* argv[] = { L"explorer", widepath.GetData(), nullptr };
 	::wxExecute(const_cast<wchar_t**>(argv), wxEXEC_ASYNC, nullptr);
-#elif __APPLE__
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	const char* argv[] = { "open", path.string().c_str(), nullptr };
 	::wxExecute(const_cast<char**>(argv), wxEXEC_ASYNC, nullptr);
 #else
@@ -305,7 +305,7 @@ void desktop_open_folder(const boost::filesystem::path
 #endif
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 namespace {
 wxExecuteEnv get_appimage_exec_env()
 {

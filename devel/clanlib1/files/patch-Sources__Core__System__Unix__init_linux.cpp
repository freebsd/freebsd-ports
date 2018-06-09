--- Sources/Core/System/Unix/init_linux.cpp.orig	2009-03-23 00:40:42 UTC
+++ Sources/Core/System/Unix/init_linux.cpp
@@ -131,7 +131,7 @@ std::string CL_System::get_exe_path()
 
 #else
 #ifndef PROC_EXE_PATH
-#define PROC_EXE_PATH "/proc/self/exe"
+#define PROC_EXE_PATH "/proc/curproc/file"
 #endif
 	int size;
 	struct stat sb;

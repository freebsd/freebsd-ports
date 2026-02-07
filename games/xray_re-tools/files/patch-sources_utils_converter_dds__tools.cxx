--- sources/utils/converter/dds_tools.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/utils/converter/dds_tools.cxx
@@ -1,5 +1,9 @@
 #define NOMINMAX
+#ifdef _WIN32
 #include <windows.h>
+#else
+#include <dirent.h>
+#endif
 #include <cstring>
 #include "dds_tools.h"
 #include "xr_image.h"
@@ -82,6 +86,7 @@ void dds_tools::process_file(const std::string& path)
 
 void dds_tools::process_folder(const std::string& path)
 {
+#ifdef _WIN32
 	WIN32_FIND_DATAA info;
 	HANDLE h = FindFirstFileA((m_textures + path + '*').c_str(), &info);
 	if (h == INVALID_HANDLE_VALUE)
@@ -95,6 +100,21 @@ void dds_tools::process_folder(const std::string& path
 		}
 	} while (FindNextFileA(h, &info));
 	FindClose(h);
+#else
+	DIR *dp;
+	struct dirent *de;
+	dp = opendir((m_textures + path).c_str());
+	while ((de = readdir(dp)) != NULL) {
+		if (de->d_type == DT_DIR) {
+			if (strcmp(de->d_name, ".") != 0 &&
+			    strcmp(de->d_name, "..") != 0)
+				process_folder((path + de->d_name) + '/');
+		} else {
+			process_file(path + de->d_name);
+		}
+	}
+	(void)closedir(dp);
+#endif
 }
 
 void dds_tools::process(const cl_parser& cl)

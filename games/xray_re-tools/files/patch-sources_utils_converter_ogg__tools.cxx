--- sources/utils/converter/ogg_tools.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/utils/converter/ogg_tools.cxx
@@ -1,5 +1,10 @@
 #define NOMINMAX
+#ifdef _WIN32
 #include <windows.h>
+#else
+#include <dirent.h>
+#include <errno.h>
+#endif
 #include "ogg_tools.h"
 #include "xr_types.h"
 #include "xr_file_system.h"
@@ -277,6 +282,7 @@ void ogg_tools::process_file(const std::string& path)
 
 void ogg_tools::process_folder(const std::string& path)
 {
+#ifdef _WIN32
 	WIN32_FIND_DATAA info;
 	HANDLE h = FindFirstFileA((m_sounds + path + '*').c_str(), &info);
 	if (h == INVALID_HANDLE_VALUE)
@@ -290,6 +296,21 @@ void ogg_tools::process_folder(const std::string& path
 		}
 	} while (FindNextFileA(h, &info));
 	FindClose(h);
+#else
+	DIR *dp;
+	struct dirent *de;
+	dp = opendir((m_sounds + path).c_str());
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
 
 void ogg_tools::process(const cl_parser& cl)

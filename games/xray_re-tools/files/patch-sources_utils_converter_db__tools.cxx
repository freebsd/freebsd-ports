--- sources/utils/converter/db_tools.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/utils/converter/db_tools.cxx
@@ -1,6 +1,10 @@
 #define NOMINMAX
-#include <windows.h>
 #include <cstring>
+#ifdef _WIN32
+#include <windows.h>
+#else
+#include <dirent.h>
+#endif
 #include "db_tools.h"
 #include "xr_scrambler.h"
 #include "xr_lzhuf.h"
@@ -10,7 +14,9 @@
 #include "lzo/minilzo.h"
 #include "crc32/crc32.h"
 
+#ifndef DB_DEBUG
 #define DB_DEBUG	0
+#endif
 
 using namespace xray_re;
 
@@ -163,7 +169,7 @@ static bool write_file(xr_file_system& fs, const std::
 		lzo_uint size = size_real;
 		uint8_t* temp = new uint8_t[size];
 		if (lzo1x_decompress_safe(data, size_compressed, temp, &size, 0) != LZO_E_OK) {
-			delete temp;
+			delete[] temp;
 			return false;
 		}
 		data = temp;
@@ -432,6 +438,7 @@ void db_packer::process_folder(const std::string& path
 		m_folders.push_back(path);
 	}
 found:
+#ifdef _WIN32
 	WIN32_FIND_DATAA info;
 	HANDLE h = FindFirstFileA((m_root + path + '*').c_str(), &info);
 	if (h == INVALID_HANDLE_VALUE)
@@ -446,6 +453,21 @@ found:
 		}
 	} while (FindNextFileA(h, &info));
 	FindClose(h);
+#else
+	DIR *dp;
+	struct dirent *de;
+	dp = opendir((m_root + path).c_str());
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
 
 void db_packer::process_file(const std::string& path)

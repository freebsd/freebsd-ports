--- src/system/FileUtility.cpp.orig	2009-10-19 05:14:24.000000000 +0400
+++ src/system/FileUtility.cpp	2009-10-25 22:04:22.000000000 +0300
@@ -22,8 +22,8 @@
 			if (!(ep->data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
 			files++;
 #endif //_WIN32W
-#ifdef linux
-			if (ep->d_type == 0x8)
+#ifdef __FreeBSD__
+			if (ep->d_type == DT_REG)
 				files++;
 #endif //linux
 		(void) closedir(dp);
@@ -49,13 +49,9 @@
 	m_usrPath = m_resPath;
 	delete[] exePath;
 #endif //_WIN32
-#ifdef linux
-	char result[PATH_MAX];
-	readlink("/proc/self/exe", result, PATH_MAX);
-	FileUtility::truncateFullPathToDir(result);
-	m_appPath = result;
-	m_resPath = m_appPath;
-	m_resPath.append("/../share/violetland/");
+#ifdef __FreeBSD__
+	m_appPath = "%%PREFIX%%/bin";
+	m_resPath = "%%PREFIX%%/share/violetland/";
 	m_usrPath = getenv("HOME");
 	m_usrPath.append("/.config");
 	mkdir(m_usrPath.c_str(), S_IRWXU | S_IRGRP | S_IROTH);

--- libraries/systeminfo/src/sys_unix.cpp.orig	2019-03-09 17:25:33 UTC
+++ libraries/systeminfo/src/sys_unix.cpp
@@ -18,6 +18,7 @@ Sys::KernelInfo Sys::getKernelInfo()
 uint64_t Sys::getSystemRam()
 {
     std::string token;
+	#ifdef Q_OS_LINUX
     std::ifstream file("/proc/meminfo");
     while(file >> token)
     {
@@ -36,6 +37,19 @@ uint64_t Sys::getSystemRam()
         // ignore rest of the line
         file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     }
+	#elif defined Q_OS_FREEBSD
+	char buff[512];
+	FILE *fp = popen("sysctl hw.physmem", "r");
+	if (fp != NULL)
+	{
+		while(fgets(buff, 512, fp) != NULL)
+		{
+			std::string str(buff);
+			uint64_t mem = std::stoull(str.substr(12, std::string::npos));
+			return mem * 1024ull;
+		}
+	}
+	#endif
     return 0; // nothing found
 }
 

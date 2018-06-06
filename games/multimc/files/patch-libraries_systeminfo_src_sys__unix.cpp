--- libraries/systeminfo/src/sys_unix.cpp.orig	2017-12-18 00:19:43 UTC
+++ libraries/systeminfo/src/sys_unix.cpp
@@ -16,6 +16,7 @@ Sys::KernelInfo Sys::getKernelInfo()
 uint64_t Sys::getSystemRam()
 {
 	std::string token;
+	#ifdef Q_OS_LINUX
 	std::ifstream file("/proc/meminfo");
 	while(file >> token)
 	{
@@ -34,6 +35,19 @@ uint64_t Sys::getSystemRam()
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
 
@@ -43,7 +57,9 @@ bool Sys::isCPU64bit()
 }
 
 bool Sys::isSystem64bit()
-{
+{	
+	#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	// kernel build arch on linux
 	return QSysInfo::currentCpuArchitecture() == "x86_64";
+	#endif
 }

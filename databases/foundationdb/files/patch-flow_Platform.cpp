--- flow/Platform.cpp.orig	2019-01-09 22:28:32 UTC
+++ flow/Platform.cpp
@@ -71,6 +71,7 @@
 
 #include <dirent.h>
 #include <sys/time.h>
+#include <sys/user.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <ftw.h>
@@ -119,7 +120,13 @@
 #include <IOKit/IOBSD.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/cpuset.h>
+#include <sys/resource.h>
 #endif
+#endif
 
 std::string removeWhitespace(const std::string &t)
 {
@@ -198,7 +205,7 @@ double getProcessorTimeThread() {
 		throw platform_error();
 	}
 	return FiletimeAsInt64(ftKernel) / double(1e7) + FiletimeAsInt64(ftUser) / double(1e7);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	return getProcessorTimeGeneric(RUSAGE_THREAD);
 #elif defined(__APPLE__)
 	/* No RUSAGE_THREAD so we use the lower level interface */
@@ -266,6 +273,14 @@ uint64_t getResidentMemoryUsage() {
 		throw platform_error();
 	}
 	return info.resident_size;
+#elif defined(__FreeBSD__)
+	struct rusage rusage;
+
+	if (getrusage(RUSAGE_SELF | RUSAGE_THREAD, &rusage) == 0) {
+		return rusage.ru_maxrss;
+	}
+
+	return 0;
 #else
 	#warning getMemoryUsage unimplemented on this platform
 	return 0;
@@ -304,7 +319,7 @@ uint64_t getMemoryUsage() {
 	}
 	return info.virtual_size;
 #else
-	#warning getMemoryUsage unimplemented on this platform
+	//#warning getMemoryUsage unimplemented on this platform
 	return 0;
 #endif
 }
@@ -427,6 +442,24 @@ void getMachineRAMInfo(MachineRAMInfo& memInfo) {
 	memInfo.total = pagesize * (vm_stat.free_count + vm_stat.active_count + vm_stat.inactive_count + vm_stat.wire_count);
 	memInfo.available = pagesize * vm_stat.free_count;
 	memInfo.committed = memInfo.total - memInfo.available;
+#elif defined(__FreeBSD__)
+	size_t len;
+	int pagesize = getpagesize(), free_pages;
+	u_long total;
+
+	len = sizeof(total);
+	if (sysctlbyname("hw.physmem", &total, &len, NULL, 0) == -1)
+		total = 0;
+
+	total = total / 1024;
+
+	len = sizeof(free_pages);
+	if((sysctlbyname("vm.stats.vm.v_free_count", &free_pages, &len, NULL, 0) == -1) || !len)
+		free_pages = 0;
+
+	memInfo.total = total;
+	memInfo.available = (pagesize / 1024) * free_pages;
+	memInfo.committed = memInfo.total - memInfo.available;
 #else
 	#warning getMachineRAMInfo unimplemented on this platform
 #endif
@@ -451,7 +484,7 @@ Error systemErrorCodeToError() {
 void getDiskBytes(std::string const& directory, int64_t& free, int64_t& total) {
 	INJECT_FAULT( platform_error, "getDiskBytes" );
 #if defined(__unixish__)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	struct statvfs buf;
 	if (statvfs(directory.c_str(), &buf)) {
 		Error e = systemErrorCodeToError();
@@ -497,7 +530,7 @@ void getDiskBytes(std::string const& directory, int64_
 #endif
 }
 
-#ifdef __unixish__
+#if defined(__linux__) || defined(__APPLE__)
 const char* getInterfaceName(uint32_t _ip) {
 	INJECT_FAULT( platform_error, "getInterfaceName" );
 	static char iname[20];
@@ -744,6 +777,30 @@ dev_t getDeviceId(std::string path) {
 
 #endif
 
+#ifdef __FreeBSD__
+void getNetworkTraffic(uint32_t ip, uint64_t& bytesSent, uint64_t& bytesReceived,
+		uint64_t& outSegs, uint64_t& retransSegs) {
+	bytesReceived = 0;
+	bytesSent = 0;
+	outSegs = 0;
+	retransSegs = 0;
+}
+
+void getMachineLoad(uint64_t& idleTime, uint64_t& totalTime) {
+	idleTime = 0;
+	totalTime = 0;
+}
+
+void getDiskStatistics(std::string const& directory, uint64_t& currentIOs, uint64_t& busyTicks, uint64_t& reads, uint64_t& writes, uint64_t& writeSectors, uint64_t& readSectors) {
+	currentIOs = 0;
+	busyTicks = 0;
+	writes = 0;
+	reads = 0;
+	writeSectors = 0;
+	readSectors = 0;
+}
+#endif
+
 #ifdef __APPLE__
 void getNetworkTraffic(uint32_t ip, uint64_t& bytesSent, uint64_t& bytesReceived,
 					   uint64_t& outSegs, uint64_t& retransSegs) {
@@ -1268,7 +1325,7 @@ struct OffsetTimer {
 		return offset + count * secondsPerCount;
 	}
 };
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define DOUBLETIME(ts) (double(ts.tv_sec) + (ts.tv_nsec * 1e-9))
 #ifndef CLOCK_MONOTONIC_RAW
 #define CLOCK_MONOTONIC_RAW 4 // Confirmed safe to do with glibc >= 2.11 and kernel >= 2.6.28. No promises with older glibc. Older kernel definitely breaks it.
@@ -1333,7 +1390,7 @@ double timer() {
 	GetSystemTimeAsFileTime(&fileTime);
 	static_assert( sizeof(fileTime) == sizeof(uint64_t), "FILETIME size wrong" );
 	return (*(uint64_t*)&fileTime - FILETIME_C_EPOCH) * 100e-9;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	struct timespec ts;
 	clock_gettime(CLOCK_REALTIME, &ts);
 	return double(ts.tv_sec) + (ts.tv_nsec * 1e-9);
@@ -1353,7 +1410,7 @@ uint64_t timer_int() {
 	GetSystemTimeAsFileTime(&fileTime);
 	static_assert( sizeof(fileTime) == sizeof(uint64_t), "FILETIME size wrong" );
 	return (*(uint64_t*)&fileTime - FILETIME_C_EPOCH);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	struct timespec ts;
 	clock_gettime(CLOCK_REALTIME, &ts);
 	return uint64_t(ts.tv_sec) * 1e9 + ts.tv_nsec;
@@ -1502,7 +1559,7 @@ static void *allocateInternal(size_t length, bool larg
 		flags |= MAP_HUGETLB;
 
 	return mmap(NULL, length, PROT_READ|PROT_WRITE, flags, -1, 0);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	int flags = MAP_PRIVATE|MAP_ANON;
 
 	return mmap(NULL, length, PROT_READ|PROT_WRITE, flags, -1, 0);
@@ -1576,6 +1633,11 @@ void setAffinity(int proc) {
 	CPU_ZERO(&set);
 	CPU_SET(proc, &set);
 	sched_setaffinity(0, sizeof(cpu_set_t), &set);
+#elif defined(__FreeBSD__)
+	cpuset_t set;
+	CPU_ZERO(&set);
+	CPU_SET(proc, &set);
+	cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1, sizeof(set), &set);
 #endif
 }
 
@@ -1636,7 +1698,7 @@ void renameFile( std::string const& fromPath, std::str
 		//renamedFile();
 		return;
 	}
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	if (!rename( fromPath.c_str(), toPath.c_str() )) {
 		//FIXME: We cannot inject faults after renaming the file, because we could end up with two asyncFileNonDurable open for the same file
 		//renamedFile();
@@ -1759,7 +1821,7 @@ bool createDirectory( std::string const& directory ) {
 	Error e = systemErrorCodeToError();
 	TraceEvent(SevError, "CreateDirectory").detail("Directory", directory).GetLastError().error(e);
 	throw e;
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	size_t sep = 0;
 	do {
 		sep = directory.find_first_of('/', sep + 1);
@@ -1804,7 +1866,7 @@ std::string abspath( std::string const& filename ) {
 		if (*x == '/')
 			*x = CANONICAL_PATH_SEPARATOR;
 	return nameBuffer;
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	char result[PATH_MAX];
 	auto r = realpath( filename.c_str(), result );
 	if (!r) {
@@ -1870,7 +1932,7 @@ std::string getUserHomeDirectory() {
 
 #ifdef _WIN32
 #define FILE_ATTRIBUTE_DATA DWORD
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 #define FILE_ATTRIBUTE_DATA mode_t
 #else
 #error Port me!
@@ -1879,7 +1941,7 @@ std::string getUserHomeDirectory() {
 bool acceptFile( FILE_ATTRIBUTE_DATA fileAttributes, std::string name, std::string extension ) {
 #ifdef _WIN32
 	return !(fileAttributes & FILE_ATTRIBUTE_DIRECTORY) && StringRef(name).endsWith(extension);
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	return S_ISREG(fileAttributes) && StringRef(name).endsWith(extension);
 #else
 	#error Port me!
@@ -1889,7 +1951,7 @@ bool acceptFile( FILE_ATTRIBUTE_DATA fileAttributes, s
 bool acceptDirectory( FILE_ATTRIBUTE_DATA fileAttributes, std::string name, std::string extension ) {
 #ifdef _WIN32
 	return (fileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	return S_ISDIR(fileAttributes);
 #else
 	#error Port me!
@@ -1925,7 +1987,7 @@ std::vector<std::string> findFiles( std::string const&
 		}
 		FindClose(h);
 	}
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	DIR *dip;
 
 	if ((dip = opendir(directory.c_str())) != NULL) {
@@ -1989,7 +2051,7 @@ void findFilesRecursively(std::string path, std::vecto
 void threadSleep( double seconds ) {
 #ifdef _WIN32
 	Sleep( (DWORD)(seconds * 1e3) );
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	struct timespec req, rem;
 
 	req.tv_sec = seconds;
@@ -2027,7 +2089,7 @@ void makeTemporary( const char* filename ) {
 THREAD_HANDLE startThread(void (*func) (void *), void *arg) {
 	return (void *)_beginthread(func, 0, arg);
 }
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 THREAD_HANDLE startThread(void *(*func) (void *), void *arg) {
 	pthread_t t;
 	pthread_create(&t, NULL, func, arg);
@@ -2040,7 +2102,7 @@ THREAD_HANDLE startThread(void *(*func) (void *), void
 void waitThread(THREAD_HANDLE thread) {
 #ifdef _WIN32
 	WaitForSingleObject(thread, INFINITE);
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	pthread_join(thread, NULL);
 #else
 	#error Port me!
@@ -2082,7 +2144,7 @@ int64_t fileSize(std::string const& filename) {
 		return 0;
 	else
 		return file_status.st_size;
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 	struct stat file_status;
 	if(stat(filename.c_str(), &file_status) != 0)
 		return 0;
@@ -2225,6 +2287,8 @@ std::string getDefaultPluginPath( const char* plugin_n
 	return format( "/usr/lib/foundationdb/plugins/%s.so", plugin_name );
 #elif defined(__APPLE__)
 	return format( "/usr/local/foundationdb/plugins/%s.dylib", plugin_name );
+#elif defined(__FreeBSD__)
+	return format( "/usr/local/lib/foundationdb/plugins/%s.so", plugin_name );
 #else
 	#error Port me!
 #endif
@@ -2475,7 +2539,7 @@ void* getImageOffset() { return NULL; }
 #endif
 
 bool isLibraryLoaded(const char* lib_path) {
-#if !defined(__linux__) && !defined(__APPLE__) && !defined(_WIN32)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(__FreeBSD__)
 #error Port me!
 #endif
 
@@ -2491,7 +2555,7 @@ bool isLibraryLoaded(const char* lib_path) {
 }
 
 void* loadLibrary(const char* lib_path) {
-#if !defined(__linux__) && !defined(__APPLE__) && !defined(_WIN32)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(_WIN32) && !defined(__FreeBSD__)
 #error Port me!
 #endif
 

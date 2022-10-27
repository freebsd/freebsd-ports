--- common/Linux/LnxHostSys.cpp.orig	2022-10-20 13:57:30 UTC
+++ common/Linux/LnxHostSys.cpp
@@ -153,7 +153,12 @@ void HostSys::MemProtect(void* baseaddr, size_t size, 
 std::string HostSys::GetFileMappingName(const char* prefix)
 {
 	const unsigned pid = static_cast<unsigned>(getpid());
+#if defined(__FreeBSD__)
+	// FreeBSD's shm_open(3) requires name to be absolute
+	return fmt::format("/tmp/{}_{}", prefix, pid);
+#else
 	return fmt::format("{}_{}", prefix, pid);
+#endif
 }
 
 void* HostSys::CreateSharedMemory(const char* name, size_t size)
@@ -169,7 +174,7 @@ void* HostSys::CreateSharedMemory(const char* name, si
 	shm_unlink(name);
 
 	// ensure it's the correct size
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 	if (ftruncate64(fd, static_cast<off64_t>(size)) < 0)
 #else
 	if (ftruncate(fd, static_cast<off_t>(size)) < 0)

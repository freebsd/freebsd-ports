--- common/include/Utilities/General.h.orig	2020-10-29 23:31:05 UTC
+++ common/include/Utilities/General.h
@@ -257,7 +257,7 @@ void MemProtectStatic(u8 (&arr)[size], const PageProte
 
 // Safe version of Munmap -- NULLs the pointer variable immediately after free'ing it.
 #define SafeSysMunmap(ptr, size) \
-    ((void)(HostSys::Munmap((uptr)(ptr), size), (ptr) = NULL))
+    ((void)(HostSys::Munmap((uptr)(ptr), size), (ptr) = 0))
 
 extern void InitCPUTicks();
 extern u64 GetTickFrequency();

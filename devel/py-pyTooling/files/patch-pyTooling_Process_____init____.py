-- Add a minimal FreeBSD process-memory implementation so the upstream 9.0.0
-- test suite can run on FreeBSD arm64 builders. Upstream lacks a FreeBSD
-- branch here and otherwise aborts during module import.
--- pyTooling/Process/__init__.py.orig	2026-09-17 20:37:56 UTC
+++ pyTooling/Process/__init__.py
@@ -114,6 +114,8 @@ class ProcessInformation(metaclass=ExtendedType, slots
 		_processHandle: Any
 	elif CurrentPlatform.IsNativeLinux:
 		_processStatusFile: ClassVar[Path] = Path(f"/proc/self/statm")
+	elif CurrentPlatform.IsNativeFreeBSD:
+		pass
 
 	if CurrentPlatform.IsNativeWindows or CurrentPlatform.IsMSYS2Environment:
 		def __init__(self) -> None:
@@ -182,6 +184,22 @@ class ProcessInformation(metaclass=ExtendedType, slots
 			rss = int(fields[1]) * self._pageSize  #: VmRSS
 
 			return MemoryInfo(rss, vms)
+
+	elif CurrentPlatform.IsNativeFreeBSD:
+		def GetMemoryUsage(self) -> MemoryInfo:
+			"""
+			Get the memory usage of this Python process on a FreeBSD system.
+
+			``resource.getrusage`` provides the resident size portably on FreeBSD.
+			Virtual memory usage is not exposed by the stdlib here, so report ``0``
+			for the virtual component until upstream adds a native implementation.
+
+			:returns: Memory usage of the current process.
+			"""
+			from resource import RUSAGE_SELF, getrusage
+
+			rss = getrusage(RUSAGE_SELF).ru_maxrss * 1024
+			return MemoryInfo(rss, 0)
 
 	elif CurrentPlatform.IsNativeMacOS:
 		class _ProcTaskInfo(Structure):

Implement Linux-like memory stats for BSDs

--- source/ramlib/ram.c.orig	2011-04-08 16:22:58 UTC
+++ source/ramlib/ram.c
@@ -27,6 +27,21 @@
 #include <mach/task.h>
 #include <mach/mach.h>
 #include <mach/mach_init.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || \
+  defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+# if defined(__DragonFly__)
+#include <sys/kinfo.h>      // struct kinfo_proc
+#include <sys/vmmeter.h>    // struct vmstats
+# elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <sys/user.h>       // struct kinfo_proc
+# elif defined(__NetBSD__)
+#include <uvm/uvm_extern.h> // struct uvmexp_sysctl
+# elif defined(__OpenBSD__)
+#include <uvm/uvmexp.h>     // struct uvmexp
+# endif
 #elif LINUX
 #include <sys/sysinfo.h>
 #include <unistd.h>
@@ -54,12 +69,22 @@ static u64 systemRam = 0x00000000;
 #ifndef WIN
 #ifndef XBOX
 #ifndef LINUX
+#ifndef __DragonFly__
+#ifndef __FreeBSD__
+#ifndef __FreeBSD_kernel__
+#ifndef __NetBSD__
+#ifndef __OpenBSD__
 static unsigned long elfOffset = 0x00000000;
 static unsigned long stackSize = 0x00000000;
 #endif
 #endif
 #endif
 #endif
+#endif
+#endif
+#endif
+#endif
+#endif
 
 /////////////////////////////////////////////////////////////////////////////
 // Symbols
@@ -68,6 +93,11 @@ static unsigned long stackSize = 0x00000
 #ifndef WIN
 #ifndef XBOX
 #ifndef LINUX
+#ifndef __DragonFly__
+#ifndef __FreeBSD__
+#ifndef __FreeBSD_kernel__
+#ifndef __NetBSD__
+#ifndef __OpenBSD__
 #if (__GNUC__ > 3)
 extern unsigned long _end;
 extern unsigned long _start;
@@ -81,6 +111,11 @@ extern unsigned long start;
 #endif
 #endif
 #endif
+#endif
+#endif
+#endif
+#endif
+#endif
 
 /////////////////////////////////////////////////////////////////////////////
 //  Functions
@@ -101,6 +136,49 @@ u64 getFreeRam(int byte_size)
 	if(host_page_size(hostPort, &size) != KERN_SUCCESS) return 0;
 	if(host_statistics(hostPort, HOST_VM_INFO, (host_info_t)&vms, &count) != KERN_SUCCESS) return 0;
 	return (u64)(((vms.inactive_count+vms.free_count)*size)/byte_size);
+#elif defined(__DragonFly__)
+	struct vmstats vms;
+	size_t sz = sizeof(vms);
+	if (sysctlbyname("vm.vmstats", &vms, &sz, NULL, 0))
+	{
+		return 0;
+	}
+	return (u64)((vms.v_free_count + vms.v_inactive_count
+				  + vms.v_cache_count) * getpagesize()) / byte_size;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+	u_int v_free_count, v_inactive_count, v_cache_count;
+	size_t sz = sizeof(u_int);
+	v_free_count = v_inactive_count = v_cache_count = 0;
+	sysctlbyname("vm.stats.vm.v_free_count",
+				 &v_free_count, &sz, NULL, 0);
+	sysctlbyname("vm.stats.vm.v_inactive_count",
+				 &v_inactive_count, &sz, NULL, 0);
+	sysctlbyname("vm.stats.vm.v_cache_count",
+				 &v_cache_count, &sz, NULL, 0);
+	return (u64)((v_free_count + v_inactive_count + v_cache_count)
+				 * getpagesize()) / byte_size;
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
+# if defined(__NetBSD__)
+#undef VM_UVMEXP
+#define VM_UVMEXP VM_UVMEXP2
+#define uvmexp uvmexp_sysctl
+# else
+#define filepages vnodepages
+#define execpages vtextpages
+# endif
+	int mib[] = {
+		CTL_VM,
+		VM_UVMEXP,
+	};
+	u_int miblen = sizeof(mib) / sizeof(mib[0]);
+	struct uvmexp uvmexp;
+	size_t sz = sizeof(uvmexp);
+	if (sysctl(mib, miblen, &uvmexp, &sz, NULL, 0))
+	{
+		return 0;
+	}
+	return (u64)((uvmexp.free + uvmexp.inactive + uvmexp.filepages
+				  + uvmexp.execpages) * uvmexp.pagesize) / byte_size;
 #elif LINUX
 	struct sysinfo info;
 	sysinfo(&info);
@@ -138,11 +216,29 @@ void setSystemRam()
 	stat.dwLength = sizeof(MEMORYSTATUS);
 	GlobalMemoryStatus(&stat);
 	systemRam = stat.dwTotalPhys;
-#elif DARWIN
-	u64 mem;
-	size_t len = sizeof(mem);
-	sysctlbyname("hw.memsize", &mem, &len, NULL, 0);
-	systemRam = mem;
+#elif defined(DARWIN) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+  defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
+# if defined(HW_MEMSIZE) || defined(HW_PHYSMEM64)
+	uint64_t physmem;
+# else
+	u_long physmem;
+# endif
+	int mib[] = {
+		CTL_HW,
+# if defined(HW_MEMSIZE)
+		HW_MEMSIZE,
+# elif defined(HW_PHYSMEM64)
+		HW_PHYSMEM64,
+# else
+		HW_PHYSMEM,
+# endif
+	};
+	size_t sz = sizeof(physmem);
+	if (sysctl(mib, 2, &physmem, &sz, NULL, 0))
+	{
+		physmem = 0;
+	}
+	systemRam = physmem;
 #elif LINUX
 	struct sysinfo info;
 	sysinfo(&info);
@@ -183,12 +279,22 @@ void setSystemRam()
 #ifndef XBOX
 #ifndef LINUX
 #ifndef SYMBIAN
+#ifndef __DragonFly__
+#ifndef __FreeBSD__
+#ifndef __FreeBSD_kernel__
+#ifndef __NetBSD__
+#ifndef __OpenBSD__
 	stackSize = (int)&_end - (int)&_start + ((int)&_start - elfOffset);
 #endif
 #endif
 #endif
 #endif
 #endif
+#endif
+#endif
+#endif
+#endif
+#endif
 	getRamStatus(BYTES);
 }
 
@@ -215,6 +321,42 @@ u64 getUsedRam(int byte_size)
 	rval = task_info(task, TASK_BASIC_INFO, tptr, &tcnt);
 	if (!(rval == KERN_SUCCESS)) return 0;
 	return info.resident_size/byte_size;
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || \
+  defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
+# if defined(__NetBSD__)
+#undef KERN_PROC
+#define KERN_PROC KERN_PROC2
+#define KINFO_PROC struct kinfo_proc2
+# else
+#define KINFO_PROC struct kinfo_proc
+# endif
+# if defined(__DragonFly__)
+#define KP_RSS(kp) (kp.kp_vm_rssize * getpagesize())
+# elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#define KP_RSS(kp) (kp.ki_rssize * getpagesize())
+# elif defined(__NetBSD__)
+#define KP_RSS(kp) (kp.p_vm_rssize * getpagesize())
+# elif defined(__OpenBSD__)
+#define KP_RSS(kp) (kp.p_vm_rssize * getpagesize())
+# endif
+	int mib[] = {
+		CTL_KERN,
+		KERN_PROC,
+		KERN_PROC_PID,
+		getpid(),
+# if defined(__NetBSD__) || defined(__OpenBSD__)
+		sizeof(KINFO_PROC),
+		1,
+# endif
+	};
+	u_int miblen = sizeof(mib) / sizeof(mib[0]);
+	KINFO_PROC kp;
+	size_t sz = sizeof(KINFO_PROC);
+	if (sysctl(mib, miblen, &kp, &sz, NULL, 0))
+	{
+		return 0;
+	}
+	return (u64)KP_RSS(kp) / byte_size;
 #elif LINUX
 	unsigned long vm = 0;
 	FILE *file = fopen("/proc/self/statm", "r");

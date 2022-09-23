--- lib/igt_os.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_os.c
@@ -44,6 +44,9 @@
 #include <sys/sysinfo.h>
 #elif defined(HAVE_SWAPCTL) /* Solaris */
 #include <sys/swap.h>
+#elif defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#include <sys/types.h>
 #endif
 #include <sys/resource.h>
 
@@ -148,6 +151,15 @@ igt_get_avail_ram_mb(void)
 	npages = sysconf(_SC_AVPHYS_PAGES);
 
 	retval = (uint64_t) pagesize * npages;
+#elif defined(__FreeBSD__) /* FreeBSD */
+	uint64_t npages, pagesize;
+	size_t npages_len = sizeof(npages);
+	size_t pagesize_len = sizeof(pagesize);
+
+	sysctlbyname("vm.stats.vm.v_free_count", &npages, &npages_len, NULL, 0);
+	sysctlbyname("vm.stats.vm.v_page_size", &pagesize, &pagesize_len, NULL, 0);
+
+	retval = pagesize * npages;
 #else
 #error "Unknown how to get available RAM for this OS"
 #endif
@@ -210,6 +222,13 @@ igt_get_total_swap_mb(void)
 	free(buf);
 
 	retval = (uint64_t) pagesize * totalpages;
+#elif defined(__FreeBSD__) /* FreeBSD */
+	uint64_t swap_total;
+	size_t swap_total_len = sizeof(swap_total);
+
+	sysctlbyname("vm.swap_total", &swap_total, &swap_total_len, NULL, 0);
+
+	retval = swap_total;
 #else
 #warning "Unknown how to get swap size for this OS"
 	return 0;

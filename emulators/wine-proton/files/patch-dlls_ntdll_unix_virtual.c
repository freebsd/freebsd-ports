--- dlls/ntdll/unix/virtual.c.orig	2024-04-26 15:24:41 UTC
+++ dlls/ntdll/unix/virtual.c
@@ -64,9 +64,11 @@
 # include <mach/mach_vm.h>
 #endif
 
+#ifdef __linux__
 #include <linux/userfaultfd.h>
 #include <sys/ioctl.h>
 #include "uffd_tmp_defs.h"
+#endif
 
 #include <sys/uio.h>
 
@@ -258,6 +260,7 @@ void *anon_mmap_alloc( size_t size, int prot )
     return mmap( NULL, size, prot, MAP_PRIVATE | MAP_ANON, -1, 0 );
 }
 
+#ifdef __linux__
 static void kernel_writewatch_softdirty_init(void)
 {
     if ((pagemap_reset_fd = open( "/proc/self/pagemap_reset", O_RDONLY | O_CLOEXEC )) == -1) return;
@@ -494,7 +497,27 @@ static NTSTATUS kernel_get_write_watches( void *base, 
     }
     return STATUS_SUCCESS;
 }
+#else
+static void kernel_writewatch_init(void)
+{
+    use_kernel_writewatch = 0;
+}
 
+static void kernel_writewatch_register_range(struct file_view*, void*, size_t)
+{
+    /* do nothing */
+}
+
+static void kernel_writewatch_reset(void*, SIZE_T)
+{
+    abort();
+}
+
+static NTSTATUS kernel_get_write_watches(void*, SIZE_T, void**, ULONG_PTR*, BOOL)
+{
+    abort();
+}
+#endif
 
 static void mmap_add_reserved_area( void *addr, SIZE_T size )
 {

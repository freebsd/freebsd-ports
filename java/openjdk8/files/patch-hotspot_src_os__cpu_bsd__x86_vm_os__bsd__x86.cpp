--- hotspot/src/os_cpu/bsd_x86/vm/os_bsd_x86.cpp.orig	2019-08-11 09:24:22.211149000 -0700
+++ hotspot/src/os_cpu/bsd_x86/vm/os_bsd_x86.cpp	2019-08-11 09:25:08.826582000 -0700
@@ -470,6 +470,9 @@
     // Handle ALL stack overflow variations here
     if (sig == SIGSEGV || sig == SIGBUS) {
       address addr = (address) info->si_addr;
+#ifdef __FreeBSD__
+      addr = (unsigned char*) align_ptr_down(addr, os::vm_page_size());
+#endif
 
       // check if fault address is within thread stack
       if (addr < thread->stack_base() &&

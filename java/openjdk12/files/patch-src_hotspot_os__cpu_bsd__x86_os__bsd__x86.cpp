--- src/hotspot/os_cpu/bsd_x86/os_bsd_x86.cpp
+++ src/hotspot/os_cpu/bsd_x86/os_bsd_x86.cpp
@@ -510,6 +510,9 @@ JVM_handle_bsd_signal(int sig,
     // Handle ALL stack overflow variations here
     if (sig == SIGSEGV || sig == SIGBUS) {
       address addr = (address) info->si_addr;
+#ifdef __FreeBSD__
+      addr = align_down(addr, os::vm_page_size());
+#endif
 
       // check if fault address is within thread stack
       if (thread->on_local_stack(addr)) {

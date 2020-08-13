--- src/os/darwin/darwin_sigar.c.orig	2014-11-17 21:46:20 UTC
+++ src/os/darwin/darwin_sigar.c
@@ -123,6 +123,69 @@
 #endif
 
 #if defined(SIGAR_FREEBSD5)
+#if __FreeBSD_version >= 1200028
+#define	VMMETER_TYPE	uint64_t
+#else
+#define	VMMETER_TYPE	u_int
+#endif
+struct __vmmeter {
+	VMMETER_TYPE v_vm_faults;
+	VMMETER_TYPE v_io_faults;
+	VMMETER_TYPE v_cow_faults;
+	VMMETER_TYPE v_cow_optim;
+	VMMETER_TYPE v_zfod;
+	VMMETER_TYPE v_ozfod;
+	VMMETER_TYPE v_swapin;
+	VMMETER_TYPE v_swapout;
+	VMMETER_TYPE v_swappgsin;
+	VMMETER_TYPE v_swappgsout;
+	VMMETER_TYPE v_vnodein;
+	VMMETER_TYPE v_vnodeout;
+	VMMETER_TYPE v_vnodepgsin;
+	VMMETER_TYPE v_vnodepgsout;
+	VMMETER_TYPE v_intrans;
+	VMMETER_TYPE v_reactivated;
+	VMMETER_TYPE v_pdwakeups;
+	VMMETER_TYPE v_pdpages;
+	VMMETER_TYPE v_pdshortfalls;
+	VMMETER_TYPE v_dfree;
+	VMMETER_TYPE v_pfree;
+	VMMETER_TYPE v_tfree;
+	VMMETER_TYPE v_forks;
+	VMMETER_TYPE v_vforks;
+	VMMETER_TYPE v_rforks;
+	VMMETER_TYPE v_kthreads;
+	VMMETER_TYPE v_forkpages;
+	VMMETER_TYPE v_vforkpages;
+	VMMETER_TYPE v_rforkpages;
+	VMMETER_TYPE v_kthreadpages;
+	VMMETER_TYPE v_swtch;
+	VMMETER_TYPE v_syscall;
+	VMMETER_TYPE v_trap;
+	VMMETER_TYPE v_intr;
+	VMMETER_TYPE v_soft;
+	u_int v_page_size;
+	u_int v_page_count;
+	u_int v_free_reserved;
+	u_int v_free_target;
+	u_int v_free_min;
+	u_int v_free_count;
+	u_int v_wire_count;
+	u_int v_active_count;
+	u_int v_inactive_target;
+	u_int v_inactive_count;
+	u_int v_laundry_count;
+	u_int v_pageout_free_min;
+	u_int v_interrupt_free_min;
+	u_int v_free_severe;
+#if (__FreeBSD_version < 1200016)
+	u_int v_cache_count;
+#endif
+#if (__FreeBSD_version < 1100079)
+	u_int v_cache_min;
+	u_int v_cache_max;
+#endif
+};
 
 #define KI_FD   ki_fd
 #define KI_PID  ki_pid
@@ -342,24 +405,21 @@ static int sigar_vmstat(sigar_t *sigar, vm_statistics_
     }
 }
 #elif defined(__FreeBSD__)
-static int sigar_vmstat(sigar_t *sigar, struct vmmeter *vmstat)
+static int sigar_vmstat(sigar_t *sigar, struct __vmmeter *vmstat)
 {
-    int status;
-    size_t size = sizeof(unsigned int);
+    size_t size;
 
-    status = kread(sigar, vmstat, sizeof(*vmstat),
-                   sigar->koffsets[KOFFSET_VMMETER]);
-
-    if (status == SIGAR_OK) {
-        return SIGAR_OK;
-    }
-
     SIGAR_ZERO(vmstat);
 
     /* derived from src/usr.bin/vmstat/vmstat.c */
     /* only collect the ones we actually use */
-#define GET_VM_STATS(cat, name, used) \
-    if (used) sysctlbyname("vm.stats." #cat "." #name, &vmstat->name, &size, NULL, 0)
+#define GET_VM_STATS(cat, name, used)	do {				\
+	if (used) {							\
+		size = sizeof(vmstat->name);				\
+		sysctlbyname("vm.stats." #cat "." #name, &vmstat->name,	\
+		    &size, NULL, 0);					\
+	}								\
+} while (0)
 
     /* sys */
     GET_VM_STATS(sys, v_swtch, 0);
@@ -399,9 +459,13 @@ static int sigar_vmstat(sigar_t *sigar, struct vmmeter
     GET_VM_STATS(vm, v_active_count, 0);
     GET_VM_STATS(vm, v_inactive_target, 0);
     GET_VM_STATS(vm, v_inactive_count, 1);
+#if (__FreeBSD_version < 1200016 )
     GET_VM_STATS(vm, v_cache_count, 1);
+#endif
+#if (__FreeBSD_version < 1100079 )
     GET_VM_STATS(vm, v_cache_min, 0);
     GET_VM_STATS(vm, v_cache_max, 0);
+#endif
     GET_VM_STATS(vm, v_pageout_free_min, 0);
     GET_VM_STATS(vm, v_interrupt_free_min, 0);
     GET_VM_STATS(vm, v_forks, 0);
@@ -440,7 +504,7 @@ int sigar_mem_get(sigar_t *sigar, sigar_mem_t *mem)
     unsigned long mem_total;
 #endif
 #if defined(__FreeBSD__)
-    struct vmmeter vmstat;
+    struct __vmmeter vmstat;
 #elif defined(__OpenBSD__) || defined(__NetBSD__)
     struct uvmexp vmstat;
 #endif
@@ -479,7 +543,11 @@ int sigar_mem_get(sigar_t *sigar, sigar_mem_t *mem)
     kern *= sigar->pagesize;
 #elif defined(__FreeBSD__)
     if ((status = sigar_vmstat(sigar, &vmstat)) == SIGAR_OK) {
+#if (__FreeBSD_version < 1200016 )
         kern = vmstat.v_cache_count + vmstat.v_inactive_count;
+#else
+        kern = vmstat.v_inactive_count;
+#endif
         kern *= sigar->pagesize;
         mem->free = vmstat.v_free_count;
         mem->free *= sigar->pagesize;
@@ -689,7 +757,7 @@ int sigar_swap_get(sigar_t *sigar, sigar_swap_t *swap)
     swap->page_out = vmstat.pageouts;
 #elif defined(__FreeBSD__)
     struct kvm_swap kswap[1];
-    struct vmmeter vmstat;
+    struct __vmmeter vmstat;
 
     if (getswapinfo_sysctl(kswap, 1) != SIGAR_OK) {
         if (!sigar->kmem) {
@@ -1897,7 +1965,7 @@ int sigar_proc_fd_get(sigar_t *sigar, sigar_pid_t pid,
     free(ofiles);
 #else
     /* seems the same as the above */
-    procfd->total = filed.fd_lastfile;
+    procfd->total = filed.fd_nfiles;
 #endif
 
     return SIGAR_OK;
@@ -3055,8 +3123,13 @@ static int net_connection_get(sigar_net_connection_wal
     int type, istcp = 0;
     char *buf;
     const char *mibvar;
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 1200026)
+    struct xtcpcb *tp = NULL;
+    struct xinpcb *inp;
+#else
     struct tcpcb *tp = NULL;
     struct inpcb *inp;
+#endif
     struct xinpgen *xig, *oxig;
     struct xsocket *so;
     size_t len;
@@ -3094,6 +3167,15 @@ static int net_connection_get(sigar_net_connection_wal
          xig->xig_len > sizeof(struct xinpgen);
          xig = (struct xinpgen *)((char *)xig + xig->xig_len))
     {
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 1200026)
+	if (istcp) {
+		tp = (struct xtcpcb *)xig;
+		inp = &tp->xt_inp;
+	} else {
+		inp = (struct xinpcb *)xig;
+	}
+	so = &inp->xi_socket;
+#else
         if (istcp) {
             struct xtcpcb *cb = (struct xtcpcb *)xig;
             tp = &cb->xt_tp;
@@ -3105,6 +3187,7 @@ static int net_connection_get(sigar_net_connection_wal
             inp = &cb->xi_inp;
             so = &cb->xi_socket;
         }
+#endif
 
         if (so->xso_protocol != proto) {
             continue;

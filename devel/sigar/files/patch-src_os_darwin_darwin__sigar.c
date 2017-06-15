--- src/os/darwin/darwin_sigar.c.orig	2014-11-17 13:46:20.000000000 -0800
+++ src/os/darwin/darwin_sigar.c	2017-03-20 23:32:31.935016000 -0700
@@ -399,9 +399,13 @@
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
@@ -479,7 +483,11 @@
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
@@ -3055,8 +3063,13 @@
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
@@ -3094,6 +3107,15 @@
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
@@ -3105,6 +3127,7 @@
             inp = &cb->xi_inp;
             so = &cb->xi_socket;
         }
+#endif
 
         if (so->xso_protocol != proto) {
             continue;

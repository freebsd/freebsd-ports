--- src/system_info.c.orig	2019-12-25 12:35:44 UTC
+++ src/system_info.c
@@ -62,7 +62,7 @@ int get_sys_total_mem_size(int64_t *mem_
    size_t len;
 
    mib[0] = CTL_HW;
-   mib[1] = HW_MEMSIZE;
+   mib[1] = HW_PHYSMEM;
    len = sizeof(*mem_size);
    if (sysctl(mib, 2, mem_size, &len, NULL, 0) != 0)
    {
@@ -583,6 +583,20 @@ int get_sysinfo(struct fast_sysinfo*info
 #define ki_rgid kp_eproc.e_pcred.p_rgid
 #define GET_SIGNAL(sig) sig
 
+#elif defined __DragonFly__
+#define ki_pid  kp_pid
+#define ki_comm kp_comm
+#define ki_ppid kp_ppid
+#define ki_start kp_start
+#define ki_flag kp_flags
+#define ki_stat kp_stat
+#define ki_sigignore kp_sigignore
+#define ki_sigcatch kp_sigcatch
+#define ki_priority kp_lwp.kl_prio
+#define ki_ruid kp_ruid
+#define ki_rgid kp_rgid
+#define GET_SIGNAL(sig) *((int *)&sig)
+
 #else
 #define ki_priority ki_pri.pri_level
 #define GET_SIGNAL(sig) *((int *)&sig)

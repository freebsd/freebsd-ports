--- src/system_info.c.orig	2016-09-08 07:44:31 UTC
+++ src/system_info.c
@@ -582,6 +582,20 @@ int get_sysinfo(struct fast_sysinfo*info
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

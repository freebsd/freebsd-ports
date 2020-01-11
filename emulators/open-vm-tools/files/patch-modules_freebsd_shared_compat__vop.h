--- modules/freebsd/shared/compat_vop.h.orig	2019-10-21 21:58:04 UTC
+++ modules/freebsd/shared/compat_vop.h
@@ -47,7 +47,11 @@
 #if __FreeBSD_version >= 800011
 #define COMPAT_THREAD_VAR(varname, varval)
 #define COMPAT_VOP_LOCK(vop, flags, threadvar) VOP_LOCK((vop), (flags))
+#if __FreeBSD_version >= 1300074
+#define COMPAT_VOP_UNLOCK(vop, flags, threadvar) VOP_UNLOCK((vop))
+#else
 #define COMPAT_VOP_UNLOCK(vop, flags, threadvar) VOP_UNLOCK((vop), (flags))
+#endif
 #define compat_lockstatus(lock, threadvar) lockstatus((lock))
 #define compat_lockmgr(lock, flags, randompointerparam, threadval) lockmgr((lock), (flags), (randompointerparam))
 #define compat_vn_lock(vp, flags, threadval) vn_lock((vp), (flags))

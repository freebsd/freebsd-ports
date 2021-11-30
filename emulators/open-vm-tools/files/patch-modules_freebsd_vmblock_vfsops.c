--- modules/freebsd/vmblock/vfsops.c.orig	2021-09-24 04:19:18 UTC
+++ modules/freebsd/vmblock/vfsops.c
@@ -124,6 +124,11 @@ VMBlockVFSMount(struct mount *mp,        // IN: mount(
    char *pathname;
    int len, error = 0;
 
+#if __FreeBSD_version >= 800087
+   struct thread *td;
+   td = curthread;
+#endif
+
    VMBLOCKDEBUG("VMBlockVFSMount(mp = %p)\n", (void *)mp);
 
    /*
@@ -171,7 +176,11 @@ VMBlockVFSMount(struct mount *mp,        // IN: mount(
     * Find lower node and lock if not already locked.
     */
 
+#if __FreeBSD_version >= 1400043
+   NDINIT(ndp, LOOKUP, FOLLOW|LOCKLEAF, UIO_SYSSPACE, target);
+#else
    NDINIT(ndp, LOOKUP, FOLLOW|LOCKLEAF, UIO_SYSSPACE, target, compat_td);
+#endif
    error = namei(ndp);
    if (error) {
       NDFREE(ndp, 0);
@@ -276,6 +285,11 @@ VMBlockVFSUnmount(struct mount *mp,    // IN: filesyst
    void *mntdata;
    int error;
    int flags = 0, removed = 0;
+
+#if __FreeBSD_version >= 800087
+   struct thread *td;
+   td = curthread;
+#endif
 
    VMBLOCKDEBUG("VMBlockVFSUnmount: mp = %p\n", (void *)mp);
 

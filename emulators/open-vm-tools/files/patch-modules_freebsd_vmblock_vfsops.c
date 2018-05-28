--- modules/freebsd/vmblock/vfsops.c.orig	2018-03-30 18:44:35 UTC
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
@@ -276,6 +281,11 @@ VMBlockVFSUnmount(struct mount *mp,    // IN: filesyst
    void *mntdata;
    int error;
    int flags = 0, removed = 0;
+
+#if __FreeBSD_version >= 800087
+   struct thread *td;
+   td = curthread;
+#endif
 
    VMBLOCKDEBUG("VMBlockVFSUnmount: mp = %p\n", (void *)mp);
 

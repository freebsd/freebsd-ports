--- modules/freebsd/vmblock/vfsops.c.orig	2017-02-24 22:15:37 UTC
+++ modules/freebsd/vmblock/vfsops.c
@@ -124,6 +124,11 @@ VMBlockVFSMount(struct mount *mp,       
    char *pathname;
    int len, error = 0;
 
+#if __FreeBSD_version >= 800087
+   struct thread *td;
+   td = curthread;
+#endif
+
    VMBLOCKDEBUG("VMBlockVFSMount(mp = %p)\n", (void *)mp);
 
    /*
@@ -277,6 +282,11 @@ VMBlockVFSUnmount(struct mount *mp,    /
    int error;
    int flags = 0, removed = 0;
 
+#if __FreeBSD_version >= 800087
+   struct thread *td;
+   td = curthread;
+#endif
+
    VMBLOCKDEBUG("VMBlockVFSUnmount: mp = %p\n", (void *)mp);
 
    xmp = MNTTOVMBLOCKMNT(mp);

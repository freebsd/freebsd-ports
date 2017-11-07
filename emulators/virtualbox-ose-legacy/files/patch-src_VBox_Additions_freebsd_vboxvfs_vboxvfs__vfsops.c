--- src/VBox/Additions/freebsd/vboxvfs/vboxvfs_vfsops.c.orig	2017-04-28 16:59:22.000000000 +0200
+++ src/VBox/Additions/freebsd/vboxvfs/vboxvfs_vfsops.c	2017-07-12 19:24:26.109029000 +0200
@@ -1,10 +1,5 @@
-/* $Id: vboxvfs_vfsops.c $ */
-/** @file
- * Description.
- */
-
 /*
  * Copyright (C) 2008-2016 Oracle Corporation
  *
  * This file is part of VirtualBox Open Source Edition (OSE), as
  * available from http://www.virtualbox.org. This file is free software;
@@ -14,245 +9,479 @@
  * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
  * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
  */
-
-#include "vboxvfs.h"
+#include <sys/types.h>
 #include <sys/param.h>
 #include <sys/systm.h>
 #include <sys/proc.h>
 #include <sys/bio.h>
 #include <sys/buf.h>
+#include <sys/conf.h>
+#include <sys/dirent.h>
 #include <sys/kernel.h>
 #include <sys/sysctl.h>
 #include <sys/vnode.h>
 #include <sys/mount.h>
+#include <sys/namei.h>
+#include <sys/fcntl.h>
+#include <sys/priv.h>
 #include <sys/stat.h>
 #include <sys/malloc.h>
 #include <sys/module.h>
+#include <sys/sbuf.h>
 
-#include <iprt/mem.h>
-
-#define VFSMP2SFGLOBINFO(mp) ((struct sf_glob_info *)mp->mnt_data)
-
-static int vboxvfs_version = VBOXVFS_VERSION;
+#include <geom/geom.h>
+#include <geom/geom_vfs.h>
 
-SYSCTL_NODE(_vfs, OID_AUTO, vboxvfs, CTLFLAG_RW, 0, "VirtualBox shared filesystem");
-SYSCTL_INT(_vfs_vboxvfs, OID_AUTO, version, CTLFLAG_RD, &vboxvfs_version, 0, "");
+#include "vboxvfs.h"
 
-/* global connection to the host service. */
-static VBGLSFCLIENT g_vboxSFClient;
+#define VFSMP2SFGLOBINFO(mp) ((struct sf_glob_info *)mp->mnt_data)
 
-static vfs_init_t       vboxvfs_init;
-static vfs_uninit_t     vboxvfs_uninit;
-static vfs_cmount_t     vboxvfs_cmount;
-static vfs_mount_t      vboxvfs_mount;
-static vfs_root_t       vboxvfs_root;
-static vfs_quotactl_t   vboxvfs_quotactl;
-static vfs_statfs_t     vboxvfs_statfs;
-static vfs_unmount_t    vboxvfs_unmount;
-
-static struct vfsops vboxvfs_vfsops = {
-    .vfs_init     =    vboxvfs_init,
-    .vfs_cmount   =    vboxvfs_cmount,
-    .vfs_mount    =    vboxvfs_mount,
-    .vfs_quotactl =    vboxvfs_quotactl,
-    .vfs_root     =    vboxvfs_root,
-    .vfs_statfs   =    vboxvfs_statfs,
-    .vfs_sync     =    vfs_stdsync,
-    .vfs_uninit   =    vboxvfs_uninit,
-    .vfs_unmount  =    vboxvfs_unmount,
+#ifdef MALLOC_DECLARE
+MALLOC_DEFINE(M_VBOXVFS, "vboxvfs", "VBOX VFS");
+#endif
+
+static sfp_connection_t *sfprov = NULL;
+
+static int vboxfs_version = VBOXVFS_VERSION;
+u_int vboxvfs_debug = 1;
+
+SYSCTL_NODE(_vfs, OID_AUTO, vboxfs, CTLFLAG_RW, 0, "VirtualBox shared filesystem");
+SYSCTL_INT(_vfs_vboxfs, OID_AUTO, version, CTLFLAG_RD, &vboxfs_version, 0, "");
+SYSCTL_UINT(_vfs_vboxfs, OID_AUTO, debug, CTLFLAG_RW, &vboxvfs_debug, 0, "Debug level");
+
+static vfs_init_t	vboxfs_init;
+static vfs_uninit_t	vboxfs_uninit;
+static vfs_cmount_t	vboxfs_cmount;
+static vfs_mount_t	vboxfs_mount;
+static vfs_root_t	vboxfs_root;
+static vfs_quotactl_t	vboxfs_quotactl;
+static vfs_statfs_t	vboxfs_statfs;
+static vfs_unmount_t	vboxfs_unmount;
+
+static struct vfsops vboxfs_vfsops = {
+	.vfs_init	= vboxfs_init,
+	.vfs_cmount	= vboxfs_cmount,
+	.vfs_mount	= vboxfs_mount,
+	.vfs_quotactl	= vboxfs_quotactl,
+	.vfs_root	= vboxfs_root,
+	.vfs_statfs	= vboxfs_statfs,
+	.vfs_sync	= vfs_stdsync,
+	.vfs_uninit	= vboxfs_uninit,
+	.vfs_unmount	= vboxfs_unmount
 };
 
 
-VFS_SET(vboxvfs_vfsops, vboxvfs, VFCF_NETWORK);
+VFS_SET(vboxfs_vfsops, vboxvfs, VFCF_NETWORK);
 MODULE_DEPEND(vboxvfs, vboxguest, 1, 1, 1);
 
-static int vboxvfs_cmount(struct mntarg *ma, void * data, int flags, struct thread *td)
+/*
+ * Allocates a new node of type 'type' inside the 'tmp' mount point, with
+ * its owner set to 'uid', its group to 'gid' and its mode set to 'mode',
+ * using the credentials of the process 'p'.
+ *
+ * If the node type is set to 'VDIR', then the parent parameter must point
+ * to the parent directory of the node being created.  It may only be NULL
+ * while allocating the root node.
+ *
+ * If the node type is set to 'VBLK' or 'VCHR', then the rdev parameter
+ * specifies the device the node represents.
+ *
+ * If the node type is set to 'VLNK', then the parameter target specifies
+ * the file name of the target file for the symbolic link that is being
+ * created.
+ *
+ * Note that new nodes are retrieved from the available list if it has
+ * items or, if it is empty, from the node pool as long as there is enough
+ * space to create them.
+ *
+ * Returns zero on success or an appropriate error code on failure.
+ */
+int
+vboxfs_alloc_node(struct mount *mp, struct vboxfs_mnt *vsfmp, const char *fullpath,
+    enum vtype type, uid_t uid, gid_t gid, mode_t mode, struct vboxfs_node *parent,
+    struct vboxfs_node **node)
 {
-    struct vboxvfs_mount_info args;
-    int rc = 0;
-
-    printf("%s: Enter\n", __FUNCTION__);
-
-    rc = copyin(data, &args, sizeof(struct vboxvfs_mount_info));
-    if (rc)
-        return rc;
+	struct vboxfs_node *nnode;
 
-    ma = mount_argf(ma, "uid", "%d", args.uid);
-    ma = mount_argf(ma, "gid", "%d", args.gid);
-    ma = mount_arg(ma, "from", args.name, -1);
+	if ((mp->mnt_kern_flag & MNTK_UNMOUNT) != 0) {
+		/*
+		 * When a new tmpfs node is created for fully
+		 * constructed mount point, there must be a parent
+		 * node, which vnode is locked exclusively.  As
+		 * consequence, if the unmount is executing in
+		 * parallel, vflush() cannot reclaim the parent vnode.
+		 * Due to this, the check for MNTK_UNMOUNT flag is not
+		 * racy: if we did not see MNTK_UNMOUNT flag, then tmp
+		 * cannot be destroyed until node construction is
+		 * finished and the parent vnode unlocked.
+		 *
+		 * Tmpfs does not need to instantiate new nodes during
+		 * unmount.
+		 */
+		return (EBUSY);
+	}
+
+	nnode = (struct vboxfs_node *)uma_zalloc_arg(
+				vsfmp->sf_node_pool, vsfmp, M_WAITOK);
+
+	/* Generic initialization. */
+	nnode->sf_type = type;
+	nnode->sf_ino = vsfmp->sf_ino++;
+	nnode->sf_path = strdup(fullpath, M_VBOXVFS);
+	nnode->sf_parent = parent;
+	nnode->vboxfsmp = vsfmp;
+
+	/* Type-specific initialization. */
+	switch (nnode->sf_type) {
+	case VBLK:
+	case VCHR:
+	case VDIR:
+	case VFIFO:
+	case VSOCK:
+	case VLNK:
+	case VREG:
+		break;
+
+	default:
+		panic("vboxfs_alloc_node: type %p %d", nnode, (int)nnode->sf_type);
+	}
 
-    rc = kernel_mount(ma, flags);
-
-    printf("%s: Leave rc=%d\n", __FUNCTION__, rc);
-
-    return rc;
+	*node = nnode;
+	return 0;
 }
 
-static const char *vboxvfs_opts[] = {
-    "uid", "gid", "from", "fstype", "fspath", "errmsg", NULL
-};
-
-static int vboxvfs_mount(struct mount *mp, struct thread *td)
+void
+vboxfs_free_node(struct vboxfs_mnt *vboxfs, struct vboxfs_node *node)
 {
-    int rc;
-    char *pszShare;
-    int  cbShare, cbOption;
-    int uid = 0, gid = 0;
-    struct sf_glob_info *pShFlGlobalInfo;
-    SHFLSTRING *pShFlShareName = NULL;
-    int cbShFlShareName;
-
-    printf("%s: Enter\n", __FUNCTION__);
-
-    if (mp->mnt_flag & (MNT_UPDATE | MNT_ROOTFS))
-        return EOPNOTSUPP;
-
-    if (vfs_filteropt(mp->mnt_optnew, vboxvfs_opts))
-    {
-        vfs_mount_error(mp, "%s", "Invalid option");
-        return EINVAL;
-    }
-
-    rc = vfs_getopt(mp->mnt_optnew, "from", (void **)&pszShare, &cbShare);
-    if (rc || pszShare[cbShare-1] != '\0' || cbShare > 0xfffe)
-        return EINVAL;
-
-    rc = vfs_getopt(mp->mnt_optnew, "gid", (void **)&gid, &cbOption);
-    if ((rc != ENOENT) && (rc || cbOption != sizeof(gid)))
-        return EINVAL;
-
-    rc = vfs_getopt(mp->mnt_optnew, "uid", (void **)&uid, &cbOption);
-    if ((rc != ENOENT) && (rc || cbOption != sizeof(uid)))
-        return EINVAL;
 
-    pShFlGlobalInfo = RTMemAllocZ(sizeof(struct sf_glob_info));
-    if (!pShFlGlobalInfo)
-        return ENOMEM;
+#ifdef INVARIANTS
+	TMPFS_NODE_LOCK(node);
+	MPASS(node->sf_vnode == NULL);
+	MPASS((node->sf_vpstate & TMPFS_VNODE_ALLOCATING) == 0);
+	TMPFS_NODE_UNLOCK(node);
+#endif
+	if (node->sf_path)
+		free(node->sf_path, M_VBOXVFS);
 
-    cbShFlShareName = offsetof (SHFLSTRING, String.utf8) + cbShare + 1;
-    pShFlShareName  = RTMemAllocZ(cbShFlShareName);
-    if (!pShFlShareName)
-        return VERR_NO_MEMORY;
+	uma_zfree(vboxfs->sf_node_pool, node);
+}
 
-    pShFlShareName->u16Length = cbShare;
-    pShFlShareName->u16Size   = cbShare + 1;
-    memcpy (pShFlShareName->String.utf8, pszShare, cbShare + 1);
+static int
+vboxfs_cmount(struct mntarg *ma, void *data, uint64_t flags)
+{
+	struct vboxfs_mount_info args;
+	int error = 0;
 
-    rc = VbglR0SfMapFolder (&g_vboxSFClient, pShFlShareName, &pShFlGlobalInfo->map);
-    RTMemFree(pShFlShareName);
+	if (data == NULL)
+		return (EINVAL);
+	error = copyin(data, &args, sizeof(struct vboxfs_mount_info));
+	if (error)
+		return (error);
+
+  	ma = mount_argf(ma, "uid", "%d", args.uid);
+	ma = mount_argf(ma, "gid", "%d", args.gid);
+	ma = mount_argf(ma, "file_mode", "%d", args.fmode);
+	ma = mount_argf(ma, "dir_mode", "%d", args.dmode);
+	ma = mount_arg(ma, "from", args.name, -1);
 
-    if (RT_FAILURE (rc))
-    {
-        RTMemFree(pShFlGlobalInfo);
-        printf("VbglR0SfMapFolder failed rc=%d\n", rc);
-        return EPROTO;
-    }
+	return (kernel_mount(ma, flags));
+}
 
-    pShFlGlobalInfo->uid = uid;
-    pShFlGlobalInfo->gid = gid;
+static const char *vboxfs_opts[] = {
+	"fstype",
+	"fspath",
+	"from",
+	"uid",
+	"gid",
+	"file_mode",
+	"dir_mode",
+	"errmsg",
+	NULL
+};
 
-    mp->mnt_data = pShFlGlobalInfo;
+#define	VBOX_INTOPT(optname, val, base) do {				\
+	char *ep, *optarg = NULL;					\
+	if (vfs_getopt(opts, optname, (void **)&optarg, NULL) == 0) {	\
+		if (optarg != NULL && *optarg == '\0')			\
+			optarg = NULL;					\
+		if (optarg != NULL)					\
+			val = strtoul(optarg, &ep, base);		\
+		if (optarg == NULL || *ep != '\0') {			\
+			struct sbuf *sb = sbuf_new_auto();		\
+			sbuf_printf(sb, "Invalid %s: \"%s\"", optname,	\
+			    optarg);					\
+			sbuf_finish(sb);				\
+			vfs_mount_error(mp, sbuf_data(sb));		\
+			sbuf_delete(sb);				\
+			return (EINVAL);				\
+		}							\
+	}								\
+} while (0)
 
-    /** @todo root vnode. */
+static int
+vboxfs_node_ctor(void *mem, int size, void *arg, int flags)
+{
+	struct vboxfs_node *node = (struct vboxfs_node *)mem;
 
-    vfs_getnewfsid(mp);
-    vfs_mountedfrom(mp, pszShare);
+	node->sf_vnode = NULL;
+	node->sf_vpstate = 0;
 
-    printf("%s: Leave rc=0\n", __FUNCTION__);
+	return (0);
+}
 
-    return 0;
+static void
+vboxfs_node_dtor(void *mem, int size, void *arg)
+{
+	struct vboxfs_node *node = (struct vboxfs_node *)mem;
+	node->sf_type = VNON;
 }
 
-static int vboxvfs_unmount(struct mount *mp, int mntflags, struct thread *td)
+static int
+vboxfs_node_init(void *mem, int size, int flags)
 {
-    struct sf_glob_info *pShFlGlobalInfo = VFSMP2SFGLOBINFO(mp);
-    int rc;
-    int flags = 0;
+	struct vboxfs_node *node = (struct vboxfs_node *)mem;
+	node->sf_ino = 0;
 
-    rc = VbglR0SfUnmapFolder(&g_vboxSFClient, &pShFlGlobalInfo->map);
-    if (RT_FAILURE(rc))
-        printf("Failed to unmap shared folder\n");
+	mtx_init(&node->sf_interlock, "tmpfs node interlock", NULL, MTX_DEF);
 
-    if (mntflags & MNT_FORCE)
-        flags |= FORCECLOSE;
+	return (0);
+}
 
-    /* There is 1 extra root vnode reference (vnode_root). */
-    rc = vflush(mp, 1, flags, td);
-    if (rc)
-        return rc;
+static void
+vboxfs_node_fini(void *mem, int size)
+{
+	struct vboxfs_node *node = (struct vboxfs_node *)mem;
 
+	mtx_destroy(&node->sf_interlock);
+}
 
-    RTMemFree(pShFlGlobalInfo);
-    mp->mnt_data = NULL;
+static int
+vboxfs_mount(struct mount *mp)
+{
+	struct vboxfs_mnt *vboxfsmp = NULL;
+	struct vfsoptlist *opts = mp->mnt_optnew;
+	sfp_mount_t *handle = NULL;
+	int readonly = 0;
+	sffs_fsinfo_t fsinfo;
+	int error, share_len;
+	char *share_name;
+   	mode_t file_mode = 0, dir_mode = 0;
+	uid_t uid = 0;
+	gid_t gid = 0;
+	struct vboxfs_node *root;
+
+	if (mp->mnt_flag & (MNT_UPDATE | MNT_ROOTFS))
+		return (EOPNOTSUPP);
+
+	if (vfs_filteropt(opts, vboxfs_opts)) {
+		vfs_mount_error(mp, "%s", "Invalid option");
+		return (EINVAL);
+	}
+
+	VBOX_INTOPT("uid", uid, 10);
+	VBOX_INTOPT("gid", gid, 10);
+	VBOX_INTOPT("file_mode", file_mode, 8);
+	VBOX_INTOPT("dir_mode", dir_mode, 8);
+	VBOX_INTOPT("ro", readonly, 10);
+
+	error = vfs_getopt(opts, "from", (void **)&share_name, &share_len);
+	if (error != 0 || share_len == 0) {
+		vfs_mount_error(mp, "Invalid from");
+		return (EINVAL);
+	}
+
+	vboxfsmp = malloc(sizeof(struct vboxfs_mnt), M_VBOXVFS, M_WAITOK | M_ZERO);
+	vboxfsmp->sf_uid = uid;
+	vboxfsmp->sf_gid = gid;
+	vboxfsmp->sf_fmode = file_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
+	vboxfsmp->sf_dmode = dir_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
+	vboxfsmp->sf_ino = 3;
+	vboxfsmp->sf_stat_ttl = 200;
+
+	/* Invoke Hypervisor mount interface before proceeding */
+	error = sfprov_mount(share_name, &handle);
+	if (error)
+		return (error);
+
+	/* Determine whether the filesystem must be read-only. */
+	error = sfprov_get_fsinfo(handle, &fsinfo);
+	if (error != 0) {
+		sfprov_unmount(handle);
+		return (error);
+	}
+	if (readonly == 0)
+		readonly = (fsinfo.readonly != 0);
+
+	vboxfsmp->sf_handle = handle;
+	vboxfsmp->sf_vfsp = mp;
+
+	vboxfsmp->sf_node_pool = uma_zcreate("VBOXFS node",
+	    sizeof(struct vboxfs_node),
+	    vboxfs_node_ctor, vboxfs_node_dtor,
+	    vboxfs_node_init, vboxfs_node_fini,
+	    UMA_ALIGN_PTR, 0);
+
+	/* Allocate the root node. */
+	error = vboxfs_alloc_node(mp, vboxfsmp, "", VDIR, 0,
+	    0, 0755, NULL, &root);
+
+	if (error != 0 || root == NULL) {
+		uma_zdestroy(vboxfsmp->sf_node_pool);
+		free(vboxfsmp, M_VBOXVFS);
+		return error;
+	}
+
+	root->sf_parent = root;
+	vboxfsmp->sf_root = root;
+
+	MNT_ILOCK(mp);
+	mp->mnt_data = vboxfsmp;
+	bzero(&mp->mnt_stat.f_fsid, sizeof(&mp->mnt_stat.f_fsid));
+	/* f_fsid is int32_t but serial is uint32_t, convert */
+	memcpy(&mp->mnt_stat.f_fsid, &fsinfo.serial, sizeof(mp->mnt_stat.f_fsid));
+	mp->mnt_flag |= MNT_LOCAL;
+	if (readonly != 0)
+		mp->mnt_flag |= MNT_RDONLY;
+#if __FreeBSD_version >= 1000021
+	mp->mnt_kern_flag |= MNTK_LOOKUP_SHARED | MNTK_EXTENDED_SHARED;
+#else
+	mp->mnt_kern_flag |= MNTK_MPSAFE | MNTK_LOOKUP_SHARED |
+	    MNTK_EXTENDED_SHARED;
+#endif
+	MNT_IUNLOCK(mp);
+	vfs_mountedfrom(mp, share_name);
 
-    return 0;
+	return (0);
 }
 
-static int vboxvfs_root(struct mount *mp, int flags, struct vnode **vpp, struct thread *td)
+/*
+ * Unmount a shared folder.
+ *
+ * vboxfs_unmount umounts the mounted file system. It return 0
+ * on sucess and any relevant errno on failure.
+ */
+static int
+vboxfs_unmount(struct mount *mp, int mntflags)
 {
-    int rc = 0;
-    struct sf_glob_info *pShFlGlobalInfo = VFSMP2SFGLOBINFO(mp);
-    struct vnode *vp;
+	struct vboxfs_mnt *vboxfsmp;
+	struct thread *td;
+	int error;
+	int flags;
+
+	vboxfsmp = VFSTOVBOXFS(mp);
+	td = curthread;
+	flags = 0;
+	if (mntflags & MNT_FORCE)
+		flags |= FORCECLOSE;
+
+	error = vflush(mp, 0, flags, td);
+	if (error)
+		return (error);
+
+	/* Invoke Hypervisor unmount interface before proceeding */
+	error = sfprov_unmount(vboxfsmp->sf_handle);
+	if (error != 0) {
+		/* TBD anything here? */
+	}
+
+	uma_zdestroy(vboxfsmp->sf_node_pool);
+
+	free(vboxfsmp, M_VBOXVFS);
+	MNT_ILOCK(mp);
+	mp->mnt_data = NULL;
+	mp->mnt_flag &= ~MNT_LOCAL;
+	MNT_IUNLOCK(mp);
 
-    printf("%s: Enter\n", __FUNCTION__);
-
-    vp = pShFlGlobalInfo->vnode_root;
-    VREF(vp);
+	return (0);
+}
 
-    vn_lock(vp, flags | LK_RETRY, td);
-    *vpp = vp;
+static int
+vboxfs_root(struct mount *mp, int flags, struct vnode **vpp)
+{
+	int error;
+	error = vboxfs_alloc_vp(mp, VFSTOVBOXFS(mp)->sf_root, flags, vpp);
 
-    printf("%s: Leave\n", __FUNCTION__);
+	if (!error)
+		(*vpp)->v_vflag |= VV_ROOT;
 
-    return rc;
+	return error;
 }
 
-static int vboxvfs_quotactl(struct mount *mp, int cmd, uid_t uid, void *arg, struct thread *td)
+/*
+ * Do operation associated with quotas, not supported
+ */
+static int
+vboxfs_quotactl(struct mount *mp, int cmd, uid_t uid, void *arg)
 {
-    return EOPNOTSUPP;
+	return (EOPNOTSUPP);
 }
 
-int vboxvfs_init(struct vfsconf *vfsp)
+/*
+ * Initialize the filesystem globals.
+ */
+static int
+vboxfs_init(struct vfsconf *vfsp)
 {
-    int rc;
+	int error;
 
-    /* Initialize the R0 guest library. */
-    rc = VbglR0SfInit();
-    if (RT_FAILURE(rc))
-        return ENXIO;
+	DROP_GIANT();
 
-    /* Connect to the host service. */
-    rc = VbglR0SfConnect(&g_vboxSFClient);
-    if (RT_FAILURE(rc))
-    {
-        printf("Failed to get connection to host! rc=%d\n", rc);
-        VbglR0SfTerm();
-        return ENXIO;
-    }
+	sfprov = sfprov_connect(SFPROV_VERSION);
+	if (sfprov == NULL) {
+		printf("%s: couldn't connect to sf provider", __func__);
+		return (ENODEV);
+	}
+
+	error = sfprov_set_show_symlinks();
+	if (error != 0)
+		printf("%s: host unable to show symlinks, error=%d\n",
+		    __func__, error);
 
-    rc = VbglR0SfSetUtf8(&g_vboxSFClient);
-    if (RT_FAILURE (rc))
-    {
-        printf("VbglR0SfSetUtf8 failed, rc=%d\n", rc);
-        VbglR0SfDisconnect(&g_vboxSFClient);
-        VbglR0SfTerm();
-        return EPROTO;
-    }
-
-    printf("Successfully loaded shared folder module\n");
-
-    return 0;
+	PICKUP_GIANT();
+	return (0);
 }
 
-int vboxvfs_uninit(struct vfsconf *vfsp)
+/*
+ * Undo the work of vboxfs_init().
+ */
+static int
+vboxfs_uninit(struct vfsconf *vfsp)
 {
-    VbglR0SfDisconnect(&g_vboxSFClient);
-    VbglR0SfTerm();
 
-    return 0;
+	DROP_GIANT();
+	sfprov_disconnect();
+	PICKUP_GIANT();
+	return (0);
 }
 
-int vboxvfs_statfs(struct mount *mp, struct statfs *sbp, struct thread *td)
+/*
+ * Get filesystem statistics.
+ */
+static int
+vboxfs_statfs(struct mount *mp, struct statfs *sbp)
 {
-    return 0;
+	struct vboxfs_mnt *vboxfsmp;
+	sffs_fsinfo_t fsinfo;
+	int error;
+
+	vboxfsmp = VFSTOVBOXFS(mp);
+
+	error = sfprov_get_fsinfo(vboxfsmp->sf_handle, &fsinfo);
+	if (error != 0)
+		return (error);
+
+	sbp->f_iosize = fsinfo.blksize;
+	sbp->f_bsize = fsinfo.blksize;
+
+	sbp->f_bfree = fsinfo.blksavail;
+	sbp->f_bavail = fsinfo.blksavail;
+	sbp->f_files = fsinfo.blksavail / 4; /* some kind of reasonable value */
+	sbp->f_ffree = fsinfo.blksavail / 4;
+
+	sbp->f_blocks = fsinfo.blksused + sbp->f_bavail;
+	sbp->f_fsid.val[0] = mp->mnt_stat.f_fsid.val[0];
+	sbp->f_fsid.val[1] = mp->mnt_stat.f_fsid.val[1];
+	sbp->f_namemax = fsinfo.maxnamesize;
+
+	return (0);
 }

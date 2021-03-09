--- src/VBox/Additions/freebsd/vboxvfs/vboxvfs_vnops.c.orig	2020-07-09 16:50:11 UTC
+++ src/VBox/Additions/freebsd/vboxvfs/vboxvfs_vnops.c
@@ -1,10 +1,6 @@
-/* $Id: vboxvfs_vnops.c $ */
-/** @file
- * Description.
- */
-
 /*
  * Copyright (C) 2008-2017 Oracle Corporation
+ * Copyright (C) 2017 Mahdi Mokhtari
  *
  * This file is part of VirtualBox Open Source Edition (OSE), as
  * available from http://www.virtualbox.org. This file is free software;
@@ -14,228 +10,1347 @@
  * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
  * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
  */
-
-#include "vboxvfs.h"
 #include <sys/param.h>
 #include <sys/systm.h>
 #include <sys/namei.h>
 #include <sys/kernel.h>
-#include <sys/proc.h>
+#include <sys/types.h>
+#include <sys/malloc.h>
+#include <sys/stat.h>
 #include <sys/bio.h>
+#include <sys/conf.h>
 #include <sys/buf.h>
-#include <sys/fcntl.h>
+#include <sys/iconv.h>
 #include <sys/mount.h>
-#include <sys/unistd.h>
 #include <sys/vnode.h>
-#include <sys/limits.h>
-#include <sys/lockf.h>
-#include <sys/stat.h>
+#include <sys/dirent.h>
+#include <sys/queue.h>
+#include <sys/unistd.h>
+#include <sys/endian.h>
 
-#include <vm/vm.h>
-#include <vm/vm_extern.h>
+#include <vm/uma.h>
 
+#include "vboxvfs.h"
+
+#if __FreeBSD_version < 1300063
+#define	VN_IS_DOOMED(vp)	 (((vp)->v_iflag & VI_DOOMED) != 0)
+#endif
+
 /*
  * Prototypes for VBOXVFS vnode operations
  */
-static vop_create_t     vboxvfs_create;
-static vop_mknod_t      vboxvfs_mknod;
-static vop_open_t       vboxvfs_open;
-static vop_close_t      vboxvfs_close;
-static vop_access_t     vboxvfs_access;
-static vop_getattr_t    vboxvfs_getattr;
-static vop_setattr_t    vboxvfs_setattr;
-static vop_read_t       vboxvfs_read;
-static vop_write_t      vboxvfs_write;
-static vop_fsync_t      vboxvfs_fsync;
-static vop_remove_t     vboxvfs_remove;
-static vop_link_t       vboxvfs_link;
-static vop_lookup_t     vboxvfs_lookup;
-static vop_rename_t     vboxvfs_rename;
-static vop_mkdir_t      vboxvfs_mkdir;
-static vop_rmdir_t      vboxvfs_rmdir;
-static vop_symlink_t    vboxvfs_symlink;
-static vop_readdir_t    vboxvfs_readdir;
-static vop_strategy_t   vboxvfs_strategy;
-static vop_print_t      vboxvfs_print;
-static vop_pathconf_t   vboxvfs_pathconf;
-static vop_advlock_t    vboxvfs_advlock;
-static vop_getextattr_t vboxvfs_getextattr;
-static vop_ioctl_t      vboxvfs_ioctl;
-static vop_getpages_t   vboxvfs_getpages;
-static vop_inactive_t   vboxvfs_inactive;
-static vop_putpages_t   vboxvfs_putpages;
-static vop_reclaim_t    vboxvfs_reclaim;
+static vop_create_t	vboxfs_create;
+static vop_open_t	vboxfs_open;
+static vop_close_t	vboxfs_close;
+static vop_access_t	vboxfs_access;
+static vop_getattr_t	vboxfs_getattr;
+static vop_setattr_t	vboxfs_setattr;
+static vop_read_t	vboxfs_read;
+static vop_readlink_t	vboxfs_readlink;
+static vop_write_t	vboxfs_write;
+static vop_fsync_t	vboxfs_fsync;
+static vop_remove_t	vboxfs_remove;
+static vop_link_t	vboxfs_link;
+static vop_cachedlookup_t	vboxfs_lookup;
+static vop_rename_t	vboxfs_rename;
+static vop_mkdir_t	vboxfs_mkdir;
+static vop_rmdir_t	vboxfs_rmdir;
+static vop_symlink_t	vboxfs_symlink;
+static vop_readdir_t	vboxfs_readdir;
+static vop_print_t	vboxfs_print;
+static vop_pathconf_t	vboxfs_pathconf;
+static vop_advlock_t	vboxfs_advlock;
+static vop_ioctl_t	vboxfs_ioctl;
+static vop_inactive_t	vboxfs_inactive;
+static vop_reclaim_t	vboxfs_reclaim;
+static vop_vptofh_t	vboxfs_vptofh;
 
-struct vop_vector vboxvfs_vnodeops = {
-    .vop_default    =   &default_vnodeops,
+struct vop_vector vboxfs_vnodeops = {
+	.vop_default	= &default_vnodeops,
 
-    .vop_access     =   vboxvfs_access,
-    .vop_advlock    =   vboxvfs_advlock,
-    .vop_close      =   vboxvfs_close,
-    .vop_create     =   vboxvfs_create,
-    .vop_fsync      =   vboxvfs_fsync,
-    .vop_getattr    =   vboxvfs_getattr,
-    .vop_getextattr =   vboxvfs_getextattr,
-    .vop_getpages   =   vboxvfs_getpages,
-    .vop_inactive   =   vboxvfs_inactive,
-    .vop_ioctl      =   vboxvfs_ioctl,
-    .vop_link       =   vboxvfs_link,
-    .vop_lookup     =   vboxvfs_lookup,
-    .vop_mkdir      =   vboxvfs_mkdir,
-    .vop_mknod      =   vboxvfs_mknod,
-    .vop_open       =   vboxvfs_open,
-    .vop_pathconf   =   vboxvfs_pathconf,
-    .vop_print      =   vboxvfs_print,
-    .vop_putpages   =   vboxvfs_putpages,
-    .vop_read       =   vboxvfs_read,
-    .vop_readdir    =   vboxvfs_readdir,
-    .vop_reclaim    =   vboxvfs_reclaim,
-    .vop_remove     =   vboxvfs_remove,
-    .vop_rename     =   vboxvfs_rename,
-    .vop_rmdir      =   vboxvfs_rmdir,
-    .vop_setattr    =   vboxvfs_setattr,
-    .vop_strategy   =   vboxvfs_strategy,
-    .vop_symlink    =   vboxvfs_symlink,
-    .vop_write      =   vboxvfs_write,
+	.vop_access	= vboxfs_access,
+	.vop_advlock	= VOP_EOPNOTSUPP,
+	.vop_close	= vboxfs_close,
+	.vop_create	= vboxfs_create,
+	.vop_fsync	= vboxfs_fsync,
+	.vop_getattr	= vboxfs_getattr,
+	.vop_getextattr = VOP_EOPNOTSUPP,
+	.vop_inactive	= vboxfs_inactive,
+	.vop_ioctl	= vboxfs_ioctl,
+	.vop_link	= vboxfs_link,
+	.vop_lookup	= vfs_cache_lookup,
+	.vop_cachedlookup	= vboxfs_lookup,
+	.vop_mkdir	= vboxfs_mkdir,
+	.vop_mknod	= VOP_EOPNOTSUPP,
+	.vop_open	= vboxfs_open,
+	.vop_pathconf	= vboxfs_pathconf,
+	.vop_print	= vboxfs_print,
+	.vop_read	= vboxfs_read,
+	.vop_readdir	= vboxfs_readdir,
+	.vop_readlink	= vboxfs_readlink,
+	.vop_reclaim	= vboxfs_reclaim,
+	.vop_remove	= vboxfs_remove,
+	.vop_rename	= vboxfs_rename,
+	.vop_rmdir	= vboxfs_rmdir,
+	.vop_setattr	= vboxfs_setattr,
+	.vop_vptofh 	= vboxfs_vptofh,
+	.vop_symlink	= vboxfs_symlink,
+	.vop_write	= vboxfs_write,
+	.vop_bmap	= VOP_EOPNOTSUPP
 };
 
-static int vboxvfs_access(struct vop_access_args *ap)
+static uint64_t
+vsfnode_cur_time_usec(void)
 {
-    return 0;
+	struct timeval now;
+
+	getmicrotime(&now);
+
+	return (now.tv_sec*1000 + now.tv_usec);
 }
 
-static int vboxvfs_open(struct vop_open_args *ap)
+static int
+vsfnode_stat_cached(struct vboxfs_node *np)
 {
-    return 0;
+	return (vsfnode_cur_time_usec() - np->sf_stat_time) <
+	    np->vboxfsmp->sf_stat_ttl * 1000UL;
 }
 
-static int vboxvfs_close(struct vop_close_args *ap)
+static int
+vsfnode_update_stat_cache(struct vboxfs_node *np)
 {
-    return 0;
+	int error;
+
+	error = sfprov_get_attr(np->vboxfsmp->sf_handle, np->sf_path,
+	    &np->sf_stat);
+#if 0
+	if (error == ENOENT)
+		sfnode_make_stale(node);
+#endif
+	if (error == 0)
+		np->sf_stat_time = vsfnode_cur_time_usec();
+
+	return (error);
 }
 
-static int vboxvfs_getattr(struct vop_getattr_args *ap)
+/*
+ * Need to clear v_object for insmntque failure.
+ */
+static void
+vboxfs_insmntque_dtr(struct vnode *vp, void *dtr_arg)
 {
-    return 0;
+
+	// XXX: vboxfs_destroy_vobject(vp, vp->v_object);
+	vp->v_object = NULL;
+	vp->v_data = NULL;
+	vp->v_op = &dead_vnodeops;
+	vgone(vp);
+	vput(vp);
 }
 
-static int vboxvfs_setattr(struct vop_setattr_args *ap)
+/*
+ * Allocates a new vnode for the node node or returns a new reference to
+ * an existing one if the node had already a vnode referencing it.  The
+ * resulting locked vnode is returned in *vpp.
+ *
+ * Returns zero on success or an appropriate error code on failure.
+ */
+int
+vboxfs_alloc_vp(struct mount *mp, struct vboxfs_node *node, int lkflag,
+    struct vnode **vpp)
 {
-    return 0;
+	struct vnode *vp;
+	int error;
+
+	error = 0;
+loop:
+	VBOXFS_NODE_LOCK(node);
+loop1:
+	if ((vp = node->sf_vnode) != NULL) {
+		MPASS((node->sf_vpstate & VBOXFS_VNODE_DOOMED) == 0);
+		VI_LOCK(vp);
+		if ((node->sf_type == VDIR && node->sf_parent == NULL) ||
+		    (VN_IS_DOOMED(vp) &&
+		    (lkflag & LK_NOWAIT) != 0)) {
+			VI_UNLOCK(vp);
+			VBOXFS_NODE_UNLOCK(node);
+			error = ENOENT;
+			vp = NULL;
+			goto out;
+		}
+		if (VN_IS_DOOMED(vp)) {
+			VI_UNLOCK(vp);
+			node->sf_vpstate |= VBOXFS_VNODE_WRECLAIM;
+			while ((node->sf_vpstate & VBOXFS_VNODE_WRECLAIM) != 0) {
+				msleep(&node->sf_vnode, VBOXFS_NODE_MTX(node),
+				    0, "vsfE", 0);
+			}
+			goto loop1;
+		}
+		VBOXFS_NODE_UNLOCK(node);
+#if __FreeBSD_version < 1300109
+		error = vget(vp, lkflag | LK_INTERLOCK, curthread);
+#else
+		error = vget(vp, lkflag | LK_INTERLOCK);
+#endif
+		if (error == ENOENT)
+			goto loop;
+		if (error != 0) {
+			vp = NULL;
+			goto out;
+		}
+
+		/*
+		 * Make sure the vnode is still there after
+		 * getting the interlock to avoid racing a free.
+		 */
+		if (node->sf_vnode == NULL || node->sf_vnode != vp) {
+			vput(vp);
+			goto loop;
+		}
+
+		goto out;
+	}
+
+	if ((node->sf_vpstate & VBOXFS_VNODE_DOOMED) ||
+	    (node->sf_type == VDIR && node->sf_parent == NULL)) {
+		VBOXFS_NODE_UNLOCK(node);
+		error = ENOENT;
+		vp = NULL;
+		goto out;
+	}
+
+	/*
+	 * otherwise lock the vp list while we call getnewvnode
+	 * since that can block.
+	 */
+	if (node->sf_vpstate & VBOXFS_VNODE_ALLOCATING) {
+		node->sf_vpstate |= VBOXFS_VNODE_WANT;
+		error = msleep((caddr_t) &node->sf_vpstate,
+		    VBOXFS_NODE_MTX(node), PDROP | PCATCH,
+		    "vboxfs_alloc_vp", 0);
+		if (error)
+			return error;
+
+		goto loop;
+	} else
+		node->sf_vpstate |= VBOXFS_VNODE_ALLOCATING;
+
+	VBOXFS_NODE_UNLOCK(node);
+
+	/* Get a new vnode and associate it with our node. */
+	error = getnewvnode("vboxfs", mp, &vboxfs_vnodeops, &vp);
+	if (error != 0)
+		goto unlock;
+	MPASS(vp != NULL);
+
+	/* lkflag is ignored, the lock is exclusive */
+	(void) vn_lock(vp, lkflag | LK_RETRY);
+
+	vp->v_data = node;
+	vp->v_type = node->sf_type;
+
+	/* Type-specific initialization. */
+	switch (node->sf_type) {
+	case VBLK:
+		/* FALLTHROUGH */
+	case VCHR:
+		/* FALLTHROUGH */
+	case VLNK:
+		/* FALLTHROUGH */
+	case VSOCK:
+		/* FALLTHROUGH */
+	case VFIFO:
+		/* FALLTHROUGH */
+	case VREG:
+		break;
+	case VDIR:
+		MPASS(node->sf_parent != NULL);
+		if (node->sf_parent == node)
+			vp->v_vflag |= VV_ROOT;
+		break;
+
+	default:
+		panic("vboxfs_alloc_vp: type %p %d", node, (int)node->sf_type);
+	}
+
+	if (vp->v_type != VFIFO)
+		VN_LOCK_ASHARE(vp);
+
+	error = insmntque1(vp, mp, vboxfs_insmntque_dtr, NULL);
+	if (error)
+		vp = NULL;
+
+unlock:
+	VBOXFS_NODE_LOCK(node);
+
+	MPASS(node->sf_vpstate & VBOXFS_VNODE_ALLOCATING);
+	node->sf_vpstate &= ~VBOXFS_VNODE_ALLOCATING;
+	node->sf_vnode = vp;
+
+	if (node->sf_vpstate & VBOXFS_VNODE_WANT) {
+		node->sf_vpstate &= ~VBOXFS_VNODE_WANT;
+		VBOXFS_NODE_UNLOCK(node);
+		wakeup((caddr_t) &node->sf_vpstate);
+	} else
+		VBOXFS_NODE_UNLOCK(node);
+
+out:
+	*vpp = vp;
+
+#ifdef INVARIANTS
+	if (error == 0) {
+		MPASS(*vpp != NULL && VOP_ISLOCKED(*vpp));
+		VBOXFS_NODE_LOCK(node);
+		MPASS(*vpp == node->sf_vnode);
+		VBOXFS_NODE_UNLOCK(node);
+	}
+#endif
+
+	return error;
 }
 
-static int vboxvfs_read(struct vop_read_args *ap)
+/*
+ * Destroys the association between the vnode vp and the node it
+ * references.
+ */
+void
+vboxfs_free_vp(struct vnode *vp)
 {
-    return 0;
+	struct vboxfs_node *node;
+
+	node = VP_TO_VBOXFS_NODE(vp);
+
+	VBOXFS_NODE_ASSERT_LOCKED(node);
+	node->sf_vnode = NULL;
+	if ((node->sf_vpstate & VBOXFS_VNODE_WRECLAIM) != 0)
+		wakeup(&node->sf_vnode);
+	node->sf_vpstate &= ~VBOXFS_VNODE_WRECLAIM;
+	vp->v_data = NULL;
 }
 
-static int vboxvfs_write(struct vop_write_args *ap)
+/*
+ * Allocate new vboxfs_node and vnode for given file
+ */
+static int
+vboxfs_alloc_file(struct vboxfs_mnt *vboxfsmp, const char *fullpath,
+    enum vtype type, mode_t mode, struct vboxfs_node *parent,
+    int lkflag, struct vnode **vpp)
 {
-    return 0;
+	int error;
+	struct vboxfs_node *unode;
+
+	error = vboxfs_alloc_node(vboxfsmp->sf_vfsp, vboxfsmp, fullpath, type,
+	    vboxfsmp->sf_uid, vboxfsmp->sf_gid, mode, parent, &unode);
+
+	if (error)
+		goto out;
+
+	error = vboxfs_alloc_vp(vboxfsmp->sf_vfsp, unode, lkflag, vpp);
+	if (error)
+		vboxfs_free_node(vboxfsmp, unode);
+
+out:
+	return (error);
 }
 
-static int vboxvfs_create(struct vop_create_args *ap)
+static int
+vboxfs_vn_get_ino_alloc(struct mount *mp, void *arg, int lkflags,
+    struct vnode **rvp)
 {
-    return 0;
+
+	return (vboxfs_alloc_vp(mp, arg, lkflags, rvp));
 }
 
-static int vboxvfs_remove(struct vop_remove_args *ap)
+/*
+ * Construct a new pathname given an sfnode plus an optional tail
+ * component of length len
+ * This handles ".." and "."
+ */
+static char *
+sfnode_construct_path(struct vboxfs_node *node, char *tail, int len)
 {
-    return 0;
+	char *p;
+
+	if (len <= 2 && tail[0] == '.' && (len == 1 || tail[1] == '.'))
+		panic("construct path for %s", tail);
+	p = malloc(strlen(node->sf_path) + 1 + len + 1, M_VBOXVFS, M_WAITOK);
+	strcpy(p, node->sf_path);
+	strcat(p, "/");
+	strcat(p, tail);
+	return (p);
 }
 
-static int vboxvfs_rename(struct vop_rename_args *ap)
+static int
+vboxfs_access(struct vop_access_args *ap)
 {
-    return 0;
+	struct vnode *vp = ap->a_vp;
+	accmode_t accmode = ap->a_accmode;
+	struct vboxfs_node *node;
+	int error;
+	mode_t m;
+
+	MPASS(VOP_ISLOCKED(vp));
+
+	node = VP_TO_VBOXFS_NODE(vp);
+
+	if ((accmode & VWRITE) && (vp->v_mount->mnt_flag & MNT_RDONLY)) {
+		switch (vp->v_type) {
+		case VDIR:
+		case VLNK:
+		case VREG:
+			return (EROFS);
+			/* NOT REACHED */
+		default:
+			break;
+		}
+	}
+
+	if (vsfnode_stat_cached(node))
+		error = 0;
+	else
+		error = vsfnode_update_stat_cache(node);
+	m = (error == 0) ? node->sf_stat.sf_mode : 0;
+
+#if __FreeBSD_version < 1300105
+	return (vaccess(vp->v_type, m, node->vboxfsmp->sf_uid,
+	    node->vboxfsmp->sf_gid, accmode, ap->a_cred, NULL));
+#else
+	return (vaccess(vp->v_type, m, node->vboxfsmp->sf_uid,
+	    node->vboxfsmp->sf_gid, accmode, ap->a_cred));
+#endif
 }
 
-static int vboxvfs_link(struct vop_link_args *ap)
+/*
+ * Clears the (cached) directory listing for the node.
+ */
+static void
+vfsnode_clear_dir_list(struct vboxfs_node *np)
 {
-    return EOPNOTSUPP;
+	while (np->sf_dir_list != NULL) {
+		sffs_dirents_t *next = np->sf_dir_list->sf_next;
+		free(np->sf_dir_list, M_VBOXVFS);
+		np->sf_dir_list = next;
+	}
 }
 
-static int vboxvfs_symlink(struct vop_symlink_args *ap)
+static int
+vboxfs_open(struct vop_open_args *ap)
 {
-    return EOPNOTSUPP;
+	struct vboxfs_node *np;
+	sfp_file_t *fp;
+	int error;
+
+	MPASS(VOP_ISLOCKED(vp));
+
+	np = VP_TO_VBOXFS_NODE(ap->a_vp);
+	error = sfprov_open(np->vboxfsmp->sf_handle, np->sf_path, &fp);
+	if (error != 0)
+		goto out;
+
+	np->sf_file = fp;
+	vnode_create_vobject(ap->a_vp, 0, ap->a_td);
+
+out:
+	MPASS(VOP_ISLOCKED(vp));
+
+	return (error);
 }
 
-static int vboxvfs_mknod(struct vop_mknod_args *ap)
+static void
+vfsnode_invalidate_stat_cache(struct vboxfs_node *np)
 {
-    return EOPNOTSUPP;
+	np->sf_stat_time = 0;
 }
 
-static int vboxvfs_mkdir(struct vop_mkdir_args *ap)
+static int
+vboxfs_close(struct vop_close_args *ap)
 {
-    return 0;
+	struct vnode *vp = ap->a_vp;
+	struct vboxfs_node *np;
+
+	np = VP_TO_VBOXFS_NODE(vp);
+
+	/*
+	 * Free the directory entries for the node. We do this on this call
+	 * here because the directory node may not become inactive for a long
+	 * time after the readdir is over. Case in point, if somebody cd's into
+	 * the directory then it won't become inactive until they cd away again.
+	 * In such a case we would end up with the directory listing not getting
+	 * updated (i.e. the result of 'ls' always being the same) until they
+	 * change the working directory.
+	 */
+	vfsnode_clear_dir_list(np);
+
+	vfsnode_invalidate_stat_cache(np);
+
+	if (np->sf_file != NULL && vp->v_usecount <= 1) {
+		(void) sfprov_close(np->sf_file);
+		np->sf_file = NULL;
+	}
+
+	return (0);
 }
 
-static int vboxvfs_rmdir(struct vop_rmdir_args *ap)
+static int
+vboxfs_getattr(struct vop_getattr_args *ap)
 {
-    return 0;
+	struct vnode 		*vp = ap->a_vp;
+	struct vattr 		*vap = ap->a_vap;
+	struct vboxfs_node	*np = VP_TO_VBOXFS_NODE(vp);
+	struct vboxfs_mnt  	*mp = np->vboxfsmp;
+	mode_t			mode;
+	int			error = 0;
+
+	mode = 0;
+	vap->va_type = vp->v_type;
+
+	vap->va_nlink = 1;		/* number of references to file */
+	vap->va_uid = mp->sf_uid;	/* owner user id */
+	vap->va_gid = mp->sf_gid;	/* owner group id */
+	vap->va_rdev = NODEV;		/* device the special file represents */
+	vap->va_gen = VNOVAL;		/* generation number of file */
+	vap->va_flags = 0;		/* flags defined for file */
+	vap->va_filerev = 0;		/* file modification number */
+	vap->va_vaflags = 0;		/* operations flags */
+	vap->va_fileid = np->sf_ino;	/* file id */
+	vap->va_fsid = vp->v_mount->mnt_stat.f_fsid.val[0];
+	if (vap->va_fileid == 0)
+		vap->va_fileid = 2;
+
+	vap->va_atime.tv_sec = VNOVAL;
+	vap->va_atime.tv_nsec = VNOVAL;
+	vap->va_mtime.tv_sec = VNOVAL;
+	vap->va_mtime.tv_nsec = VNOVAL;
+	vap->va_ctime.tv_sec = VNOVAL;
+	vap->va_ctime.tv_nsec = VNOVAL;
+
+	if (!vsfnode_stat_cached(np)) {
+		error = vsfnode_update_stat_cache(np);
+		if (error != 0)
+			goto done;
+	}
+
+	vap->va_atime = np->sf_stat.sf_atime;
+	vap->va_mtime = np->sf_stat.sf_mtime;
+	vap->va_ctime = np->sf_stat.sf_ctime;
+
+	mode = np->sf_stat.sf_mode;
+
+	vap->va_mode = mode;
+	if (S_ISDIR(mode)) {
+		vap->va_type = VDIR;	/* vnode type (for create) */
+		vap->va_mode = mp->sf_dmode != 0 ? (mp->sf_dmode & 0777) : vap->va_mode;
+		vap->va_mode &= ~mp->sf_dmask;
+		vap->va_mode |= S_IFDIR;
+	} else if (S_ISREG(mode)) {
+		vap->va_type = VREG;
+		vap->va_mode = mp->sf_fmode != 0 ? (mp->sf_fmode & 0777) : vap->va_mode;
+		vap->va_mode &= ~mp->sf_fmask;
+		vap->va_mode |= S_IFREG;
+	} else if (S_ISFIFO(mode))
+		vap->va_type = VFIFO;
+	else if (S_ISCHR(mode))
+		vap->va_type = VCHR;
+	else if (S_ISBLK(mode))
+		vap->va_type = VBLK;
+	else if (S_ISLNK(mode)) {
+		vap->va_type = VLNK;
+		vap->va_mode = mp->sf_fmode != 0 ? (mp->sf_fmode & 0777) : vap->va_mode;
+		vap->va_mode &= ~mp->sf_fmask;
+		vap->va_mode |= S_IFLNK;
+	} else if (S_ISSOCK(mode))
+		vap->va_type = VSOCK;
+
+	vap->va_size = np->sf_stat.sf_size;
+	vap->va_blocksize = 512;
+	/* bytes of disk space held by file */
+   	vap->va_bytes = (np->sf_stat.sf_alloc + 511) / 512;
+
+done:
+	return (error);
 }
 
-static int vboxvfs_readdir(struct vop_readdir_args *ap)
+static int
+vboxfs_setattr(struct vop_setattr_args *ap)
 {
-    return 0;
+	struct vnode 		*vp = ap->a_vp;
+	struct vattr 		*vap = ap->a_vap;
+	struct vboxfs_node	*np = VP_TO_VBOXFS_NODE(vp);
+	int			error;
+	mode_t			mode;
+
+	mode = vap->va_mode;
+	if (vp->v_type == VREG)
+		mode |= S_IFREG;
+	else if (vp->v_type == VDIR)
+		mode |= S_IFDIR;
+	else if (vp->v_type == VBLK)
+		mode |= S_IFBLK;
+	else if (vp->v_type == VCHR)
+		mode |= S_IFCHR;
+	else if (vp->v_type == VLNK)
+		mode |= S_IFLNK;
+	else if (vp->v_type == VFIFO)
+		mode |= S_IFIFO;
+	else if (vp->v_type == VSOCK)
+		mode |= S_IFSOCK;
+
+	vfsnode_invalidate_stat_cache(np);
+
+	error = sfprov_set_attr(np->vboxfsmp->sf_handle, np->sf_path,
+	    mode, vap->va_atime, vap->va_mtime, vap->va_ctime);
+#if 0
+	if (error == ENOENT)
+		sfnode_make_stale(np);
+#endif
+	if (vap->va_size != (u_quad_t)VNOVAL) {
+		switch (vp->v_type) {
+		case VDIR:
+			return (EISDIR);
+		case VLNK:
+			/* FALLTHROUGH */
+		case VREG:
+			error = sfprov_set_size(np->vboxfsmp->sf_handle, np->sf_path, vap->va_size);
+			break;
+		case VCHR:
+			/* FALLTHROUGH */
+		case VBLK:
+			/* FALLTHROUGH */
+		case VSOCK:
+			/* FALLTHROUGH */
+		case VFIFO:
+			/* FALLTHROUGH */
+		case VNON:
+			/* FALLTHROUGH */
+		case VBAD:
+			/* FALLTHROUGH */
+		case VMARKER:
+			return (0);
+		}
+	}
+
+	return (error);
 }
 
-static int vboxvfs_fsync(struct vop_fsync_args *ap)
+#define blkoff(vboxfsmp, loc)	((loc) & (vboxfsmp)->bmask)
+
+static int
+vboxfs_read(struct vop_read_args *ap)
 {
-    return 0;
+	struct vnode		*vp = ap->a_vp;
+	struct uio 		*uio = ap->a_uio;
+	struct vboxfs_node	*np = VP_TO_VBOXFS_NODE(vp);
+	int			error = 0;
+	uint32_t		bytes;
+	uint32_t		done;
+	unsigned long		offset;
+	ssize_t			total;
+	void			*tmpbuf;
+
+	if (vp->v_type == VDIR)
+		return (EISDIR);
+
+	if (vp->v_type != VREG)
+		return (EINVAL);
+
+	if (uio->uio_offset < 0)
+		return (EINVAL);
+
+	total = uio->uio_resid;
+	if (total == 0)
+		return (0);
+
+	/*
+	 * XXXGONZO: this is just to get things working
+	 * should be optimized
+	 */
+	tmpbuf = contigmalloc(PAGE_SIZE, M_DEVBUF, M_WAITOK, 0, ~0, PAGE_SIZE, 0);
+	if (tmpbuf == 0)
+		return (ENOMEM);
+
+	do {
+		offset = uio->uio_offset;
+		done = bytes = min(PAGE_SIZE, uio->uio_resid);
+		error = sfprov_read(np->sf_file, tmpbuf,
+		    offset, &done, 0);
+		if (error == 0 && done > 0)
+			error = uiomove(tmpbuf, done, uio);
+	} while (error == 0 && uio->uio_resid > 0 && done > 0);
+
+	contigfree(tmpbuf, PAGE_SIZE, M_DEVBUF);
+
+	/* a partial read is never an error */
+	if (total != uio->uio_resid)
+		error = 0;
+
+	return (error);
 }
 
-static int vboxvfs_print (struct vop_print_args *ap)
+static int
+vboxfs_write(struct vop_write_args *ap)
 {
-    return 0;
+	struct vnode		*vp = ap->a_vp;
+	struct uio 		*uio = ap->a_uio;
+	struct vboxfs_node	*np = VP_TO_VBOXFS_NODE(vp);
+	int			error = 0;
+	uint32_t		bytes;
+	uint32_t		done;
+	unsigned long		offset;
+	ssize_t			total;
+	void			*tmpbuf;
+
+	if (vp->v_type == VDIR)
+		return (EISDIR);
+
+	if (vp->v_type != VREG)
+		return (EINVAL);
+
+	if (uio->uio_offset < 0)
+		return (EINVAL);
+
+	total = uio->uio_resid;
+	if (total == 0)
+		return (0);
+
+	/*
+	 * XXXGONZO: this is just to get things working
+	 * should be optimized
+	 */
+	tmpbuf = contigmalloc(PAGE_SIZE, M_DEVBUF, M_WAITOK, 0, ~0, PAGE_SIZE, 0);
+	if (tmpbuf == 0)
+		return (ENOMEM);
+
+	do {
+		offset = uio->uio_offset;
+		bytes = min(PAGE_SIZE, uio->uio_resid);
+		error = uiomove(tmpbuf, bytes, uio);
+		if (error != 0)
+			break;
+		done = bytes;
+		error = sfprov_write(np->sf_file, tmpbuf,
+		    offset, &done, 0);
+		if (error != 0)
+			break;
+		total -= done;
+		if (done != bytes)
+			uio->uio_resid += bytes - done;
+	} while (error == 0 && uio->uio_resid > 0 && done > 0);
+
+	contigfree(tmpbuf, PAGE_SIZE, M_DEVBUF);
+
+	/* a partial write is never an error */
+	if (total != uio->uio_resid)
+		error = 0;
+
+	return (error);
 }
 
-static int vboxvfs_pathconf (struct vop_pathconf_args *ap)
+static int
+vboxfs_create(struct vop_create_args *ap)
 {
-    return 0;
+	struct vnode *dvp = ap->a_dvp;
+	struct vnode **vpp = ap->a_vpp;
+	struct componentname *cnp = ap->a_cnp;
+	struct vattr *vap = ap->a_vap;
+	sffs_stat_t	stat;
+	char	*fullpath = NULL;
+	struct vboxfs_node *dir = VP_TO_VBOXFS_NODE(dvp);
+	sfp_file_t *fp;
+	int error;
+	struct 	vboxfs_mnt *vboxfsmp = dir->vboxfsmp;
+
+	MPASS(vap->va_type == VREG);
+
+	fullpath = sfnode_construct_path(dir, cnp->cn_nameptr, cnp->cn_namelen);
+	error = sfprov_create(dir->vboxfsmp->sf_handle, fullpath, vap->va_mode,
+	    &fp, &stat);
+
+	if (error)
+		goto out;
+
+	error = vboxfs_alloc_file(vboxfsmp, fullpath, VREG, vap->va_mode, dir, cnp->cn_lkflags, vpp);
+
+out:
+	if (fullpath)
+		free(fullpath, M_VBOXVFS);
+
+	if (error == 0) {
+		vfsnode_clear_dir_list(dir);
+		if ((cnp->cn_flags & MAKEENTRY) != 0)
+			cache_enter(dvp, *vpp, cnp);
+	}
+
+	return (error);
 }
 
-static int vboxvfs_strategy (struct vop_strategy_args *ap)
+static int
+vboxfs_remove(struct vop_remove_args *ap)
 {
-    return 0;
+	struct vnode *dvp = ap->a_dvp;
+	struct vnode *vp = ap->a_vp;
+	struct vboxfs_node *np, *dir;
+
+	int error;
+
+	MPASS(VOP_ISLOCKED(dvp));
+	MPASS(VOP_ISLOCKED(vp));
+
+	error = 0;
+
+	np = VP_TO_VBOXFS_NODE(vp);
+	dir = VP_TO_VBOXFS_NODE(vp);
+
+	/*
+	 * If anything else is using this vnode, then fail the remove.
+	 * Why?  Windows hosts can't sfprov_remove() a file that is open,
+	 * so we have to sfprov_close() it first.
+	 * There is no errno for this - since it's not a problem on UNIX,
+	 * but ETXTBSY is the closest.
+	 */
+	if (np->sf_file != NULL) {
+		if (vp->v_usecount > 1) {
+			error = ETXTBSY;
+			goto out;
+		}
+		sfprov_close(np->sf_file);
+		np->sf_file = NULL;
+	}
+
+	error = sfprov_remove(np->vboxfsmp->sf_handle, np->sf_path,
+	    np->sf_type == VLNK);
+
+#if 0
+	if (error == ENOENT || error == 0)
+		sfnode_make_stale(np);
+#endif
+
+	if (error == 0)
+		vfsnode_clear_dir_list(dir);
+
+out:
+	return (error);
 }
 
-static int vboxvfs_ioctl(struct vop_ioctl_args *ap)
+static int
+vboxfs_rename(struct vop_rename_args *ap)
 {
-    return ENOTTY;
+	struct vnode *fvp;
+	struct vnode *fdvp;
+	struct vnode *tvp;
+	struct vnode *tdvp;
+	struct componentname *fcnp;
+	struct componentname *tcnp;
+	struct vboxfs_node *np;
+	int ret;
+
+	fvp = ap->a_fvp;
+	fdvp = ap->a_fdvp;
+	tvp = ap->a_tvp;
+	tdvp = ap->a_tdvp;
+	fcnp = ap->a_fcnp;
+	tcnp = ap->a_tcnp;
+
+	/* Check for cross-device rename */
+	if ((fvp->v_mount != tdvp->v_mount) ||
+	    (tvp && (fvp->v_mount != tvp->v_mount))) {
+		ret = EXDEV;
+		goto out;
+	}
+	np = VP_TO_VBOXFS_NODE(fvp);
+	if (np == NULL)
+		return (0);
+	ret = sfprov_rename(np->vboxfsmp->sf_handle,
+	    fcnp->cn_nameptr, tcnp->cn_nameptr, fvp->v_type == VDIR);
+out:
+	if (tdvp == tvp)
+		vrele(tdvp);
+	else
+		vput(tdvp);
+	if (tvp)
+		vput(tvp);
+	vrele(fdvp);
+	vrele(fvp);
+	return (ret);
 }
 
-static int vboxvfs_getextattr(struct vop_getextattr_args *ap)
+static int
+vboxfs_link(struct vop_link_args *ap)
 {
-    return 0;
+	return (EOPNOTSUPP);
 }
 
-static int vboxvfs_advlock(struct vop_advlock_args *ap)
+static int
+vboxfs_symlink(struct vop_symlink_args *ap)
 {
-    return 0;
+	struct vnode *dvp = ap->a_dvp;
+	struct vnode **vpp = ap->a_vpp;
+	struct componentname *cnp = ap->a_cnp;
+	struct vattr *vap = ap->a_vap;
+	sffs_stat_t	stat;
+	char	*fullpath = NULL;
+	struct vboxfs_node *dir = VP_TO_VBOXFS_NODE(dvp);
+	int error;
+	struct 	vboxfs_mnt *vboxfsmp = dir->vboxfsmp;
+
+	MPASS(vap->va_type == VLNK);
+
+	fullpath = sfnode_construct_path(dir, cnp->cn_nameptr, cnp->cn_namelen);
+	error = sfprov_symlink(dir->vboxfsmp->sf_handle, fullpath, ap->a_target, &stat);
+
+	if (error)
+		goto out;
+
+	error = vboxfs_alloc_file(vboxfsmp, fullpath, VLNK, vap->va_mode, dir, cnp->cn_lkflags, vpp);
+
+out:
+	if (fullpath)
+		free(fullpath, M_VBOXVFS);
+
+	if (error == 0)
+		vfsnode_clear_dir_list(dir);
+
+	return (error);
 }
 
-static int vboxvfs_lookup(struct vop_lookup_args *ap)
+static int
+vboxfs_mkdir(struct vop_mkdir_args *ap)
 {
-    return 0;
+	struct vnode *dvp = ap->a_dvp;
+	struct vnode **vpp = ap->a_vpp;
+	struct componentname *cnp = ap->a_cnp;
+	struct vattr *vap = ap->a_vap;
+	sffs_stat_t	stat;
+	char	*fullpath = NULL;
+	struct vboxfs_node *dir = VP_TO_VBOXFS_NODE(dvp);
+	sfp_file_t *fp;
+	int error;
+	struct 	vboxfs_mnt *vboxfsmp = dir->vboxfsmp;
+
+	MPASS(vap->va_type == VDIR);
+
+	fullpath = sfnode_construct_path(dir, cnp->cn_nameptr, cnp->cn_namelen);
+	error = sfprov_mkdir(dir->vboxfsmp->sf_handle, fullpath, vap->va_mode,
+	    &fp, &stat);
+
+	if (error)
+		goto out;
+
+	error = vboxfs_alloc_file(vboxfsmp, fullpath, VDIR, vap->va_mode, dir, cnp->cn_lkflags, vpp);
+
+out:
+	if (fullpath)
+		free(fullpath, M_VBOXVFS);
+
+	if (error == 0)
+		vfsnode_clear_dir_list(dir);
+
+	return (error);
 }
 
-static int vboxvfs_inactive(struct vop_inactive_args *ap)
+static int
+vboxfs_rmdir(struct vop_rmdir_args *ap)
 {
-    return 0;
+	struct vnode *dvp = ap->a_dvp;
+	struct vnode *vp = ap->a_vp;
+	struct vboxfs_node *np, *dir;
+
+	int error;
+
+	MPASS(VOP_ISLOCKED(dvp));
+	MPASS(VOP_ISLOCKED(vp));
+
+	error = 0;
+
+	np = VP_TO_VBOXFS_NODE(vp);
+	dir = VP_TO_VBOXFS_NODE(vp);
+
+	/*
+	 * If anything else is using this vnode, then fail the remove.
+	 * Why?  Windows hosts can't sfprov_remove() a file that is open,
+	 * so we have to sfprov_close() it first.
+	 * There is no errno for this - since it's not a problem on UNIX,
+	 * but ETXTBSY is the closest.
+	 */
+	if (np->sf_file != NULL) {
+		if (vp->v_usecount > 1) {
+			error = ETXTBSY;
+			goto out;
+		}
+		sfprov_close(np->sf_file);
+		np->sf_file = NULL;
+	}
+
+	error = sfprov_rmdir(np->vboxfsmp->sf_handle, np->sf_path);
+
+#if 0
+	if (error == ENOENT || error == 0)
+		sfnode_make_stale(np);
+#endif
+
+	if (error == 0)
+		vfsnode_clear_dir_list(dir);
+
+out:
+	return (error);
 }
 
-static int vboxvfs_reclaim(struct vop_reclaim_args *ap)
+static int
+vboxfs_readdir(struct vop_readdir_args *ap)
 {
-    return 0;
+	int *eofp = ap->a_eofflag;
+	struct vnode *vp = ap->a_vp;
+	struct uio *uio = ap->a_uio;
+	struct vboxfs_node *dir = VP_TO_VBOXFS_NODE(vp);
+	struct vboxfs_node *node;
+	struct sffs_dirent *dirent = NULL;
+	sffs_dirents_t *cur_buf;
+	off_t offset = 0;
+	off_t orig_off = uio->uio_offset;
+	int error = 0;
+	int dummy_eof;
+
+	if (vp->v_type != VDIR)
+		return (ENOTDIR);
+
+	if (eofp == NULL)
+		eofp = &dummy_eof;
+	*eofp = 0;
+
+	/*
+	 * Get the directory entry names from the host. This gets all
+	 * entries. These are stored in a linked list of sffs_dirents_t
+	 * buffers, each of which contains a list of dirent64_t's.
+	 */
+	if (dir->sf_dir_list == NULL) {
+		error = sfprov_readdir(dir->vboxfsmp->sf_handle, dir->sf_path,
+		    &dir->sf_dir_list);
+		if (error != 0)
+			goto done;
+	}
+
+	/*
+	 * Validate and skip to the desired offset.
+	 */
+	cur_buf = dir->sf_dir_list;
+	offset = 0;
+
+	while (cur_buf != NULL && offset + cur_buf->sf_len <= uio->uio_offset) {
+		offset += cur_buf->sf_len;
+		cur_buf = cur_buf->sf_next;
+	}
+
+	if (cur_buf == NULL && offset != uio->uio_offset) {
+		error = EINVAL;
+		goto done;
+	}
+
+	if (cur_buf != NULL && offset != uio->uio_offset) {
+		off_t off = offset;
+		int step;
+		dirent = &cur_buf->sf_entries[0];
+
+		while (off < uio->uio_offset) {
+			if (dirent->sf_off == uio->uio_offset)
+				break;
+			step = sizeof(struct sffs_dirent) + dirent->sf_entry.d_reclen;
+			dirent = (struct sffs_dirent *) (((char *) dirent) + step);
+			off += step;
+		}
+
+		if (off >= uio->uio_offset) {
+			error = EINVAL;
+			goto done;
+		}
+	}
+
+	offset = uio->uio_offset - offset;
+
+	/*
+	 * Lookup each of the names, so that we have ino's, and copy to
+	 * result buffer.
+	 */
+	while (cur_buf != NULL) {
+		if (offset >= cur_buf->sf_len) {
+			cur_buf = cur_buf->sf_next;
+			offset = 0;
+			continue;
+		}
+
+		dirent = (struct sffs_dirent *)
+		    (((char *) &cur_buf->sf_entries[0]) + offset);
+		if (dirent->sf_entry.d_reclen > uio->uio_resid)
+			break;
+
+		if (strcmp(dirent->sf_entry.d_name, ".") == 0) {
+			node = dir;
+		} else if (strcmp(dirent->sf_entry.d_name, "..") == 0) {
+			node = dir->sf_parent;
+			if (node == NULL)
+				node = dir;
+		} else {
+#if 0
+			node = vsfnode_lookup(dir, dirent->sf_entry.d_name, VNON,
+			    0, &dirent->sf_stat, vsfnode_cur_time_usec(), NULL);
+			if (node == NULL)
+				panic("sffs_readdir() lookup failed");
+#endif
+		}
+
+		if (node)
+			dirent->sf_entry.d_fileno = node->sf_ino;
+		else
+			dirent->sf_entry.d_fileno = 0xdeadbeef;
+
+		error = uiomove(&dirent->sf_entry, dirent->sf_entry.d_reclen, uio);
+		if (error != 0)
+			break;
+
+		uio->uio_offset = dirent->sf_off;
+		offset += sizeof(struct sffs_dirent) + dirent->sf_entry.d_reclen;
+	}
+
+	if (error == 0 && cur_buf == NULL)
+		*eofp = 1;
+done:
+	if (error != 0)
+		uio->uio_offset = orig_off;
+	return (error);
 }
 
-static int vboxvfs_getpages(struct vop_getpages_args *ap)
+static int
+vboxfs_readlink(struct vop_readlink_args *v)
 {
-    return 0;
+	struct vnode *vp = v->a_vp;
+	struct uio *uio = v->a_uio;
+
+	int error;
+	struct vboxfs_node *np;
+	void *tmpbuf;
+
+	MPASS(uio->uio_offset == 0);
+	MPASS(vp->v_type == VLNK);
+
+	np = VP_TO_VBOXFS_NODE(vp);
+
+	tmpbuf = contigmalloc(MAXPATHLEN, M_DEVBUF, M_WAITOK, 0, ~0, 1, 0);
+	if (tmpbuf == NULL)
+		return (ENOMEM);
+
+	error = sfprov_readlink(np->vboxfsmp->sf_handle, np->sf_path, tmpbuf,
+	    MAXPATHLEN);
+	if (error)
+		goto done;
+
+	error = uiomove(tmpbuf, strlen(tmpbuf), uio);
+
+done:
+	if (tmpbuf)
+		contigfree(tmpbuf, MAXPATHLEN, M_DEVBUF);
+	return (error);
 }
 
-static int vboxvfs_putpages(struct vop_putpages_args *ap)
+static int
+vboxfs_fsync(struct vop_fsync_args *ap)
 {
-    return 0;
+	struct vnode *vp;
+	struct vboxfs_node *np;
+	int ret;
+
+	vp = ap->a_vp;
+	np = VP_TO_VBOXFS_NODE(vp);
+	if (np == NULL)
+		return (0);
+	ret = sfprov_fsync(np->sf_file);
+	return (ret);
 }
 
+static int
+vboxfs_print(struct vop_print_args *ap)
+{
+	struct vnode *vp = ap->a_vp;
+	struct vboxfs_node *np;
+
+	np = VP_TO_VBOXFS_NODE(vp);
+
+	if (np == NULL) {
+		printf("No vboxfs_node data\n");
+		return (0);
+	}
+
+	printf("\tpath = %s, parent = %p", np->sf_path,
+	    np->sf_parent ? np->sf_parent : NULL);
+	printf("\n");
+	return (0);
+}
+
+static int
+vboxfs_pathconf(struct vop_pathconf_args *ap)
+{
+	register_t *retval = ap->a_retval;
+	int error = 0;
+
+	switch (ap->a_name) {
+	case _PC_LINK_MAX:
+		*retval = 65535;
+		break;
+	case _PC_NAME_MAX:
+		*retval = NAME_MAX;
+		break;
+	case _PC_PATH_MAX:
+		*retval = PATH_MAX;
+		break;
+	default:
+		error = EINVAL;
+		break;
+	}
+	return (error);
+}
+
+/*
+ * File specific ioctls.
+ */
+static int
+vboxfs_ioctl(struct vop_ioctl_args *ap)
+{
+	return (ENOTTY);
+}
+
+/*
+ * Lookup an entry in a directory and create a new vnode if found.
+ */
+static int
+vboxfs_lookup(struct vop_cachedlookup_args /* {
+		struct vnodeop_desc *a_desc;
+		struct vnode *a_dvp;
+		struct vnode **a_vpp;
+		struct componentname *a_cnp;
+	} */ *ap)
+{
+	struct 	componentname *cnp = ap->a_cnp;
+	struct 	vnode *dvp = ap->a_dvp;		/* the directory vnode */
+	char	*nameptr = cnp->cn_nameptr;	/* the name of the file or directory */
+	struct	vnode **vpp = ap->a_vpp;	/* the vnode we found or NULL */
+	struct  vnode *tdp = NULL;
+	struct 	vboxfs_node *node = VP_TO_VBOXFS_NODE(dvp);
+	struct 	vboxfs_mnt *vboxfsmp = node->vboxfsmp;
+	u_long  nameiop = cnp->cn_nameiop;
+	u_long 	flags = cnp->cn_flags;
+	sffs_stat_t	stat;
+	//long 	namelen;
+	ino_t 	id = 0;
+	int 	ltype, type, error = 0;
+	int 	lkflags = cnp->cn_lkflags;
+	char	*fullpath = NULL;
+
+	error = ENOENT;
+	if (cnp->cn_flags & ISDOTDOT) {
+		error = vn_vget_ino_gen(dvp, vboxfs_vn_get_ino_alloc,
+		    node->sf_parent, cnp->cn_lkflags, vpp);
+		error = ENOENT;
+		if (error != 0)
+			goto out;
+
+	} else if (cnp->cn_namelen == 1 && cnp->cn_nameptr[0] == '.') {
+		VREF(dvp);
+		*vpp = dvp;
+		error = 0;
+	} else {
+		mode_t m;
+		type = VNON;
+		fullpath = sfnode_construct_path(node, cnp->cn_nameptr, cnp->cn_namelen);
+		error = sfprov_get_attr(node->vboxfsmp->sf_handle,
+		    fullpath, &stat);
+		// stat_time = vsfnode_cur_time_usec();
+
+		m = stat.sf_mode;
+		if (error != 0) {
+			/* The entry was not found in the directory.
+			 * This is OK if we are creating or renaming an
+			 * entry and are working on the last component of
+			 * the path name. */
+			if ((cnp->cn_flags & ISLASTCN) &&
+			    (cnp->cn_nameiop == CREATE || \
+			    cnp->cn_nameiop == RENAME ||
+			    (cnp->cn_nameiop == DELETE &&
+			    cnp->cn_flags & DOWHITEOUT &&
+			    cnp->cn_flags & ISWHITEOUT))) {
+				error = VOP_ACCESS(dvp, VWRITE, cnp->cn_cred,
+				    cnp->cn_thread);
+				if (error != 0)
+					goto out;
+
+				/* Keep the component name in the buffer for
+				 * future uses. */
+				cnp->cn_flags |= SAVENAME;
+
+				error = EJUSTRETURN;
+			} else
+				error = ENOENT;
+		}
+		else {
+			if (S_ISDIR(m))
+				type = VDIR;
+			else if (S_ISREG(m))
+				type = VREG;
+			else if (S_ISLNK(m))
+				type = VLNK;
+			error = vboxfs_alloc_file(vboxfsmp, fullpath, type, 0755, node, cnp->cn_lkflags, vpp);
+		}
+	}
+
+	if ((cnp->cn_flags & MAKEENTRY) != 0)
+		cache_enter(dvp, *vpp, cnp);
+out:
+	if (fullpath)
+		free(fullpath, M_VBOXVFS);
+
+	return (error);
+}
+
+static int
+vboxfs_inactive(struct vop_inactive_args *ap)
+{
+   	return (0);
+}
+
+static int
+vboxfs_reclaim(struct vop_reclaim_args *ap)
+{
+	struct vnode *vp;
+	struct vboxfs_node *node;
+	struct 	vboxfs_mnt *vboxfsmp;
+
+	vp = ap->a_vp;
+	node = VP_TO_VBOXFS_NODE(vp);
+	vboxfsmp = node->vboxfsmp;
+
+	vnode_destroy_vobject(vp);
+	vp->v_object = NULL;
+	cache_purge(vp);
+
+	VBOXFS_NODE_LOCK(node);
+	VBOXFS_ASSERT_ELOCKED(node);
+	vboxfs_free_vp(vp);
+
+	/* If the node referenced by this vnode was deleted by the user,
+	 * we must free its associated data structures (now that the vnode
+	 * is being reclaimed). */
+	if ((node->sf_vpstate & VBOXFS_VNODE_ALLOCATING) == 0) {
+		node->sf_vpstate = VBOXFS_VNODE_DOOMED;
+		VBOXFS_NODE_UNLOCK(node);
+		vboxfs_free_node(vboxfsmp, node);
+	} else
+		VBOXFS_NODE_UNLOCK(node);
+
+	MPASS(vp->v_data == NULL);
+
+	return (0);
+}
+
+static int
+vboxfs_vptofh(struct vop_vptofh_args *ap)
+{
+
+	return (EOPNOTSUPP);
+}

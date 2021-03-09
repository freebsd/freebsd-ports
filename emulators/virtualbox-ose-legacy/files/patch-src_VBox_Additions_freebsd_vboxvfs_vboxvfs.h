--- src/VBox/Additions/freebsd/vboxvfs/vboxvfs.h.orig	2018-06-29 13:08:17 UTC
+++ src/VBox/Additions/freebsd/vboxvfs/vboxvfs.h
@@ -1,8 +1,3 @@
-/* $Id: vboxvfs.h $ */
-/** @file
- * Description.
- */
-
 /*
  * Copyright (C) 2010-2017 Oracle Corporation
  *
@@ -21,72 +16,413 @@
 #define VBOXVFS_VFSNAME "vboxvfs"
 #define VBOXVFS_VERSION 1
 
-#define MAX_HOST_NAME 256
-#define MAX_NLS_NAME 32
+#define MAX_HOST_NAME 	256
+#define MAX_NLS_NAME 	32
+//#define MODEMASK	07777	/* mode bits plus permission bits */
+/** Helper macros */
+#define VFSTOVBOXFS(mp)		((struct vboxfs_mnt *)((mp)->mnt_data))
+#define VP_TO_VBOXFS_NODE(vp) 	((struct vboxfs_node *)(vp)->v_data)
+#define VBOXTOV(np)		((struct vnode *)(np)->n_vnode)
 
-struct vboxvfs_mount_info {
-    char name[MAX_HOST_NAME];
-    char nls_name[MAX_NLS_NAME];
-    int uid;
-    int gid;
-    int ttl;
-};
+#define	ROOTDIR_INO		1
+#define	THEFILE_INO		2
+#define THEFILE_NAME	"thefile"
 
+#define VBOXFS_NODE_LOCK(node) mtx_lock(&(node)->sf_interlock)
+#define VBOXFS_NODE_UNLOCK(node) mtx_unlock(&(node)->sf_interlock)
+#define VBOXFS_NODE_MTX(node) (&(node)->sf_interlock)
+#define	VBOXFS_NODE_ASSERT_LOCKED(node) mtx_assert(VBOXFS_NODE_MTX(node), \
+    MA_OWNED)
+
+#ifdef INVARIANTS
+#define VBOXFS_ASSERT_LOCKED(node) do {					\
+		MPASS(node != NULL);					\
+		MPASS(node->sf_vnode != NULL);				\
+		if (!VOP_ISLOCKED(node->sf_vnode) &&			\
+		    !mtx_owned(VBOXFS_NODE_MTX(node)))			\
+			panic("vboxfs: node is not locked: %p", node);	\
+	} while (0)
+#define VBOXFS_ASSERT_ELOCKED(node) do {					\
+		MPASS((node) != NULL);					\
+		MPASS((node)->sf_vnode != NULL);			\
+		mtx_assert(VBOXFS_NODE_MTX(node), MA_OWNED);		\
+		ASSERT_VOP_LOCKED((node)->sf_vnode, "vboxfs");		\
+	} while (0)
+#else
+#define VBOXFS_ASSERT_LOCKED(node) (void)0
+#define VBOXFS_ASSERT_ELOCKED(node) (void)0
+#endif
+
+#define	VBOXFS_VNODE_ALLOCATING	1
+#define	VBOXFS_VNODE_WANT	2
+#define	VBOXFS_VNODE_DOOMED	4
+#define	VBOXFS_VNODE_WRECLAIM	8
+
+MALLOC_DECLARE(M_VBOXVFS);
+
 #ifdef _KERNEL
+#ifndef FREEBSD_STYLE
+#include "../../../../../include/iprt/nocrt/limits.h"
+#include "../../../../../include/iprt/alloc.h"
+#include "../../../../../include/iprt/asm.h"
+#include "../../../../../include/iprt/asm-amd64-x86.h"
+#include "../../../../../include/iprt/asm-math.h"
+#include "../../../../../include/iprt/assert.h"
+#include "../../../../../include/iprt/cdefs.h"
+#include "../../../../../include/iprt/err.h"
+#include "../../../../../include/iprt/fs.h"
+#include "../../../../../include/iprt/log.h"
+#include "../../../../../include/iprt/mangling.h"
+#include "../../../../../include/iprt/mem.h"
+#include "../../../../../include/iprt/param.h"
+#include "../../../../../include/iprt/path.h"
+#include "../../../../../include/iprt/semaphore.h"
+#include "../../../../../include/iprt/stdarg.h"
+#include "../../../../../include/iprt/stdint.h"
+#include "../../../../../include/iprt/string.h"
+#include "../../../../../include/iprt/time.h"
+#include "../../../../../include/iprt/types.h"
+#include "../../../../../include/iprt/uni.h"
+#include "../../../../../include/iprt/nocrt/limits.h"
+#include "../../../../../include/iprt/alloc.h"
+#include "../../../../../include/iprt/asm.h"
+#include "../../../../../include/iprt/asm-amd64-x86.h"
+#include "../../../../../include/iprt/asm-math.h"
+#include "../../../../../include/iprt/assert.h"
+#include "../../../../../include/iprt/cdefs.h"
+#include "../../../../../include/iprt/err.h"
+#include "../../../../../include/iprt/fs.h"
+#include "../../../../../include/iprt/log.h"
+#include "../../../../../include/iprt/mangling.h"
+#include "../../../../../include/iprt/mem.h"
+#include "../../../../../include/iprt/param.h"
+#include "../../../../../include/iprt/path.h"
+#include "../../../../../include/iprt/semaphore.h"
+#include "../../../../../include/iprt/stdarg.h"
+#include "../../../../../include/iprt/stdint.h"
+#include "../../../../../include/iprt/string.h"
+#include "../../../../../include/iprt/time.h"
+#include "../../../../../include/iprt/types.h"
+#include "../../../../../include/iprt/uni.h"
 
-#include <VBox/VBoxGuestLibSharedFolders.h>
+#else
+
+#include "iprt/nocrt/limits.h"
+#include "iprt/alloc.h"
+#include "iprt/asm.h"
+#include "iprt/asm-amd64-x86.h"
+#include "iprt/asm-math.h"
+#include "iprt/assert.h"
+#include "iprt/cdefs.h"
+#include "iprt/err.h"
+#include "iprt/fs.h"
+#include "iprt/log.h"
+#include "iprt/mem.h"
+#include "iprt/param.h"
+#include "iprt/path.h"
+#include "iprt/semaphore.h"
+#include "iprt/stdarg.h"
+#include "iprt/stdint.h"
+#include "iprt/string.h"
+#include "iprt/time.h"
+#include "iprt/types.h"
+#include "iprt/uni.h"
+#include "iprt/nocrt/limits.h"
+#include "iprt/alloc.h"
+#include "iprt/asm.h"
+#include "iprt/asm-amd64-x86.h"
+#include "iprt/asm-math.h"
+#include "iprt/assert.h"
+#include "iprt/cdefs.h"
+#include "iprt/err.h"
+#include "iprt/fs.h"
+#include "iprt/log.h"
+#include "iprt/mem.h"
+#include "iprt/param.h"
+#include "iprt/path.h"
+#include "iprt/semaphore.h"
+#include "iprt/stdarg.h"
+#include "iprt/stdint.h"
+#include "iprt/string.h"
+#include "iprt/time.h"
+#include "iprt/types.h"
+#include "iprt/uni.h"
+
+#include "common/VBoxGuestLib/SysHlp.h"
+
+#endif /* !FREEBSD_STYLE */
+
 #include <sys/mount.h>
 #include <sys/vnode.h>
+#include <sys/_timespec.h>
 
-struct vboxvfsmount {
-    uid_t           uid;
-    gid_t           gid;
-    mode_t          file_mode;
-    mode_t          dir_mode;
-    struct mount   *mp;
-    struct ucred   *owner;
-    u_int           flags;
-    long            nextino;
-    int             caseopt;
-    int             didrele;
+#include <VBox/VBoxGuestLibSharedFolders.h>
+
+#define	VBOXVFS_DEBUG(lvl, ...)	do {					\
+	if (vboxvfs_debug >= (lvl)) {					\
+		printf("VBOXVFS[%u]: ", lvl);				\
+		printf(__VA_ARGS__);					\
+		printf("\n");						\
+	}								\
+} while (0)
+
+/*
+ * representation of an active mount point
+ */
+struct sfp_mount {
+	VBGLSFMAP map;
 };
 
-/* structs - stolen from the linux shared module code */
+/*
+ * Mount / Unmount a shared folder.
+ *
+ * sfprov_mount() takes as input the connection pointer and the name of
+ * the shared folder. On success, it returns zero and supplies an
+ * sfp_mount_t handle. On failure it returns any relevant errno value.
+ *
+ * sfprov_unmount() unmounts the mounted file system. It returns 0 on
+ * success and any relevant errno on failure.
+ */
+typedef struct sfp_mount sfp_mount_t;
+
+struct sfp_file {
+	SHFLHANDLE handle;
+	VBGLSFMAP map;	/* need this again for the close operation */
+};
+
+typedef struct sfp_file sfp_file_t;
+
+/*
+ * File operations: open/close/read/write/etc.
+ *
+ * open/create can return any relevant errno, however ENOENT
+ * generally means that the host file didn't exist.
+ */
+typedef struct sffs_stat {
+	mode_t		sf_mode;
+	off_t		sf_size;
+	off_t		sf_alloc;
+	struct timespec	sf_atime;
+	struct timespec	sf_mtime;
+	struct timespec	sf_ctime;
+} sffs_stat_t;
+
+/*
+ * Read directory entries.
+ */
+/*
+ * a singly linked list of buffers, each containing an array of stat's+dirent's.
+ * sf_len is length of the sf_entries array, in bytes.
+ */
+typedef struct sffs_dirents {
+	struct sffs_dirents	*sf_next;
+	long long sf_len;
+	struct sffs_dirent {
+		sffs_stat_t	sf_stat;
+		struct dirent	sf_entry;	/* this is variable length */
+		off_t sf_off;
+	} sf_entries[1];
+} sffs_dirents_t;
+
+/*
+ * Shared Folders filesystem per-mount data structure.
+ */
+struct vboxfs_mnt {
+	struct mount	*sf_vfsp;	/* filesystem's vfs struct */
+	sfp_mount_t	*sf_handle;	/* guest-host communication handle */
+	uid_t		sf_uid;		/* owner of all shared folders */
+	gid_t		sf_gid;		/* group of all shared folders */
+	mode_t		sf_dmode;	/* mode of all directories */
+	mode_t		sf_fmode;	/* mode of all files */
+	mode_t		sf_dmask;	/* mask of all directories */
+	mode_t		sf_fmask;	/* mask of all files */
+	int		sf_stat_ttl;	/* ttl for stat caches (in ms) */
+	int		sf_fsync;	/* whether to honor fsync or not */
+	uint64_t	sf_ino;		/* per FS ino generator */
+	uma_zone_t	sf_node_pool;
+	struct vboxfs_node	*sf_root;
+};
+
+/*
+ * vboxfs_node is the file system dependent vnode data for vboxfs.
+ * vboxfs_node's also track all files ever accessed, both open and closed.
+ * It duplicates some of the information in vnode, since it holds
+ * information for files that may have been completely closed.
+ *
+ */
+struct vboxfs_node {
+	struct vboxfs_mnt	*vboxfsmp;	/* containing mounted file system */
+	char			*sf_path;	/* full pathname to file or dir */
+	uint64_t		sf_ino;		/* assigned unique ID number */
+	struct vnode		*sf_vnode;	/* vnode if active */
+	sfp_file_t		*sf_file;	/* non NULL if open */
+	struct vboxfs_node	*sf_parent;	/* parent sfnode of this one */
+	uint16_t		sf_children;	/* number of children sfnodes */
+	uint8_t			sf_type;	/* VDIR or VREG */
+	uint8_t			sf_vpstate;	/* XXX: ADD COMMENT */
+	uint8_t			sf_is_stale;	/* this is stale and should be purged */
+	sffs_stat_t		sf_stat;	/* cached file attrs for this node */
+	uint64_t		sf_stat_time;	/* last-modified time of sf_stat */
+	sffs_dirents_t		*sf_dir_list;	/* list of entries for this directory */
+
+	/* interlock to protect sf_vpstate */
+	struct mtx		sf_interlock;
+};
+
+struct vboxfs_mount_info {
+	char name[MAX_HOST_NAME];   /* share name */
+	char nls_name[MAX_NLS_NAME];/* name of an I/O charset */
+	int  uid;		    /* user ID for all entries, default 0=root */
+	int  gid;		    /* group ID for all entries, default 0=root */
+	int  ttl;		    /* time to live */
+	int  dmode;		    /* mode for directories if != 0xffffffff */
+	int  fmode;		    /* mode for regular files if != 0xffffffff */
+	int  dmask;		    /* umask applied to directories */
+	int  fmask;		    /* umask applied to regular files */
+};
+
 struct sf_glob_info {
-    VBGLSFMAP map;
-/*    struct nls_table *nls;*/
-    int ttl;
-    int uid;
-    int gid;
-    struct vnode *vnode_root;
+	VBGLSFMAP map;
+/*	struct nls_table *nls;*/
+	int ttl;
+	int uid;
+	int gid;
+	struct vnode *vnode_root;
 };
 
+/** Per-file system mount instance data. */
+typedef struct vboxfs_globinfo
+{
+	VBGLSFMAP			Map;
+	int			Ttl;
+	int			Uid;
+	int			Gid;
+	struct mount		*pVFS;
+	struct vboxfs_node	*pVNodeRoot;
+} vboxfs_globinfo_t;
+
 struct sf_inode_info {
-    SHFLSTRING *path;
-    int force_restat;
+	SHFLSTRING *path;
+	int force_restat;
 };
 
 #if 0
 struct sf_dir_info {
-    struct list_head info_list;
+	struct list_head info_list;
 };
 #endif
 
 struct sf_dir_buf {
-    size_t nb_entries;
-    size_t free_bytes;
-    size_t used_bytes;
-    void *buf;
+	size_t nb_entries;
+	size_t free_bytes;
+	size_t used_bytes;
+	void *buf;
 #if 0
-   struct list_head head;
+	struct list_head head;
 #endif
 };
 
 struct sf_reg_info {
-    SHFLHANDLE handle;
+	SHFLHANDLE handle;
 };
 
+int vboxfs_alloc_vp(struct mount *, struct vboxfs_node *, int,
+    struct vnode **);
+void vboxfs_free_vp(struct vnode *);
+
+int vboxfs_alloc_node(struct mount *, struct vboxfs_mnt *, const char*,
+    enum vtype, uid_t, gid_t, mode_t, struct vboxfs_node *,
+    struct vboxfs_node **);
+void vboxfs_free_node(struct vboxfs_mnt *, struct vboxfs_node *);
+
+/*
+ * These are the provider interfaces used by sffs to access the underlying
+ * shared file system.
+ */
+#define SFPROV_VERSION  1
+
+/*
+ * Initialization and termination.
+ * sfprov_connect() is called once before any other interfaces and returns
+ * a handle used in further calls. The argument should be SFPROV_VERSION
+ * from above. On failure it returns a NULL pointer.
+ *
+ * sfprov_disconnect() must only be called after all sf file systems have been
+ * unmounted.
+ */
+typedef struct sfp_connection sfp_connection_t;
+
+extern sfp_connection_t *sfprov_connect(int);
+extern void sfprov_disconnect(void);
+
+extern int sfprov_mount(char *, sfp_mount_t **);
+extern int sfprov_unmount(sfp_mount_t *);
+
+/*
+ * query information about a mounted file system
+ */
+typedef struct sffs_fsinfo {
+	uint64_t blksize;
+	uint64_t blksused;
+	uint64_t blksavail;
+	uint32_t maxnamesize;
+	uint32_t readonly;
+	uint32_t serial;
+} sffs_fsinfo_t;
+
+extern int sfprov_get_fsinfo(sfp_mount_t *, sffs_fsinfo_t *);
+
+extern int sfprov_create(sfp_mount_t *, char *path, mode_t mode,
+    sfp_file_t **fp, sffs_stat_t *stat);
+extern int sfprov_open(sfp_mount_t *, char *path, sfp_file_t **fp);
+extern int sfprov_close(sfp_file_t *fp);
+extern int sfprov_read(sfp_file_t *, char * buffer, uint64_t offset,
+    uint32_t *numbytes, int buflocked);
+extern int sfprov_write(sfp_file_t *, char * buffer, uint64_t offset,
+    uint32_t *numbytes, int buflocked);
+extern int sfprov_fsync(sfp_file_t *fp);
+
+
+/*
+ * get/set information about a file (or directory) using pathname
+ */
+extern int sfprov_get_mode(sfp_mount_t *, char *, mode_t *);
+extern int sfprov_get_size(sfp_mount_t *, char *, uint64_t *);
+extern int sfprov_get_atime(sfp_mount_t *, char *, struct timespec *);
+extern int sfprov_get_mtime(sfp_mount_t *, char *, struct timespec *);
+extern int sfprov_get_ctime(sfp_mount_t *, char *, struct timespec *);
+extern int sfprov_get_attr(sfp_mount_t *, char *, sffs_stat_t *);
+extern int sfprov_set_attr(sfp_mount_t *, char *, mode_t,
+   struct timespec, struct timespec, struct timespec);
+extern int sfprov_set_size(sfp_mount_t *, char *, uint64_t);
+
+
+/*
+ * File/Directory operations
+ */
+extern int sfprov_trunc(sfp_mount_t *, char *);
+extern int sfprov_remove(sfp_mount_t *, char *path, u_int is_link);
+extern int sfprov_mkdir(sfp_mount_t *, char *path, mode_t mode,
+    sfp_file_t **fp, sffs_stat_t *stat);
+extern int sfprov_rmdir(sfp_mount_t *, char *path);
+extern int sfprov_rename(sfp_mount_t *, char *from, char *to, u_int is_dir);
+
+
+/*
+ * Symbolic link operations
+ */
+extern int sfprov_set_show_symlinks(void);
+extern int sfprov_readlink(sfp_mount_t *, char *path, char *target,
+    size_t tgt_size);
+extern int sfprov_symlink(sfp_mount_t *, char *linkname, char *target,
+    sffs_stat_t *stat);
+
+#define SFFS_DIRENTS_SIZE	8192
+#define SFFS_DIRENTS_OFF	(offsetof(sffs_dirents_t, sf_entries[0]))
+
+extern int sfprov_readdir(sfp_mount_t *mnt, char *path,
+    sffs_dirents_t **dirents);
+
 #endif  /* KERNEL */
 
 #endif /* !___VBOXVFS_H___ */
-

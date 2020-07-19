--- src/VBox/Additions/freebsd/vboxvfs/vboxvfs_prov.c.orig	2020-06-26 09:59:35 UTC
+++ src/VBox/Additions/freebsd/vboxvfs/vboxvfs_prov.c
@@ -0,0 +1,1020 @@
+/*
+ * Copyright (C) 2008-2016 Oracle Corporation
+ *
+ * This file is part of VirtualBox Open Source Edition (OSE), as
+ * available from http://www.virtualbox.org. This file is free software;
+ * you can redistribute it and/or modify it under the terms of the GNU
+ * General Public License (GPL) as published by the Free Software
+ * Foundation, in version 2 as it comes in the "COPYING" file of the
+ * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+ * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+ *
+ * The contents of this file may alternatively be used under the terms
+ * of the Common Development and Distribution License Version 1.0
+ * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
+ * VirtualBox OSE distribution, in which case the provisions of the
+ * CDDL are applicable instead of those of the GPL.
+ *
+ * You may elect to license modified versions of this file under the
+ * terms and conditions of either the GPL or the CDDL or both.
+ */
+
+/*
+ * Provider interfaces for shared folder file system.
+ */
+
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/param.h>
+#include <sys/systm.h>
+#include <sys/kernel.h>
+#include <sys/malloc.h>
+#include <sys/mount.h>
+#include <sys/vnode.h>
+#include <sys/dirent.h>
+#include <sys/proc.h>
+#include <vm/vm.h>
+#include <vm/pmap.h>
+#include <vm/vm_kern.h>
+#include <vm/vm_map.h>
+#include <vm/vm_object.h>
+#include <vm/vm_extern.h>
+#include "vboxvfs.h"
+
+#define DIRENT_RECLEN(namelen)    \
+	((offsetof(struct dirent, d_name[0]) + 1 + (namelen) + 7) & ~ 7)
+#define DIRENT_NAMELEN(reclen)    \
+	((reclen) - (offsetof(struct dirent, d_name[0])))
+
+static VBGLSFCLIENT vbox_client;
+
+extern u_int vboxvfs_debug;
+
+static int
+sfprov_vbox2errno(int rc)
+{
+	if (rc == VERR_ACCESS_DENIED)
+		return (EACCES);
+	if (rc == VERR_INVALID_NAME)
+		return (ENOENT);
+	return (RTErrConvertToErrno(rc));
+}
+
+/*
+ * utility to create strings
+ */
+static SHFLSTRING *
+sfprov_string(char *path, int *sz)
+{
+	SHFLSTRING *str;
+	int len = strlen(path);
+
+	*sz = len + 1 + sizeof (*str) - sizeof (str->String);
+	str = malloc(*sz, M_VBOXVFS, M_WAITOK | M_ZERO);
+	str->u16Size = len + 1;
+	str->u16Length = len;
+	strcpy(str->String.utf8, path);
+	return (str);
+}
+
+sfp_connection_t *
+sfprov_connect(int version)
+{
+	/* only one version for now, so must match */
+	int error = -1;
+
+	if (version != SFPROV_VERSION) {
+		printf("%s: version mismatch (%d, expected %d)\n", __func__,
+		    version, SFPROV_VERSION);
+		return (NULL);
+	}
+
+	if (RT_FAILURE(VbglR0SfInit()))
+		return (NULL);
+
+	if (RT_FAILURE(VbglR0SfConnect(&vbox_client))) {
+		VbglR0SfTerm();
+		return (NULL);
+	}
+
+	if (RT_FAILURE(VbglR0SfSetUtf8(&vbox_client))) {
+		VbglR0SfDisconnect(&vbox_client);
+		VbglR0SfTerm();
+		return (NULL);
+	}
+	return ((sfp_connection_t *)&vbox_client);
+}
+
+void
+sfprov_disconnect()
+{
+	VbglR0SfDisconnect(&vbox_client);
+	VbglR0SfTerm();
+}
+
+int
+sfprov_mount(char *path, sfp_mount_t **mnt)
+{
+	sfp_mount_t *m;
+	SHFLSTRING *str;
+	int size;
+	int rc;
+
+	VBOXVFS_DEBUG(1, "%s: Enter", __FUNCTION__);
+	VBOXVFS_DEBUG(1, "%s: path: [%s]", __FUNCTION__, path);
+
+	m = malloc(sizeof (*m),  M_VBOXVFS, M_WAITOK | M_ZERO);
+	str = sfprov_string(path, &size);
+
+	int error;
+	rc = VbglR0SfMapFolder(&vbox_client, str, &m->map);
+	if (RT_FAILURE(rc)) {
+		free(m, M_VBOXVFS);
+		*mnt = NULL;
+		error = sfprov_vbox2errno(rc);
+	} else {
+		*mnt = m;
+		error = 0;
+	}
+	free(str, M_VBOXVFS);
+	printf("%s(%s): error=%d rc=%d\n", __func__, path, error, rc);
+	return (error);
+}
+
+int
+sfprov_unmount(sfp_mount_t *mnt)
+{
+	int rc;
+
+	rc = VbglR0SfUnmapFolder(&vbox_client, &mnt->map);
+	if (RT_FAILURE(rc)) {
+		printf("sfprov_unmount: VbglR0SfUnmapFolder() failed rc=%d\n", rc);
+		rc = sfprov_vbox2errno(rc);
+	} else {
+		rc = 0;
+	}
+
+	free(mnt, M_VBOXVFS);
+	return (rc);
+}
+
+/*
+ * query information about a mounted file system
+ */
+int
+sfprov_get_fsinfo(sfp_mount_t *mnt, sffs_fsinfo_t *fsinfo)
+{
+	int rc;
+	SHFLVOLINFO info;
+	uint32_t bytes = sizeof(SHFLVOLINFO);
+	size_t bytesused;
+
+	rc = VbglR0SfFsInfo(&vbox_client, &mnt->map, 0,
+	    (SHFL_INFO_GET | SHFL_INFO_VOLUME), &bytes, (SHFLDIRINFO *)&info);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+
+	fsinfo->blksize = info.ulBytesPerAllocationUnit;
+	bytesused =
+	    info.ullTotalAllocationBytes - info.ullAvailableAllocationBytes;
+	fsinfo->blksused = bytesused / info.ulBytesPerAllocationUnit;
+	fsinfo->blksavail = info.ullAvailableAllocationBytes /
+	    info.ulBytesPerAllocationUnit;
+	fsinfo->maxnamesize = info.fsProperties.cbMaxComponent;
+	fsinfo->readonly = info.fsProperties.fReadOnly;
+	fsinfo->serial = info.ulSerial;
+	return (0);
+}
+
+/*
+ * file/directory information conversions.
+ */
+static void
+sfprov_fmode_from_mode(RTFMODE *fMode, mode_t mode)
+{
+	RTFMODE m = 0;
+
+#define mode_set(r) ((mode & (S_##r)) ? RTFS_UNIX_##r : 0)
+	m  = mode_set (ISUID);
+	m |= mode_set (ISGID);
+	m |= (mode & S_ISVTX) ? RTFS_UNIX_ISTXT : 0;
+	m |= mode_set (IRUSR);
+	m |= mode_set (IWUSR);
+	m |= mode_set (IXUSR);
+	m |= mode_set (IRGRP);
+	m |= mode_set (IWGRP);
+	m |= mode_set (IXGRP);
+	m |= mode_set (IROTH);
+	m |= mode_set (IWOTH);
+	m |= mode_set (IXOTH);
+
+	if (S_ISDIR(mode))
+		m |= RTFS_TYPE_DIRECTORY;
+	else if (S_ISREG(mode))
+		m |= RTFS_TYPE_FILE;
+	else if (S_ISFIFO(mode))
+		m |= RTFS_TYPE_FIFO;
+	else if (S_ISCHR(mode))
+		m |= RTFS_TYPE_DEV_CHAR;
+	else if (S_ISBLK(mode))
+		m |= RTFS_TYPE_DEV_BLOCK;
+	else if (S_ISLNK(mode))
+		m |= RTFS_TYPE_SYMLINK;
+	else if (S_ISSOCK(mode))
+		m |= RTFS_TYPE_SOCKET;
+	else
+		m |= RTFS_TYPE_FILE;
+
+	*fMode = m;
+}
+
+static void
+sfprov_mode_from_fmode(mode_t *mode, RTFMODE fMode)
+{
+	mode_t m = 0;
+
+	if (RTFS_IS_DIRECTORY(fMode))
+		m |= S_IFDIR;
+	else if (RTFS_IS_FILE(fMode))
+		m |= S_IFREG;
+	else if (RTFS_IS_FIFO(fMode))
+		m |= S_IFIFO;
+	else if (RTFS_IS_DEV_CHAR(fMode))
+		m |= S_IFCHR;
+	else if (RTFS_IS_DEV_BLOCK(fMode))
+		m |= S_IFBLK;
+	else if (RTFS_IS_SYMLINK(fMode))
+		m |= S_IFLNK;
+	else if (RTFS_IS_SOCKET(fMode))
+		m |= S_IFSOCK;
+
+	if (fMode & RTFS_UNIX_IRUSR)
+		m |= S_IRUSR;
+	if (fMode & RTFS_UNIX_IWUSR)
+		m |= S_IWUSR;
+	if (fMode & RTFS_UNIX_IXUSR)
+		m |= S_IXUSR;
+	if (fMode & RTFS_UNIX_IRGRP)
+		m |= S_IRGRP;
+	if (fMode & RTFS_UNIX_IWGRP)
+		m |= S_IWGRP;
+	if (fMode & RTFS_UNIX_IXGRP)
+		m |= S_IXGRP;
+	if (fMode & RTFS_UNIX_IROTH)
+		m |= S_IROTH;
+	if (fMode & RTFS_UNIX_IWOTH)
+		m |= S_IWOTH;
+	if (fMode & RTFS_UNIX_IXOTH)
+		m |= S_IXOTH;
+	if (fMode & RTFS_UNIX_ISUID)
+		m |= S_ISUID;
+	if (fMode & RTFS_UNIX_ISGID)
+		m |= S_ISGID;
+	if (fMode & RTFS_UNIX_ISTXT)
+		m |= S_ISVTX;
+	*mode = m;
+}
+
+static void
+sfprov_ftime_from_timespec(struct timespec *time, RTTIMESPEC *ts)
+{
+	uint64_t nanosec = RTTimeSpecGetNano(ts);
+	time->tv_sec = nanosec / UINT64_C(1000000000);
+	time->tv_nsec = nanosec % UINT64_C(1000000000);
+}
+
+static void
+sfprov_stat_from_info(sffs_stat_t *stat, SHFLFSOBJINFO *info)
+{
+	sfprov_mode_from_fmode(&stat->sf_mode, info->Attr.fMode);
+	stat->sf_size  = info->cbObject;
+	stat->sf_alloc = info->cbAllocated;
+	sfprov_ftime_from_timespec(&stat->sf_atime, &info->AccessTime);
+	sfprov_ftime_from_timespec(&stat->sf_mtime, &info->ModificationTime);
+	sfprov_ftime_from_timespec(&stat->sf_ctime, &info->ChangeTime);
+}
+
+/*
+ * File operations: open/close/read/write/etc.
+ *
+ * open/create can return any relevant errno, however ENOENT
+ * generally means that the host file didn't exist.
+ */
+int
+sfprov_create(
+	sfp_mount_t *mnt,
+	char *path,
+	mode_t mode,
+	sfp_file_t **fp,
+	sffs_stat_t *stat)
+{
+	int rc;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	int size;
+	sfp_file_t *newfp;
+
+	str = sfprov_string(path, &size);
+	parms.Handle = SHFL_HANDLE_NIL;
+	parms.Info.cbObject = 0;
+	sfprov_fmode_from_mode(&parms.Info.Attr.fMode, mode);
+	parms.CreateFlags = SHFL_CF_ACT_CREATE_IF_NEW |
+	    SHFL_CF_ACT_REPLACE_IF_EXISTS | SHFL_CF_ACCESS_READWRITE;
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+	free(str, M_VBOXVFS);
+
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	if (parms.Handle == SHFL_HANDLE_NIL) {
+		if (parms.Result == SHFL_FILE_EXISTS)
+			return (EEXIST);
+		return (ENOENT);
+	}
+	newfp = malloc(sizeof(sfp_file_t), M_VBOXVFS, M_WAITOK | M_ZERO);
+	newfp->handle = parms.Handle;
+	newfp->map = mnt->map;
+	*fp = newfp;
+	sfprov_stat_from_info(stat, &parms.Info);
+	return (0);
+}
+
+int
+sfprov_open(sfp_mount_t *mnt, char *path, sfp_file_t **fp)
+{
+	int rc;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	int size;
+	sfp_file_t *newfp;
+
+	/*
+	 * First we attempt to open it read/write. If that fails we
+	 * try read only.
+	 */
+	bzero(&parms, sizeof(parms));
+	str = sfprov_string(path, &size);
+	parms.Handle = SHFL_HANDLE_NIL;
+	parms.Info.cbObject = 0;
+	parms.CreateFlags = SHFL_CF_ACT_FAIL_IF_NEW | SHFL_CF_ACCESS_READWRITE;
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+	if (RT_FAILURE(rc) && rc != VERR_ACCESS_DENIED) {
+		free(str, M_VBOXVFS);
+		return (sfprov_vbox2errno(rc));
+	}
+	if (parms.Handle == SHFL_HANDLE_NIL) {
+		if (parms.Result == SHFL_PATH_NOT_FOUND ||
+		    parms.Result == SHFL_FILE_NOT_FOUND) {
+			free(str, M_VBOXVFS);
+			return (ENOENT);
+		}
+		parms.CreateFlags =
+		    SHFL_CF_ACT_FAIL_IF_NEW | SHFL_CF_ACCESS_READ;
+		rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+		if (RT_FAILURE(rc)) {
+			free(str, M_VBOXVFS);
+			return (sfprov_vbox2errno(rc));
+		}
+		if (parms.Handle == SHFL_HANDLE_NIL) {
+			free(str, M_VBOXVFS);
+			return (ENOENT);
+		}
+	}
+	else
+		free(str, M_VBOXVFS);
+	newfp = malloc(sizeof(sfp_file_t), M_VBOXVFS, M_WAITOK | M_ZERO);
+	newfp->handle = parms.Handle;
+	newfp->map = mnt->map;
+	*fp = newfp;
+	return (0);
+}
+
+int
+sfprov_trunc(sfp_mount_t *mnt, char *path)
+{
+	int rc;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	int size;
+
+	/*
+	 * open it read/write.
+	 */
+	str = sfprov_string(path, &size);
+	parms.Handle = 0;
+	parms.Info.cbObject = 0;
+	parms.CreateFlags = SHFL_CF_ACT_FAIL_IF_NEW | SHFL_CF_ACCESS_READWRITE |
+	    SHFL_CF_ACT_OVERWRITE_IF_EXISTS;
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+	free(str, M_VBOXVFS);
+
+	if (RT_FAILURE(rc)) {
+		return (sfprov_vbox2errno(rc));
+	}
+	(void)VbglR0SfClose(&vbox_client, &mnt->map, parms.Handle);
+	return (0);
+}
+
+int
+sfprov_close(sfp_file_t *fp)
+{
+	int rc;
+
+	rc = VbglR0SfClose(&vbox_client, &fp->map, fp->handle);
+	free(fp, M_VBOXVFS);
+	return (0);
+}
+
+int
+sfprov_read(sfp_file_t *fp, char *buffer, uint64_t offset, uint32_t *numbytes,
+    int buflocked)
+{
+	int rc;
+
+	rc = VbglR0SfRead(&vbox_client, &fp->map, fp->handle, offset,
+	    numbytes, (uint8_t *)buffer, buflocked);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	return (0);
+}
+
+int
+sfprov_write(sfp_file_t *fp, char *buffer, uint64_t offset, uint32_t *numbytes,
+    int buflocked)
+{
+	int rc;
+
+	rc = VbglR0SfWrite(&vbox_client, &fp->map, fp->handle, offset,
+	    numbytes, (uint8_t *)buffer, buflocked);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	return (0);
+}
+
+int
+sfprov_fsync(sfp_file_t *fp)
+{
+	int rc;
+
+	rc = VbglR0SfFlush(&vbox_client, &fp->map, fp->handle);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	return (0);
+}
+
+
+static int
+sfprov_getinfo(sfp_mount_t *mnt, char *path, PSHFLFSOBJINFO info)
+{
+	int rc;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	int size;
+
+	str = sfprov_string(path, &size);
+	parms.Handle = 0;
+	parms.Info.cbObject = 0;
+	parms.CreateFlags = SHFL_CF_LOOKUP | SHFL_CF_ACT_FAIL_IF_NEW;
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+	free(str, M_VBOXVFS);
+
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	if (parms.Result != SHFL_FILE_EXISTS)
+		return (ENOENT);
+	*info = parms.Info;
+	return (0);
+}
+
+/*
+ * get information about a file (or directory)
+ */
+int
+sfprov_get_mode(sfp_mount_t *mnt, char *path, mode_t *mode)
+{
+	int rc;
+	SHFLFSOBJINFO info;
+
+	rc = sfprov_getinfo(mnt, path, &info);
+	if (rc)
+		return (rc);
+	sfprov_mode_from_fmode(mode, info.Attr.fMode);
+	return (0);
+}
+
+int
+sfprov_get_size(sfp_mount_t *mnt, char *path, uint64_t *size)
+{
+	int rc;
+	SHFLFSOBJINFO info;
+
+	rc = sfprov_getinfo(mnt, path, &info);
+	if (rc)
+		return (rc);
+	*size = info.cbObject;
+	return (0);
+}
+
+
+int
+sfprov_get_atime(sfp_mount_t *mnt, char *path, struct timespec *time)
+{
+	int rc;
+	SHFLFSOBJINFO info;
+
+	rc = sfprov_getinfo(mnt, path, &info);
+	if (rc)
+		return (rc);
+	sfprov_ftime_from_timespec(time, &info.AccessTime);
+	return (0);
+}
+
+int
+sfprov_get_mtime(sfp_mount_t *mnt, char *path, struct timespec *time)
+{
+	int rc;
+	SHFLFSOBJINFO info;
+
+	rc = sfprov_getinfo(mnt, path, &info);
+	if (rc)
+		return (rc);
+	sfprov_ftime_from_timespec(time, &info.ModificationTime);
+	return (0);
+}
+
+int
+sfprov_get_ctime(sfp_mount_t *mnt, char *path, struct timespec *time)
+{
+	int rc;
+	SHFLFSOBJINFO info;
+
+	rc = sfprov_getinfo(mnt, path, &info);
+	if (rc)
+		return (rc);
+	sfprov_ftime_from_timespec(time, &info.ChangeTime);
+	return (0);
+}
+
+int
+sfprov_get_attr(sfp_mount_t *mnt, char *path, sffs_stat_t *attr)
+{
+	int rc;
+	SHFLFSOBJINFO info;
+
+	rc = sfprov_getinfo(mnt, path, &info);
+	if (rc)
+		return (rc);
+	sfprov_stat_from_info(attr, &info);
+	return (0);
+}
+
+static void
+sfprov_timespec_from_ftime(RTTIMESPEC *ts, struct timespec time)
+{
+	uint64_t nanosec = UINT64_C(1000000000) * time.tv_sec + time.tv_nsec;
+	RTTimeSpecSetNano(ts, nanosec);
+}
+
+int
+sfprov_set_attr(
+	sfp_mount_t *mnt,
+	char *path,
+	mode_t mode,
+	struct timespec atime,
+	struct timespec mtime,
+	struct timespec ctime)
+{
+	int rc, err;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	SHFLFSOBJINFO info;
+	uint32_t bytes;
+	int str_size;
+
+	str = sfprov_string(path, &str_size);
+	parms.Handle = 0;
+	parms.Info.cbObject = 0;
+	parms.CreateFlags = SHFL_CF_ACT_OPEN_IF_EXISTS
+			  | SHFL_CF_ACT_FAIL_IF_NEW
+			  | SHFL_CF_ACCESS_ATTR_WRITE;
+
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+
+	if (RT_FAILURE(rc)) {
+		printf("sfprov_set_attr: VbglR0SfCreate(%s) failed rc=%d\n",
+		    path, rc);
+		err = sfprov_vbox2errno(rc);
+		goto fail2;
+	}
+	if (parms.Result != SHFL_FILE_EXISTS) {
+		err = ENOENT;
+		goto fail1;
+	}
+
+	RT_ZERO(info);
+#if 0
+	if (mask & AT_MODE)
+		sfprov_fmode_from_mode(&info.Attr.fMode, mode);
+	if (mask & AT_ATIME)
+		sfprov_timespec_from_ftime(&info.AccessTime, atime);
+	if (mask & AT_MTIME)
+		sfprov_timespec_from_ftime(&info.ModificationTime, mtime);
+	if (mask & AT_CTIME)
+		sfprov_timespec_from_ftime(&info.ChangeTime, ctime);
+#endif
+	bytes = sizeof(info);
+	rc = VbglR0SfFsInfo(&vbox_client, &mnt->map, parms.Handle,
+	    (SHFL_INFO_SET | SHFL_INFO_FILE), &bytes, (SHFLDIRINFO *)&info);
+	if (RT_FAILURE(rc)) {
+		if (rc != VERR_ACCESS_DENIED && rc != VERR_WRITE_PROTECT)
+		{
+			printf("sfprov_set_attr: VbglR0SfFsInfo(%s, FILE) failed rc=%d\n",
+		    path, rc);
+		}
+		err = sfprov_vbox2errno(rc);
+		goto fail1;
+	}
+
+	err = 0;
+
+fail1:
+	rc = VbglR0SfClose(&vbox_client, &mnt->map, parms.Handle);
+	if (RT_FAILURE(rc)) {
+		printf("sfprov_set_attr: VbglR0SfClose(%s) failed rc=%d\n",
+		    path, rc);
+	}
+fail2:
+	free(str, M_VBOXVFS);
+	return err;
+}
+
+int
+sfprov_set_size(sfp_mount_t *mnt, char *path, uint64_t size)
+{
+	int rc, err;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	SHFLFSOBJINFO info;
+	uint32_t bytes;
+	int str_size;
+
+	str = sfprov_string(path, &str_size);
+	parms.Handle = 0;
+	parms.Info.cbObject = 0;
+	parms.CreateFlags = SHFL_CF_ACT_OPEN_IF_EXISTS
+			  | SHFL_CF_ACT_FAIL_IF_NEW
+			  | SHFL_CF_ACCESS_WRITE;
+
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+
+	if (RT_FAILURE(rc)) {
+		printf("sfprov_set_size: VbglR0SfCreate(%s) failed rc=%d\n",
+		    path, rc);
+		err = sfprov_vbox2errno(rc);
+		goto fail2;
+	}
+	if (parms.Result != SHFL_FILE_EXISTS) {
+		err = ENOENT;
+		goto fail1;
+	}
+
+	RT_ZERO(info);
+	info.cbObject = size;
+	bytes = sizeof(info);
+	rc = VbglR0SfFsInfo(&vbox_client, &mnt->map, parms.Handle,
+	    (SHFL_INFO_SET | SHFL_INFO_SIZE), &bytes, (SHFLDIRINFO *)&info);
+	if (RT_FAILURE(rc)) {
+		printf("sfprov_set_size: VbglR0SfFsInfo(%s, SIZE) failed rc=%d\n",
+		    path, rc);
+		err = sfprov_vbox2errno(rc);
+		goto fail1;
+	}
+
+	err = 0;
+
+fail1:
+	rc = VbglR0SfClose(&vbox_client, &mnt->map, parms.Handle);
+	if (RT_FAILURE(rc)) {
+		printf("sfprov_set_size: VbglR0SfClose(%s) failed rc=%d\n",
+		    path, rc);
+	}
+fail2:
+	free(str, M_VBOXVFS);
+	return err;
+}
+
+/*
+ * Directory operations
+ */
+int
+sfprov_mkdir(
+	sfp_mount_t *mnt,
+	char *path,
+	mode_t mode,
+	sfp_file_t **fp,
+	sffs_stat_t *stat)
+{
+	int rc;
+	SHFLCREATEPARMS parms;
+	SHFLSTRING *str;
+	int size;
+	sfp_file_t *newfp;
+
+	str = sfprov_string(path, &size);
+	parms.Handle = SHFL_HANDLE_NIL;
+	parms.Info.cbObject = 0;
+	sfprov_fmode_from_mode(&parms.Info.Attr.fMode, mode);
+	parms.CreateFlags = SHFL_CF_DIRECTORY | SHFL_CF_ACT_CREATE_IF_NEW |
+	    SHFL_CF_ACT_FAIL_IF_EXISTS | SHFL_CF_ACCESS_READ;
+	rc = VbglR0SfCreate(&vbox_client, &mnt->map, str, &parms);
+	free(str, M_VBOXVFS);
+
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	if (parms.Handle == SHFL_HANDLE_NIL) {
+		if (parms.Result == SHFL_FILE_EXISTS)
+			return (EEXIST);
+		return (ENOENT);
+	}
+	newfp = malloc(sizeof(sfp_file_t), M_VBOXVFS, M_WAITOK | M_ZERO);
+	newfp->handle = parms.Handle;
+	newfp->map = mnt->map;
+	*fp = newfp;
+	sfprov_stat_from_info(stat, &parms.Info);
+	return (0);
+}
+
+int
+sfprov_set_show_symlinks(void)
+{
+	int rc;
+
+	rc = VbglR0SfSetSymlinks(&vbox_client);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+
+	return (0);
+}
+
+int
+sfprov_remove(sfp_mount_t *mnt, char *path, u_int is_link)
+{
+	int rc;
+	SHFLSTRING *str;
+	int size;
+
+	str = sfprov_string(path, &size);
+	rc = VbglR0SfRemove(&vbox_client, &mnt->map, str,
+		SHFL_REMOVE_FILE | (is_link ? SHFL_REMOVE_SYMLINK : 0));
+	free(str, M_VBOXVFS);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	return (0);
+}
+
+int
+sfprov_readlink(
+	sfp_mount_t *mnt,
+	char *path,
+	char *target,
+	size_t tgt_size)
+{
+	int rc;
+	SHFLSTRING *str;
+	int size;
+
+	str = sfprov_string(path, &size);
+
+	rc = VbglR0SfReadLink(&vbox_client, &mnt->map, str, (uint32_t) tgt_size,
+	    target);
+	if (RT_FAILURE(rc))
+		rc = sfprov_vbox2errno(rc);
+
+	free(str, M_VBOXVFS);
+	return (rc);
+}
+
+int
+sfprov_symlink(
+	sfp_mount_t *mnt,
+	char *linkname,
+	char *target,
+	sffs_stat_t *stat)
+{
+	int rc;
+	SHFLSTRING *lnk, *tgt;
+	int lnk_size, tgt_size;
+	SHFLFSOBJINFO info;
+
+	lnk = sfprov_string(linkname, &lnk_size);
+	tgt = sfprov_string(target, &tgt_size);
+
+	rc = VbglR0SfSymlink(&vbox_client, &mnt->map, lnk, tgt, &info);
+	if (RT_FAILURE(rc)) {
+		rc = sfprov_vbox2errno(rc);
+		goto done;
+	}
+
+	if (stat != NULL)
+		sfprov_stat_from_info(stat, &info);
+
+done:
+	free(lnk, M_VBOXVFS);
+	free(tgt, M_VBOXVFS);
+
+	return (rc);
+}
+
+int
+sfprov_rmdir(sfp_mount_t *mnt, char *path)
+{
+	int rc;
+	SHFLSTRING *str;
+	int size;
+
+	str = sfprov_string(path, &size);
+	rc = VbglR0SfRemove(&vbox_client, &mnt->map, str, SHFL_REMOVE_DIR);
+	free(str, M_VBOXVFS);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	return (0);
+}
+
+int
+sfprov_rename(sfp_mount_t *mnt, char *from, char *to, u_int is_dir)
+{
+	int rc;
+	SHFLSTRING *old, *new;
+	int old_size, new_size;
+
+	old = sfprov_string(from, &old_size);
+	new = sfprov_string(to, &new_size);
+	rc = VbglR0SfRename(&vbox_client, &mnt->map, old, new,
+	    (is_dir ? SHFL_RENAME_DIR : SHFL_RENAME_FILE) |
+	    SHFL_RENAME_REPLACE_IF_EXISTS);
+	free(old, M_VBOXVFS);
+	free(new, M_VBOXVFS);
+	if (RT_FAILURE(rc))
+		return (sfprov_vbox2errno(rc));
+	return (0);
+}
+
+/*
+ * Read all filenames in a directory.
+ *
+ * - success - all entries read and returned
+ * - ENOENT - Couldn't open the directory for reading
+ * - EINVAL - Internal error of some kind
+ *
+ * On successful return, *dirents points to a list of sffs_dirents_t;
+ * for each dirent, all fields except the d_ino will be set appropriately.
+ * The caller is responsible for freeing the dirents buffer.
+ */
+int
+sfprov_readdir(
+	sfp_mount_t *mnt,
+	char *path,
+	sffs_dirents_t **dirents)
+{
+	int error;
+	char *cp;
+	int len;
+	SHFLSTRING *mask_str = NULL;	/* must be path with "/" appended */
+	int mask_size;
+	sfp_file_t *fp;
+	uint32_t infobuff_alloc = 16384;
+	SHFLDIRINFO *infobuff = NULL, *info;
+	uint32_t numbytes;
+	uint32_t nents;
+	uint32_t size;
+	off_t offset;
+	sffs_dirents_t *cur_buf;
+	struct sffs_dirent *dirent;
+	unsigned short reclen;
+	unsigned short entlen;
+
+	*dirents = NULL;
+
+	error = sfprov_open(mnt, path, &fp);
+	if (error != 0)
+		return (ENOENT);
+
+	/*
+	 * Allocate the first dirents buffers.
+	 */
+	*dirents = malloc(SFFS_DIRENTS_SIZE,  M_VBOXVFS, M_WAITOK | M_ZERO);
+	if (*dirents == NULL) {
+		error = (ENOSPC);
+		goto done;
+	}
+	cur_buf = *dirents;
+	cur_buf->sf_next = NULL;
+	cur_buf->sf_len = 0;
+
+	/*
+	 * Create mask that VBox expects. This needs to be the directory path,
+	 * plus a "*" wildcard to get all files.
+	 */
+	len = strlen(path) + 3;
+	cp = malloc(len, M_VBOXVFS, M_WAITOK | M_ZERO);
+	if (cp == NULL) {
+		error = (ENOSPC);
+		goto done;
+	}
+	strcpy(cp, path);
+	strcat(cp, "/*");
+	mask_str = sfprov_string(cp, &mask_size);
+	free(cp, M_VBOXVFS);
+
+	/*
+	 * Now loop using VbglR0SfDirInfo
+	 */
+	infobuff = malloc(infobuff_alloc, M_VBOXVFS, M_WAITOK | M_ZERO);
+	if (infobuff == NULL) {
+		error = (ENOSPC);
+		goto done;
+	}
+
+	offset = 0;
+	for (;;) {
+		numbytes = infobuff_alloc;
+		error = VbglR0SfDirInfo(&vbox_client, &fp->map, fp->handle,
+		    mask_str, 0, 0, &numbytes, infobuff, &nents);
+
+		switch (error) {
+		case VINF_SUCCESS:
+			/* fallthrough */
+		case VERR_NO_MORE_FILES:
+			break;
+		case VERR_NO_TRANSLATION:
+			/* XXX ??? */
+			break;
+		default:
+			error = sfprov_vbox2errno(error);
+			goto done;
+		}
+
+		/*
+		 * Create the dirent_t's and save the stats for each name
+		 */
+		for (info = infobuff; (char *) info < (char *) infobuff + numbytes; nents--) {
+			size_t buflen;
+
+			/* expand buffers if we need more space */
+			reclen = DIRENT_RECLEN(strlen(info->name.String.utf8));
+			entlen = sizeof(struct sffs_dirent) + reclen;
+			buflen = SFFS_DIRENTS_OFF + cur_buf->sf_len + entlen;
+			if (buflen > SFFS_DIRENTS_SIZE) {
+				cur_buf->sf_next = malloc(SFFS_DIRENTS_SIZE,
+				    M_VBOXVFS, M_WAITOK | M_ZERO);
+				if (cur_buf->sf_next == NULL) {
+					error = ENOSPC;
+					goto done;
+				}
+				cur_buf = cur_buf->sf_next;
+				cur_buf->sf_next = NULL;
+				cur_buf->sf_len = 0;
+			}
+
+			/* create the dirent with the name, offset, and len */
+			dirent = (struct sffs_dirent *)
+			    (((char *) &cur_buf->sf_entries[0]) + cur_buf->sf_len);
+			strncpy(&dirent->sf_entry.d_name[0],
+			    info->name.String.utf8, DIRENT_NAMELEN(reclen));
+			dirent->sf_entry.d_reclen = reclen;
+			dirent->sf_entry.d_namlen = strlen(info->name.String.utf8);
+			dirent->sf_entry.d_name[dirent->sf_entry.d_namlen] = 0;
+			offset += entlen;
+			dirent->sf_off = offset;
+
+			/* save the stats */
+			sfprov_stat_from_info(&dirent->sf_stat, &info->Info);
+
+			/* next info */
+			cur_buf->sf_len += entlen;
+			size = offsetof (SHFLDIRINFO, name.String) + info->name.u16Size;
+			info = (SHFLDIRINFO *) ((uintptr_t) info + size);
+		}
+		KASSERT(nents == 0, ("nents != 0"));
+		KASSERT((char *) info == (char *) infobuff + numbytes, "(char *) info != (char *) infobuff + numbytes");
+
+		if (error == VERR_NO_MORE_FILES)
+			break;
+	}
+	error = 0;
+
+done:
+	if (error != 0) {
+		while (*dirents) {
+			cur_buf = (*dirents)->sf_next;
+			free(*dirents, M_VBOXVFS);
+			*dirents = cur_buf;
+		}
+	}
+	if (infobuff != NULL)
+		free(infobuff, M_VBOXVFS);
+	if (mask_str != NULL)
+		free(mask_str, M_VBOXVFS);
+	sfprov_close(fp);
+
+	return (error);
+}

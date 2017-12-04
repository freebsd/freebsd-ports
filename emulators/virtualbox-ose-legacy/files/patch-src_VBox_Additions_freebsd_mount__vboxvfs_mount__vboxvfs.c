--- src/VBox/Additions/freebsd/mount_vboxvfs/mount_vboxvfs.c.orig	1970-01-01 01:00:00.000000000 +0100
+++ src/VBox/Additions/freebsd/mount_vboxvfs/mount_vboxvfs.c	2017-07-12 19:24:26.106029000 +0200
@@ -0,0 +1,168 @@
+/*
+* Copyright (c) 1992, 1993, 1994
+* The Regents of the University of California. All rights reserved.
+*
+* Redistribution and use in source and binary forms, with or without
+* modification, are permitted provided that the following conditions
+* are met:
+* 1. Redistributions of source code must retain the above copyright
+* notice, this list of conditions and the following disclaimer.
+* 2. Redistributions in binary form must reproduce the above copyright
+* notice, this list of conditions and the following disclaimer in the
+* documentation and/or other materials provided with the distribution.
+* 4. Neither the name of the University nor the names of its contributors
+* may be used to endorse or promote products derived from this software
+* without specific prior written permission.
+*
+* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+* ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+* SUCH DAMAGE.
+*/
+
+#include <sys/cdio.h>
+#include <sys/stat.h>
+#include <sys/file.h>
+#include <sys/iconv.h>
+#include <sys/param.h>
+#include <sys/linker.h>
+#include <sys/module.h>
+#include <sys/mount.h>
+#include <sys/uio.h>
+
+#include <err.h>
+#include <errno.h>
+#include <stdlib.h>
+#include <stdio.h>
+#include <string.h>
+#include <sysexits.h>
+#include <unistd.h>
+
+#include "mntopts.h"
+
+#define MAX_HOST_NAME  256
+static char mount_point[MAXPATHLEN + 1];
+static char vboxfs_vfsname[] = "vboxvfs";
+static struct mntopt mopts[] = {
+	MOPT_STDOPTS,
+	MOPT_END
+};
+
+static void usage(void) __dead2;
+
+static void 
+usage(void)
+{
+	fprintf(stderr,
+	    "Usage: [OPTIONS] NAME MOUNTPOINT\n"
+	    "Mount the VirtualBox shared folder NAME to MOUNTPOINT.\n"
+	    "\nOptions:\n"
+	    "  -w    mount the shared folder writable \n"
+	    "  -r    mount the shared folder read-only (the default)\n");
+	exit(1);
+}
+
+int
+main(int argc, char *argv[])
+{
+	struct iovec *iov;
+	struct stat st;
+	char *host_name;
+	char errmsg[255];
+	uid_t uid;
+	gid_t gid;
+	mode_t dir_mode, file_mode;
+	int iovlen;
+	int ronly = 0;
+	int error, ch;
+	int mntflags = 0;
+
+	iov = NULL;
+	iovlen = 0;
+	errmsg[0] = '\0';
+	uid = (uid_t)-1;
+	gid = (gid_t)-1;
+	file_mode = 0;
+	dir_mode = 0;
+
+	while ((ch = getopt(argc, argv, "rwo:h")) != -1)
+		switch(ch) {
+		default:
+			fprintf(stderr, "unknown option `%c:%#x'\n", ch, ch);
+			return (1);
+
+		case '?':
+		case 'h':
+			usage();
+		case 'r':
+			ronly = 1;
+			break;
+		case 'w':
+			ronly = 0;
+			break;
+		case 'o':
+			getmntopts(optarg, mopts, &mntflags, 0);
+			break;
+		}
+
+	if (argc - optind < 2)
+		usage();
+
+	host_name = argv[optind];
+	realpath(argv[optind+1], mount_point);
+
+	if (stat(mount_point, &st) == -1)
+		err(EX_OSERR, "could not find mount point %s", mount_point);
+
+	if (!S_ISDIR(st.st_mode)) {
+		errno = ENOTDIR;
+		err(EX_OSERR, "can't mount on %s", mount_point);
+	}
+
+	if (strlen(host_name) > MAX_HOST_NAME - 1)
+		err(EX_OSERR, "host name is too big %s", host_name);
+
+	if (ronly == 0)
+		mntflags |= MNT_ASYNC;
+	if (uid == (uid_t)-1)
+		uid = st.st_uid;
+	if (gid == (gid_t)-1)
+		gid = st.st_gid;
+	if (file_mode == 0)
+		file_mode = st.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
+	if (dir_mode == 0) {
+		dir_mode = file_mode;
+		if (dir_mode & S_IRUSR)
+			dir_mode |= S_IXUSR;
+		if (dir_mode & S_IRGRP)
+			dir_mode |= S_IXGRP;
+		if (dir_mode & S_IROTH)
+			dir_mode |= S_IXOTH;
+	}
+
+	build_iovec(&iov, &iovlen, "fstype", vboxfs_vfsname, (size_t)-1);
+	build_iovec(&iov, &iovlen, "fspath", mount_point, (size_t)-1);
+	build_iovec(&iov, &iovlen, "from", host_name, (size_t)-1);
+	build_iovec_argf(&iov, &iovlen, "uid", "%d", uid);
+	build_iovec_argf(&iov, &iovlen, "gid", "%d", gid);
+	build_iovec_argf(&iov, &iovlen, "file_mode", "%o", file_mode);
+	build_iovec_argf(&iov, &iovlen, "dir_mode", "%o", dir_mode);
+	build_iovec(&iov, &iovlen, "errmsg", errmsg, sizeof(errmsg));
+
+	error = nmount(iov, iovlen, mntflags);
+	if (error == -1) {
+		if (errmsg[0] != '\0')
+			err(1, "%s: error: %s", mount_point, errmsg);
+		else
+			err(1, "%s: error %d", mount_point, error);
+	}
+
+	return (0);
+}

--- src/mntent.h.orig	2025-10-12 11:00:40 UTC
+++ src/mntent.h
@@ -0,0 +1,189 @@
+/*
+ *  mntent
+ *  mntent.h - compatibility header for FreeBSD
+ *
+ *  Copyright (c) 2001 David Rufino <daverufino@btinternet.com>
+ *  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+#ifndef VIFM__UTILS__MNTENT_H__
+#define VIFM__UTILS__MNTENT_H__
+
+#include <stddef.h>
+#include <stdio.h>
+
+#define MOUNTED "dummy"
+
+#define MNTTYPE_NFS "nfs"
+
+struct mntent
+{
+	char *mnt_fsname;
+	char *mnt_dir;
+	char *mnt_type;
+	char *mnt_opts;
+	int mnt_freq;
+	int mnt_passno;
+};
+
+#define setmntent(x,y) ((FILE *)0x1)
+struct mntent * getmntent(FILE *fp);
+char * hasmntopt(const struct mntent *mnt, const char option[]);
+#define endmntent(x) ((int)1)
+
+#endif /* VIFM__UTILS__MNTENT_H__ */
+
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+
+#include <stdlib.h>
+#include <string.h>
+
+#ifdef __NetBSD__
+#define statfs statvfs
+#define f_flags f_flag
+#endif
+
+static struct mntent * statfs_to_mntent(struct statfs *mntbuf);
+static char * flags2opts(int flags);
+static char * catopt(char s0[], const char s1[]);
+
+char *
+hasmntopt(const struct mntent *mnt, const char option[])
+{
+	char *opt, *optbuf;
+
+	optbuf = strdup(mnt->mnt_opts);
+	for(opt = optbuf; (opt = strtok(opt, " ")) != NULL; opt = NULL)
+	{
+		if(!strcasecmp(opt, option))
+		{
+			opt = opt - optbuf + mnt->mnt_opts;
+			free(optbuf);
+			return (opt);
+		}
+	}
+	free(optbuf);
+	return NULL;
+}
+
+struct mntent *
+getmntent(FILE *fp)
+{
+	static int pos = -1;
+	static int mntsize = -1;
+
+	static struct statfs *mntbuf;
+
+	(void)fp;
+
+	if(pos == -1 || mntsize == -1)
+	{
+		mntsize = getmntinfo(&mntbuf, MNT_NOWAIT);
+	}
+
+	pos++;
+	if(pos == mntsize)
+	{
+		pos = mntsize = -1;
+		return NULL;
+	}
+
+	return statfs_to_mntent(&mntbuf[pos]);
+}
+
+static struct mntent *
+statfs_to_mntent(struct statfs *mntbuf)
+{
+	static struct mntent _mntent;
+	static char opts_buf[40], *tmp;
+
+	_mntent.mnt_fsname = mntbuf->f_mntfromname;
+	_mntent.mnt_dir = mntbuf->f_mntonname;
+	_mntent.mnt_type = mntbuf->f_fstypename;
+	tmp = flags2opts (mntbuf->f_flags);
+	if(tmp != NULL)
+	{
+		opts_buf[sizeof(opts_buf) - 1] = '\0';
+		strncpy(opts_buf, tmp, sizeof(opts_buf) - 1);
+		free(tmp);
+	}
+	else
+	{
+		*opts_buf = '\0';
+	}
+	_mntent.mnt_opts = opts_buf;
+	_mntent.mnt_freq = _mntent.mnt_passno = 0;
+	return &_mntent;
+}
+
+static char *
+flags2opts(int flags)
+{
+	char *res = catopt(NULL, (flags & MNT_RDONLY) ? "ro" : "rw");
+	if(flags & MNT_SYNCHRONOUS) res = catopt(res, "sync");
+	if(flags & MNT_NOEXEC)      res = catopt(res, "noexec");
+	if(flags & MNT_NOSUID)      res = catopt(res, "nosuid");
+#ifndef __OpenBSD__
+	if(flags & MNT_UNION)       res = catopt(res, "union");
+#endif
+	if(flags & MNT_ASYNC)       res = catopt(res, "async");
+	if(flags & MNT_NOATIME)     res = catopt(res, "noatime");
+#if !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+	if(flags & MNT_NOCLUSTERR)  res = catopt(res, "noclusterr");
+	if(flags & MNT_NOCLUSTERW)  res = catopt(res, "noclusterw");
+	if(flags & MNT_NOSYMFOLLOW) res = catopt(res, "nosymfollow");
+	if(flags & MNT_SUIDDIR)     res = catopt(res, "suiddir");
+#endif
+
+	return res;
+}
+
+static char *
+catopt(char s0[], const char s1[])
+{
+	char *cp;
+
+	if(s1 == NULL || *s1 == '\0')
+	{
+		return s0;
+	}
+	if(s0 && *s0)
+	{
+		const size_t i = strlen(s0) + strlen(s1) + 1 + 1;
+		if((cp = malloc(i)) == NULL)
+		{
+			return NULL;
+		}
+		(void)snprintf(cp, i, "%s %s", s0, s1);
+	}
+	else
+	{
+		cp = strdup(s1);
+	}
+
+	free(s0);
+	return cp;
+}

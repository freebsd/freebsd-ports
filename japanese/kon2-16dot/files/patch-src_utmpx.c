--- src/utmpx.c.orig	1970-01-01 09:00:00.000000000 +0900
+++ src/utmpx.c	2012-05-10 02:12:23.827551809 +0900
@@ -0,0 +1,156 @@
+/*
+ * KON2 - Kanji ON Console -
+ * Copyright (C) 1992-1996 Takashi MANABE (manabe@papilio.tutics.tut.ac.jp)
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
+ * THIS SOFTWARE IS PROVIDED BY TAKASHI MANABE ``AS IS'' AND ANY
+ * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ * 
+ */
+
+/*
+	Original utmp.c was ported from Wnn by komeda@ics.osaka-u.ac.jp.
+	This code is written by manabe@papilio.tutics.tut.ac.jp,
+	and this does not contain old code (Wnn's setutmp.c).
+
+	Thanks to komeda@ics.osaka-u.ac.jp.
+*/
+
+#include	<stdio.h>
+#include	<unistd.h>
+#include	<fcntl.h>
+#include	<string.h>
+#include	<pwd.h>
+#include	<utmpx.h>
+#include	<grp.h>
+#include	<sys/stat.h>
+#if defined(__FreeBSD__)
+#include	<ttyent.h>
+#endif
+
+#if !defined(__FreeBSD__)
+static int ttyGid;
+#else
+static gid_t ttyGid;
+static int ts;
+#endif
+static int unuse_utmp = 0;
+
+void	UnUseUtmp(int flg)
+{
+	unuse_utmp = flg;
+}
+
+void	SetUtmp(char *tty)
+{
+	struct utmpx	utmp;
+	struct utmpx	*utp;
+
+	struct passwd	*pw;
+	struct group	*ttygrp;
+	char	*tn;
+#if defined(__FreeBSD__)
+	struct ttyent	*ttyp;
+	int fd, i;
+#endif
+	if (unuse_utmp)
+		return;
+	pw = getpwuid(getuid());
+	tn = rindex(tty, '/') + 1;
+	memset((char *)&utmp, 0, sizeof(utmp));
+#if !defined(__FreeBSD__)
+	strncpy(utmp.ut_id, tn + 3, sizeof(utmp.ut_id));
+	utmp.ut_type = DEAD_PROCESS;
+	setutent();
+	getutid(&utmp);
+	utmp.ut_type = USER_PROCESS;
+	utmp.ut_pid = getpid();
+	strncpy(utmp.ut_line, tn, sizeof(utmp.ut_line));
+	strncpy(utmp.ut_user, pw->pw_name, sizeof(utmp.ut_user));
+	time(&(utmp.ut_time));
+	pututline(&utmp);
+	endutent();
+#else
+	setutxent();
+	strncpy(utmp.ut_id, tn + 3, sizeof(utmp.ut_id));
+	utmp.ut_type = DEAD_PROCESS;
+	utp = getutxent();
+	memcpy(&utmp, utp, sizeof(utmp));
+	utmp.ut_type = USER_PROCESS;
+	utmp.ut_pid = getpid();
+	strncpy(utmp.ut_line, tn, sizeof(utmp.ut_line));
+	strncpy(utmp.ut_user, pw->pw_name, sizeof(utmp.ut_user));
+	gettimeofday(&utmp.ut_tv, NULL);
+	pututxline(&utmp);
+	endutxent();
+#endif
+	if ((ttygrp = getgrnam("tty")) != NULL)
+		ttyGid = ttygrp->gr_gid;
+	else
+		ttyGid = -1;
+	chmod(tty, 0622);
+	chown(tty, getuid(), ttyGid);
+}
+
+void	ResetUtmp(char *tty)
+{
+#if !defined(__FreeBSD__)
+	struct utmp	utmp, *utp;
+	char	*tn;
+#else
+	struct utmpx	utmp;
+	struct utmpx	*utp;
+	char	*tn;
+	int fd;
+#endif
+	if (unuse_utmp)
+		return;
+
+#if !defined(__FreeBSD__)
+	tn = rindex(tty, '/') + 4;
+	memset((char *)&utmp, 0, sizeof(utmp));
+	strncpy(utmp.ut_id, tn, sizeof(utmp.ut_id));
+	utmp.ut_type = USER_PROCESS;
+	setutent();
+	utp = getutid(&utmp);
+	utp->ut_type = DEAD_PROCESS;
+	memset(utp->ut_user, 0, sizeof(utmp.ut_user));
+	utp->ut_type = DEAD_PROCESS;
+	time(&(utp->ut_time));
+	pututline(utp);
+	endutent();
+#else
+	tn = rindex(tty, '/') + 4;
+	memset((char *)&utmp, 0, sizeof(utmp));
+	strncpy(utmp.ut_id, tn, sizeof(utmp.ut_id));
+	utmp.ut_type = USER_PROCESS;
+	setutxent();
+	utp = getutxent();
+	memcpy(&utmp, utp, sizeof(utmp));
+	utmp.ut_type = DEAD_PROCESS;
+	memset(utmp.ut_user, 0, sizeof(utmp.ut_user));
+	utmp.ut_type = DEAD_PROCESS;
+	gettimeofday(&utmp.ut_tv, NULL);
+	pututxline(&utmp);
+	endutxent();
+#endif
+	chmod(tty, 0600);
+	chown(tty, 0, ttyGid);
+}

/*-
 * Copyright (c) 1999, Peter Wemm <peter@netplex.com.au>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

/*
 * A cheap hack to put a paper thick fence in front of /home/ncvs
 * and a replacement of the ncvs priviliged group.
 */

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <err.h>

#define ACCESS "/home/ncvs/CVSROOT/access"
#define REALCVS "/usr/bin/ncvs"

char linebuf[1024];

int
main(int ac, char **av)
{
	FILE *fp;
	uid_t uid;
	struct passwd *pw;
	char *p, *s;
	int karma;

	karma = 0;

#if 0
	/* not such a good idea if cvs is called from the commitlog scripts */
	if (getgid() == getegid())
		errx(1, "fatal: not installed setgid correctly!");
#endif
	umask(002);

	fp = fopen(ACCESS, "r");
	if (fp == NULL)
		err(1, "cannot open %s", ACCESS);

	uid = getuid();
	pw = getpwuid(uid);
	if (pw == NULL)
		err(1, "you don't exist! (getpwuid(3) failed)");

	while ((p = fgets(linebuf, sizeof(linebuf) - 1, fp)) != NULL) {
		while ((s = strsep(&p, " \t\n")) != NULL) {
			if (*s == '\0')
				continue;	/* whitespace */
			if (*s == '#' || *s == '/' || *s == ';')
				break;		/* comment */
			if (strcmp(s, pw->pw_name) == 0) {
				karma++;
				break;
			}
			break;	/* ignore further tokens on line for now */
		}
	}
	fclose(fp);

	if (karma > 0) {
		if (setgid(getegid()) < 0)
			err(1, "setgid(getegid()) failed!");
	} else {
		if (setgid(getgid()) < 0)
			err(1, "setgid(getgid()) failed!");
		/* tell cvs to not bother trying to create locks */
		putenv("CVSREADONLYFS=true");
	}

	execv(REALCVS, av);
	err(1, "cannot execv(%s)", REALCVS);
}

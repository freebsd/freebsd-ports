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
 * Actually, this is a hack that I've used for a zillion years
 * elsewhere originating on a SVR4 machine.  But hey, it works.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <paths.h>
#include <time.h>


char *wday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
char *mon[] =  { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

char *Prog;

static int
writestr(int fd, char *buf)
{
	return write(fd, buf, strlen(buf));
}

static void
usage(void)
{
	writestr(2, "Usage: ");
	writestr(2, Prog);
	writestr(2, " [ -s subject ] [ -r reply-to ] "
	    "[ -f from ] [ -f From: ]..\n");
	writestr(2, " [ -b bcc ] [ -c cc ] [-H] [-I/-B/-Q] "
	    "[-v] address [address]...\n");
	exit(1);
}

static char *
makerfc822date(time_t now)
{
	struct tm	*tm;
	static char	buf[1024];
	time_t		tzo;

	tm = localtime(&now);

	tzo = tm->tm_gmtoff;

	tzo = tzo / 60;		/* minutes */
	tzo = (tzo % 60) + (tzo / 60 * 100);

	snprintf(buf, sizeof(buf), "%s, %d %s %d %02d:%02d:%02d %+05ld (%s)", 
	    wday[tm->tm_wday], tm->tm_mday, mon[tm->tm_mon],
	    tm->tm_year + 1900, tm->tm_hour, tm->tm_min,
	    tm->tm_sec, tzo, tm->tm_zone);
	return buf;
}



int
main(int ac, char **av)
{
	int	c;
	int	i;
	pid_t	pid;
	int	pfd[2];
	char	*smvec[1024];
	char	**vec = smvec;
	char	buf[1024];
	char	Frombuf[256];	/* Long enough */
	char	frombuf[256];	/* Long enough */
	char	gecos[256];	/* Long enough */
	char	*s;

	char	*subj = NULL;
	char	*reply = NULL;
	char	*from = NULL;
	char	*From = NULL;
	char	*cc = NULL;
	char	*bcc = NULL;
	char	*delmode = NULL;
	char	*verbose = NULL;
	char	*hostname = NULL;
	int	headers = 0;

	struct passwd	*pw;

	Prog = av[0];

	while ((c = getopt(ac, av, "s:f:F:h:r:c:b:IBQHv")) != EOF) {
		switch (c) {

		case 's':	/* -s Subject: */
			if (subj)
				usage();
			subj = optarg;
			break;

		case 'f':	/* -f From_ */
			if (from)
				usage();
			from = optarg;
			break;

		case 'F':	/* -F From: */
			if (From)
				usage();
			From = optarg;
			break;

		case 'h':	/* -h hostname */
			if (hostname)
				usage();
			hostname = optarg;
			break;

		case 'H':	/* -H = headers coming in via stdin too */
			headers++;
			break;

		case 'r':	/* -r Reply-To: */
			if (reply)
				usage();
			reply = optarg;
			break;

		case 'b':	/* -b Bcc: */
			if (bcc)
				usage();
			bcc = optarg;
			break;

		case 'c':	/* -b cc: */
			if (cc)
				usage();
			cc = optarg;
			break;

		case 'I':	/* -I interactive delivery */
			delmode = "-odi";
			break;

		case 'B':	/* -B background delivery */
			delmode = "-odb";
			break;

		case 'Q':	/* -Q queue up only */
			delmode = "-odq";
			break;

		case 'v':
			verbose = "-v";
			break;

		default:
		case '?':	/* err */
			writestr(2, "Unknown switch: '");
			buf[0] = optopt;
			buf[1] = '\0';
			writestr(2, buf);
			writestr(2, "'\n");
			usage();
			break;
		}
	}
	ac -= optind;
	av += optind;
	if (ac < 1) {
		writestr(2, "you must supply an address!\n");
		usage();
	}

	if (hostname == NULL) {
		gethostname(buf, sizeof(buf));
		buf[sizeof(buf)-1] = '\0';		/* academic.. */
		hostname = buf;
	}
	Frombuf[0] = '\0';

	if (From) {
		/* From@hostname */
		snprintf(Frombuf, sizeof(Frombuf), "%s@%s", From, hostname);
		pw = getpwnam(From);
	} else {
		pw = getpwuid(getuid());
	}
	if (pw && hostname == buf) {
		if (pw->pw_gecos) {
			strncpy(gecos, pw->pw_gecos, sizeof(gecos) - 1);
			gecos[sizeof(gecos) - 1] = '\0';
			if ((s = strchr(gecos, ',')))
				*s = '\0';
			if ((s = strchr(gecos, ';')))
				*s = '\0';
			snprintf(Frombuf, sizeof(Frombuf), "%s <%s@%s>",
			    gecos, pw->pw_name, hostname);
		} else {
			/* From@hostname */
			snprintf(Frombuf, sizeof(Frombuf), "%s@%s",
			    pw->pw_name, hostname);
		}
	}
	endpwent();
	if (verbose) {
		writestr(2, "From: ");
		writestr(2, Frombuf);
		writestr(2, "\n");
	}

	*vec++ = "sendmail";
	*vec++ = "-oi";
	*vec++ = "-oem";

	if (delmode) {
		*vec++ = delmode;
	}

	if (verbose) {
		*vec++ = verbose;
	}

	if (from) {
		*vec++ = "-f";
		snprintf(frombuf, sizeof(frombuf), "%s@%s", from, hostname);
		*vec++ = frombuf;
	}

	for (i = 0; i < ac; i++)
		*vec++ = av[i];

	if (bcc)
		*vec++ = bcc;

	*vec++ = NULL;

	if (verbose) {
		writestr(1, "Executing:");
		vec = smvec;
		while (*vec) {
			writestr(1, " ");
			writestr(1, *vec);
			vec++;
		}
		writestr(1, "\n");
	}


	if (pipe(pfd) < 0) {
		perror("pipe");
		exit(1);
	}

	pid = fork();

	switch(pid) {

	case 0:			/* child */
		close(0);
		dup(pfd[0]);
		for (i = 3; i < 64; i++)
			close(i);
		execv(_PATH_SENDMAIL, smvec);
		perror(_PATH_SENDMAIL);
		_exit(1);
		break;

	case -1:		/* error */
		perror("fork");
		exit(1);
		break;

	default:		/* parent */
		close(pfd[0]);
		break;
	}

	if (Frombuf[0]) {
		writestr(pfd[1], "From: ");
		writestr(pfd[1], Frombuf);
		writestr(pfd[1], "\n");
	}
	writestr(pfd[1], "Date: ");
	writestr(pfd[1], makerfc822date(time(0)));
	writestr(pfd[1], "\n");

	if (subj) {
		writestr(pfd[1], "Subject: ");
		writestr(pfd[1], subj);
		writestr(pfd[1], "\n");
	}
	if (reply) {
		writestr(pfd[1], "Reply-To: ");
		writestr(pfd[1], reply);
		writestr(pfd[1], "\n");
	}
	if (cc) {
		writestr(pfd[1], "Cc: ");
		writestr(pfd[1], cc);
		writestr(pfd[1], "\n");
	}

	writestr(pfd[1], "To: ");
	writestr(pfd[1], av[0]);

	for (i = 1; i < ac; i++) {
		writestr(pfd[1], ", ");
		writestr(pfd[1], av[i]);
	}
	writestr(pfd[1], "\n");

	/* Headers from stdin */
	if (!headers)
		writestr(pfd[1], "\n");

	while ((c = read(0, buf, sizeof(buf))) > 0) {
		write(pfd[1], buf, c);
	}

	close(pfd[1]);

	alarm(600);		/* drop dead in 10 minutes */

	while (wait(NULL) > 0)
		;

	exit(0);
}

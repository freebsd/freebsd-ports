--- etc/autologin/autologin.c.orig	2000-08-02 11:39:42.000000000 -0700
+++ etc/autologin/autologin.c	2010-01-28 21:04:23.000000000 -0800
@@ -23,7 +23,15 @@
 #include <pwd.h>
 #include <grp.h>
 #include <errno.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+#include <utmpx.h>
+#define utmp utmpx
+#define setutent setutxent
+#define getutent getutxent
+#define endutent endutxent
+#else
 #include <utmp.h>
+#endif
 
 
 #include "machine.h"
@@ -189,7 +197,12 @@
 	(void)strncpy(utmp.ut_host, "(autologin)", sizeof(utmp.ut_host));
 #endif
 #endif
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+	utmp.ut_tv.tv_sec = time((time_t *) 0);
+	utmp.ut_tv.tv_usec = 0;
+#else
 	utmp.ut_time = time((time_t *) 0);
+#endif
 
 	if (0 == iFound) {
 		fprintf(stderr, "%s: %s: no ttyslot\n", progname, pctty);
@@ -443,11 +456,36 @@
 		/* NOTREACHED */
 	}
 #endif
+#ifdef __FreeBSD_version
+	/* XXX:	FreeBSD does not support IUCLC, translate uppercase characters
+		to lowercase */
+	n_tio.c_iflag &= ~(IGNCR);
+#else
 	n_tio.c_iflag &= ~(IGNCR|IUCLC);
+#endif
 	n_tio.c_iflag |= ICRNL|IXON|IXANY;
+#ifdef __FreeBSD_version
+	/*
+	   XXX: FreeBSD does not support OLCUC, translater lowercase
+		to uppercase
+	   XXX:	FreeBSD does not support OFILL, use fill (padding) characters
+		instead of timing for delays
+	   XXX:	FreeBSD does not support NLDLY, newline delay (nlN)
+	   XXX:	FreeBSD does not support CRDLY, carrier return delay (crN)
+	   XXX:	FreeBSD does not support BSDLY, backspace dealy (bsN)
+	*/
+	n_tio.c_oflag &= ~(ONOCR|ONLRET|TABDLY);
+#else
 	n_tio.c_oflag &= ~(OLCUC|ONOCR|ONLRET|OFILL|NLDLY|CRDLY|TABDLY|BSDLY);
+#endif
 	n_tio.c_oflag |= OPOST|ONLCR|TAB3;
+#ifdef __FreeBSD_version
+	/* XXX:	FreeBSD does not support XCASE, with icanon, escape with '\'
+		for uppercase characters */
+	n_tio.c_lflag &= ~(NOFLSH|ECHOK|ECHONL);
+#else
 	n_tio.c_lflag &= ~(XCASE|NOFLSH|ECHOK|ECHONL);
+#endif
 	n_tio.c_lflag |= ISIG|ICANON|ECHO;
 	n_tio.c_cc[VEOF] = '\004';		/* ^D	*/
 	n_tio.c_cc[VEOL] = '\000';		/* EOL	*/

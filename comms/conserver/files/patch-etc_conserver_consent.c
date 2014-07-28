--- etc/conserver/consent.c.orig	Wed Nov 17 18:10:14 1999
+++ etc/conserver/consent.c	Wed Nov 17 18:12:57 1999
@@ -295,7 +295,7 @@
 	 */
 	termp.c_iflag = IXON|IXOFF|BRKINT;
 	termp.c_oflag = 0;
-	termp.c_cflag = CREAD;
+	termp.c_cflag = CREAD | (termp.c_cflag & (CLOCAL|CRTSCTS));
 	termp.c_cflag |= pCE->pparity->iset;
 	termp.c_lflag = 0;
 	/*
@@ -303,7 +303,7 @@
 	 * Set the VTIME == 1 (0.1 sec)
 	 * Don't bother with the control characters as they are not used
 	 */
-	termp.c_cc[VMIN] = 128;
+	termp.c_cc[VMIN] = 1;
 	termp.c_cc[VTIME] = 1;
 
 	if (-1 == cfsetospeed(&termp,pCE->pbaud->irate)) {
@@ -563,11 +563,10 @@
 		exit(1);
 	}
 #endif
-	n_tios.c_iflag &= ~(IGNCR|IUCLC);
+	n_tios.c_iflag &= ~(IGNCR);
 	n_tios.c_iflag |= ICRNL|IXON|IXANY;
-	n_tios.c_oflag &= ~(OLCUC|ONOCR|ONLRET|OFILL|NLDLY|CRDLY|TABDLY|BSDLY);
 	n_tios.c_oflag |= OPOST|ONLCR;
-	n_tios.c_lflag &= ~(XCASE|NOFLSH|ECHOK|ECHONL);
+	n_tios.c_lflag &= ~(NOFLSH|ECHOK|ECHONL);
 	n_tios.c_lflag |= ISIG|ICANON|ECHO;
 	n_tios.c_cc[VEOF] = '\004';
 	n_tios.c_cc[VEOL] = '\000';
